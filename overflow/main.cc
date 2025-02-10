#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <chrono>  // 用于时间测量

using namespace std;
using namespace std::chrono;

// 将__int128转换为字符串
std::string int128_to_string(__int128_t value) {
    if (value == 0) {
        return "0";
    }

    bool is_negative = false;
    if (value < 0) {
        is_negative = true;
        value = -value;
    }

    std::string str;
    while (value > 0) {
        str.push_back('0' + static_cast<char>(value % 10));
        value /= 10;
    }

    if (is_negative) {
        str.push_back('-');
    }

    std::reverse(str.begin(), str.end());
    return str.empty() ? "0" : str;
}

// 编译时计算10^exponent
constexpr __int128_t pow10(uint32_t exponent) {
    __int128_t result = 1;
    for (uint32_t i = 0; i < exponent; ++i) {
        result *= 10;
    }
    return result;
}

template<uint32_t Scale>
class Int128Decimal {
    static_assert(Scale < 38, "Scale must be less than 38");

public:
    using value_type = __int128_t;
    constexpr static uint32_t precision_value = 38;
    constexpr static uint32_t scale_value = Scale;
    constexpr static __int128_t radix = pow10(Scale);
    constexpr static __int128_t half_radix = radix / 2;

private:
    __int128_t value_;

public:
    explicit Int128Decimal(__int128_t value) : value_(value) {}
    explicit Int128Decimal(double value) : value_(static_cast<__int128_t>(std::round(value * radix))) {}

    __int128_t getValue() const { return value_; }

    static __int128_t getBase(__int128_t value) { return value / radix; }
    static __int128_t getFrac(__int128_t value) { 
        __int128_t frac = value % radix;
        // 处理负数的余数问题
        if (frac < 0) {
            frac += radix;
        }
        return frac;
    }

    static __int128_t mergeDecimalPair(__int128_t base, __int128_t frac) {
        return base * radix + frac;
    }

    // 重载加法运算符
    Int128Decimal operator+(const Int128Decimal& other) const {
        return Int128Decimal(value_ + other.value_);
    }


    // 第一种：没有溢出检查的普通加法
    Int128Decimal add_no_overflow(const Int128Decimal& other) const {
        return Int128Decimal(value_ + other.value_);
    }

    // 第二种：使用内建溢出检查的加法
    Int128Decimal add_with_overflow(const Int128Decimal& other) const {
        __int128_t result;
        bool overflow = __builtin_add_overflow(value_, other.value_, &result);
        if (overflow) {
            throw std::overflow_error("Overflow occurred in add_with_overflow");
        }
        return Int128Decimal(result);
    }

    // 第三种：检查符号位的加法
    Int128Decimal add_with_sign_check(const Int128Decimal& other) const {
        __int128_t result = value_ + other.value_;
        if (((value_ > 0) && (other.value_ > 0) && (result < 0)) || 
            ((value_ < 0) && (other.value_ < 0) && (result > 0))) {
            throw std::overflow_error("Overflow occurred in add_with_sign_check");
        }
        return Int128Decimal(result);
    }
    // 第三种：检查 XOR 加法溢出
    Int128Decimal add_with_xor_check(const Int128Decimal& other) const {
        __int128_t result = value_ + other.value_;

        // 检查溢出：x ^ r 和 y ^ r 的符号位不同表示溢出
        if (((value_ ^ result) & (other.value_ ^ result)) < 0) {
            throw std::overflow_error("Overflow occurred in add_with_xor_check");
        }

        return Int128Decimal(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const Int128Decimal& dec) {
        __int128_t value = dec.value_;
        bool is_negative = false;
        if (value < 0) {
            is_negative = true;
            value = -value;
        }

        __int128_t base = value / radix;
        __int128_t frac = value % radix;

        if (is_negative) {
            os << '-';
        }

        os << int128_to_string(base);

        if constexpr (Scale > 0) {
            os << '.';
            std::string frac_str = int128_to_string(frac);
            if (frac_str.length() < Scale) {
                frac_str = std::string(Scale - frac_str.length(), '0') + frac_str;
            }
            os << frac_str;
        }

        return os;
    }
};

// 测试加法运算的性能
template<uint32_t Scale>
void test_addition_performance(int iterations) {
    Int128Decimal<Scale> dec1(static_cast<__int128_t>(12345));  // 123.45
    Int128Decimal<Scale> dec2(static_cast<__int128_t>(67890));  // 678.90

    // 获取当前时间
    auto start = high_resolution_clock::now();

    // 执行加法运算
    Int128Decimal<Scale> result = dec1;
    for (int i = 0; i < iterations; ++i) {
        // result = result.add_no_overflow(dec2);//2.03s
        // result = result.add_with_overflow(dec2);//2.7s
        result = result.add_with_sign_check(dec2);//2.2s
        // result = result.add_with_xor_check(dec2);//2.7s
    }

    // 获取结束时间
    auto end = high_resolution_clock::now();
    
    // 计算持续时间
    auto duration = duration_cast<microseconds>(end - start);
    
    // 打印结果，根据时间长短选择合适的单位
    if (duration.count() >= 1000000) {
        // 超过1秒，输出秒
        cout << "Total time for " << iterations/10000 << "W iterations: " 
             << duration.count() / 1000000.0 << " seconds." << endl;
    } else if (duration.count() >= 1000) {
        // 超过1毫秒，输出毫秒
        cout << "Total time for " << iterations << " iterations: " 
             << duration.count() / 1000.0 << " milliseconds." << endl;
    } else {
        // 否则，输出微秒
        cout << "Total time for " << iterations << " iterations: " 
             << duration.count() << " microseconds." << endl;
    }
}
int main() {
    Int128Decimal<2> dec1(static_cast<__int128_t>(12345)); // 表示123.45
    cout << dec1 << endl;         // 输出: 123.45

    Int128Decimal<3> dec2(static_cast<__int128_t>(-1234567)); // 表示-1234.567
    cout << dec2 << endl;            // 输出: -1234.567

    Int128Decimal<2> dec3(12.345);   // 四舍五入到12.35
    cout << dec3 << endl;            // 输出: 12.35

    // 执行性能测试：进行100000000次加法运算并打印执行时间
    test_addition_performance<2>(100000000);

    return 0;
}

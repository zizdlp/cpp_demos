
#include <iostream>

// 定义一个简单的函数模板
template <typename T>
T add(T a, T b) {
    return a + b;
}

// 部分特化：特化模板以适应特定类型
template <>
float add<float>(float a, float b) {
    std::cout << "Using specialized float version." << std::endl;
    return a + b;
}

int main() {
    int intResult = add(2, 3);       // 实例化int版本的add函数模板
    float floatResult = add(1.1, 2.2); // 实例化float版本的add函数模板，触发部分特化

    std::cout << "intResult: " << intResult << std::endl;
    std::cout << "floatResult: " << floatResult << std::endl;

    return 0;
}

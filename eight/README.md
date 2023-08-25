# 八股文

1. explicit 关键字

**explicit** 防止隐式类型转换,典型场景：构造函数。


```cpp
class MyClass {
public:
    explicit MyClass(int value) {
        this->value = value;
    }

    int getValue() {
        return value;
    }
private:
    int value;
};

int main() {
    MyClass obj1 = 42;  // 这里会导致编译错误，因为构造函数被声明为 explicit
    MyClass obj2(42);   // 这里是正确的，使用了显式构造函数调用
    int x = obj2.getValue(); // 正常调用成员函数

    return 0;
}
```






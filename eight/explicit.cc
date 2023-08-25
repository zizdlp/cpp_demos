#include <iostream>

class MyClass {
public:
    // explicit MyClass(int value) { // add explicit 关键字
    MyClass(int value) { 
        this->value = value;
    }

    int getValue() {
        return value;
    }

private:
    int value;
};

// 但现在，假设有一个函数接受 MyClass 对象作为参数
void func(MyClass obj) {
    int val = obj.getValue();
    std::cout << val << std::endl;
}

int main() {
    MyClass obj1 = 42;  // 没有使用 explicit，会隐式调用构造函数
    int x = obj1.getValue();
    std::cout << x << std::endl; // 输出 42，似乎一切正常

    func(42);  // 这里会隐式转换为 MyClass 对象，输出不是期望的结果

    return 0;
}

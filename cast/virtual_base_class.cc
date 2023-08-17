#include <iostream>

class A {
public:
    int value;
    A() : value(10) {}
    void showValue() {
        std::cout << "Value from A: " << value << std::endl;
    }
};  

class B : public A {
public:
    B() { value = 20; }
};

class C : public A {
public:
    C() { value = 30; }
};

class D : public B, public C {
public:
    D() {}
};

class VB : public virtual A {
public:
    VB() { value = 20; }
};

class VC : public virtual A {
public:
    VC() { value = 30; }
};

class VD : public VB, public VC {
public:
    VD() {}
};


void test_vd(){
    VD vd;
    vd.showValue(); // 这一行不会导致编译错误，引入虚基类解决 showValue 二义性
    vd.VB::showValue(); // 通过指定基类可以解决二义性问题
    vd.VC::showValue();
}


int main() {
    D d;
    // d.showValue(); // 这一行会导致编译错误，因为 showValue 二义性
    d.B::showValue(); // 通过指定基类可以解决二义性问题
    d.C::showValue();
    test_vd(); // 通过引入虚基类，避免二义性
    return 0;
}

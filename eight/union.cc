/**
 *  union: 联合（union）是一种节省空间的特殊的类:
 * 1. 可以有多个数据成员，但是同一时间只有一个数据成员有值
 * 2. 赋值某个成员，导致其他成员变为未定义
 * 3. 默认public
 * 
 * 当某个成员被赋值后其他成员变为未定义状态。联合有如下特点：
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/


#include<iostream>

union UnionTest {
    UnionTest() : i(10) {};
    int i;
    double d;
};

static union {
    int i;
    double d;
};

int main() {
    UnionTest u;

    union {
        int i;
        double d;
    };

    std::cout << u.i << std::endl;  // 输出 UnionTest 联合的 10

    ::i = 20;
    std::cout << ::i << std::endl;  // 输出全局静态匿名联合的 20

    i = 30;
    std::cout << i << std::endl;    // 输出局部匿名联合的 30

    return 0;
}
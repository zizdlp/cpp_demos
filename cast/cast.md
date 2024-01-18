# cast in c++

> **背景：** 有个需要将const string& cast 到 const int [] 的场景 总是报错，这里汇总下各种cast

## 四种基础cast

### reinterpret_cast

顾名思义，通过重新解释底层位模式在类型之间进行转换。reinterpret_cast是最强的cast，它纯粹是一个编译时指令，指示编译器将expression视为具有new-type 类型，不进行类型检查，因此是类型不安全的（仅在你确切知道可以用这个，才使用这个）

- 用于转换一种指针类型到另一种指针类型 `int* cast2 char*`
- 指针cast2整数类型（要求整数类型的内存能够容纳指针）`char* to long long int`
- 整数或者枚举cast2指针类型 `int cast2 char*`
- 不能改变const性质

### static_cast

用于替代隐式转换，用户自定义转换，比如 `int cast2 double`，`double cast2 int`

### dynamic_cast

运行时确定，用于子类父类之间cast,（常见用于多态）

### const_cast

添加、移除constness、volatility;
cast2 指针、引用。

## 智能指针cast



```mermaid

```


### 虚函数表

每个类一个表： 每个含有虚函数的类都有自己的虚函数表，虚函数表的内容是与类的具体定义相关的。派生类会继承基类的虚函数表，并根据需要修改其中的函数指针来实现覆盖。
- 存储在内存中： 虚函数表是一个类的静态数据成员，它在类的对象中不会被复制。每个类只有一个虚函数表，不管创建了多少个对象。
- 运行时确定 （编译时只知道左边声明的类型：`A a= b;`，运行时才能根据b实际类型确定a。
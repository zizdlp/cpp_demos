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

#include <iostream>

using namespace std;

struct V {
  virtual void f() {}  // must be polymorphic to use runtime-checked dynamic_cast
};
struct A : virtual V {};
struct D : A {};
void test_dynamic_cast() {
  D d;
  A& a = d;                                         // upcast, dynamic_cast may be used, but unnecessary
  [[maybe_unused]] D& new_d = dynamic_cast<D&>(a);  // downcast,必须是多态的
}
void test_reinterpret_cast() {
  // 指针 cast2 指针
  int* vaule_int_pointer = new int(5);
  [[maybe_unused]] auto value_char_pointer = reinterpret_cast<char*>(vaule_int_pointer);

  // 指针 cast2 整数类型
  double* value_double_pointer = new double(5);
  [[maybe_unused]] auto result_double = reinterpret_cast<long long int>(value_double_pointer);

  // 整数 cast2 指针类型
  int value_int = 1;
  [[maybe_unused]] auto result_char_pointer = reinterpret_cast<char*>(value_int);

  // const char* cast2 const int*;//本意是cast const string & to const int[];
  const std::string value_const_int = "abc";
  [[maybe_unused]] auto result_const_int_arr = reinterpret_cast<const int*>(value_const_int.c_str());
}

void test_static_cast() {
  [[maybe_unused]] int n = static_cast<int>(3.14);           // double to int;
  [[maybe_unused]] double value_d = static_cast<double>(5);  // int to double;
}

void test_const_cast() {
  const int value_int = 4;
  const int* value_int_pointer = new int(5);
  [[maybe_unused]] auto result_int = const_cast<int&>(value_int);                           // const int to int&;
  [[maybe_unused]] auto result_int_pointer = const_cast<int*>(value_int_pointer);           // const int* to int*;
  [[maybe_unused]] auto result_c_int = const_cast<const int&>(result_int);                  // int& to const int&
  [[maybe_unused]] auto result_c_int_pointer = const_cast<const int*>(result_int_pointer);  // int* to const int*
}

int main() {
  test_dynamic_cast();
  test_reinterpret_cast();
  test_static_cast();
  test_const_cast();
}
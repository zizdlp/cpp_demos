#include <iostream>
#include <cassert>
#include <chrono>
#include "NumberArr.h"

uint64_t GetTimeStamp() {  // 直接调用此函数就可以返回时间戳了
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void TestNumberArr() {
  std::cout << "_________ TestNumberArr Start ___________ \n";
  auto arr = NumberArr<int>(5);
  arr.print_value();
  arr.set_value(32);
  arr.print_value();
  int left,right,res;
  mul(left,right,res);
  mulX(left,right,res);
  std::cout << "_________ TestNumberArr Done ___________ \n";
}
int main() {
  TestNumberArr();
}
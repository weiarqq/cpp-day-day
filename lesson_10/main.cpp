#include <iostream>
using namespace std;

/*
this指针
1. 解决命名冲突
2. this就表示 获取这个对象本身


常量成员函数

*/
class Hero {
private:
  string name;
  mutable int hpCounter;

public:
  Hero() : name("weah"), hpCounter(0) {}
  string getName() {
    this->name = "weah";
    return this->name;
  }
  string setName() const{
    // this->name = "weah"; 常量成员函数不能修复成员变量
    hpCounter++; // mutable 修饰变量可以在常函数中进行修改
  }
};

int main() { return 0; }
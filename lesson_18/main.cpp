// 纯虚函数和抽象类

#include <iostream>
using namespace std;

class Animal {
public:
  virtual void
  eat() = 0; // 设置 =0 则为纯虚函数, 此时继承的话 子类必须重写，不重写的话
             // 子类也会成为抽象类,
             // 包含纯虚函数的类，称为抽象类，抽象类不能实例化，必须被继承；
  void dink() {}
};

class Cat : public Animal {
public:
  string name;
  void eat() { cout << "猫吃东西" << endl; }
};

int main() {
  Cat cat;
  cat.eat();

  return 0;
}
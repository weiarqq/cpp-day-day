// 继承

/*
继承方式

class 子类名： 继承方式 父类名 {};

公共 public
保护 protected
私有 private

子类访问父类成员的权限会因为继承方式而改变
继承方式\父类成员访问权限               public      protected   private
public                              public      protected   无法访问
protected                           protected   protected   无法访问
private                             private     private     无法访问


继承中的父类子类构造函数和析构函数顺序
构造链中，先构造的后析构，先构造父类再构造子类


同名属性访问
子类和父类有同名属性的情况，访问父类同名属性使用 子类对象.父类名::属性名

*/
#include <iostream>
using namespace std;

class Animal {
public:
  Animal() { cout << "父类构造函数" << endl; }
  void eat() { cout << this->name << "吃" << endl; }

  void drink() { cout << this->name << "喝" << endl; }
  string name;

  ~Animal() { cout << "父类析构函数" << endl; }
};

class Dog : public Animal {
public:
  Dog() {
    name = "狗";
    cout << "子类 狗 构造函数" << endl;
  }
  string name;
  ~Dog() { cout << "子类 狗 析构函数" << endl; }
  void eat() { cout << this->name << "吃" << endl; }
};

class Cat : public Animal {
public:
  Cat() {
    name = "猫";

    cout << "子类 猫 构造函数" << endl;
  }
  string name;
  void eat() { cout << this->name << "吃" << endl; }
  ~Cat() { cout << "子类 猫 析构函数" << endl; }
};

int main() {
  Dog dog;
  Cat cat;
  cout << cat.Animal::name << endl; //访问父类同名属性
  dog.eat();
  dog.Animal::eat(); // 访问父类同名函数
  cat.drink();
  return 0;
}
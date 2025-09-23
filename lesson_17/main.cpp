// 多态
#include <iostream>
using namespace std;

class Animal {
  public:
    virtual void eat() { cout << "动物吃东西" << endl; }
};

class Cat : public Animal {
  public:
    void eat() { cout << "猫吃东西" << endl; }
};

class Dog : public Animal {
  public:
    void eat() { cout << "狗在吃东西" << endl; }
};

void test1(Animal& a) {
    // 由于形参为Animal则会直接父类的函数，如果需要使用实参的函数，则需要在父类中改为虚函数；
    a.eat();
}
void test2() {
    Cat cat;
    test1(cat);
}
int main() {
    test2();
    Animal* a = new Cat();
    a->eat(); // 此时为多态，执行子类函数， 如果父类函数不添加
              // virtual,则也会直接父类函数
    delete a;
    Cat cat;
    cat.Animal::eat();

    return 0;
}
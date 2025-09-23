// 运算符重载

#include <iostream>
#include <ostream>
using namespace std;

class Complex {
  friend Complex operator-(Complex &a, Complex &b);
  friend Complex &operator++(Complex &a);
  friend ostream &operator<<(ostream &cout, const Complex &a);

private:
  int real;
  int image;

public:
  Complex() : real(0), image(0) {}
  Complex(int real, int image) {
    this->real = real;
    this->image = image;
  }
  Complex operator+(Complex &other) {
    Complex c;
    c.real = other.real;
    c.image = other.image;
    return c;
  }
  Complex &operator++() { //前置++ ++a
    this->real += 1;
    return *this;
  }

  Complex operator++(int) { //后置++ a++       函数创建对象
                            //不要返回引用，因为函数内成员会被释放
    Complex c = *this;
    this->real += 1;
    return c;
  }
  void Print() { cout << this->real << "+" << this->image << "i" << endl; }
};

Complex operator-(Complex &a, Complex &b) {
  Complex c;
  c.real = a.real - b.real;
  c.image = a.image - b.image;
  return c;
}

Complex &operator++(Complex &a) {
  a.real += 1;
  return a;
}

ostream &operator<<(ostream &cout,
                    const Complex &a) { // const   cout << c++ << endl报错;
                                        // 非常量引用不能作为函数返回值
  cout << a.real << "+" << a.image << "i" << endl;
  return cout;
}

class A {};

A func1() { return A(); }

void func2(const A &a) {} //const可以

int main() {
  Complex ta(10, 10);
  Complex tb(20, 15);
  Complex c = ta + tb;
  c.Print();
  Complex d = ta - tb;
  d.Print();
  cout << c << endl;
  cout << c++ << endl;

  func2(func1()); // 非常量引用的初始值必须为左值，func1的返回值不是左指，如果是非常量引用，函数执行完后，内部成员会被释放

  return 0;
}
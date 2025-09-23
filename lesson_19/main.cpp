// 虚析构函数和纯虚析构函数
#include <iostream>
using namespace std;

class BaseA {
public:
  BaseA() {}
  //   ~BaseA() { cout << "父类析构函数执行" << endl; }
  //   virtual ~BaseA() { cout << "父类析构函数执行" << endl; } //
  //   虚析构函数，此时多态时，释放内存时会执行子类和父类的虚构函数
  virtual ~BaseA() = 0; // 纯虚析构函数，此时BaseA变为抽象类, 并且需要在类外实现
};

BaseA::~BaseA() { cout << "父类纯虚析构函数执行" << endl; }

class BaseB : public BaseA {
public:
  BaseB() {}
  ~BaseB() { cout << "子类析构函数执行" << endl; }
};

int main() {
  //   BaseA *a = new BaseB();
  //   delete a;
  BaseB b;
  return 0;
}
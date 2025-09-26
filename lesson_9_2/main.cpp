#include <iostream>
using namespace std;

class Base final {
  public:
    Base() { cout << "禁止被继承" << endl; }
};

class Parent {
  public:
    virtual int add() { return 1; };
    virtual int mult() final {
        cout << "禁止被重写" << endl;
        return 1;
    };
};

class Son : public Parent {
  public:
    int add() override { return 2; };
    // int mult() override {}; 错误 禁止被重写
};

int main() {
    Son son;
    son.mult();
}
// 函数调用运算符的重载
#include <iostream>
using namespace std;

class AddFunction {
public:
  AddFunction() : count(0) {}
  int operator()(int a, int b) {
    count++; // 可以用来记录状态
    return a + b + count;
  }

private:
  int count;
};

int main() {
  AddFunction add;
  cout << add(5, 6) << endl;
  cout << add(5, 6) << endl;
  cout << add(5, 6) << endl;
  cout << add(5, 6) << endl;
}
#include <iostream>
using namespace std;

/*
引用： 给变量取一个别名，本质是一个指针常量 int& a 等价于 int* const a
 数据类型& 变量名 = 变量；
 引用必须初始化，且初始化后不可更改引用 int& a;错误
in t



*& 指针引用 形式参数传递

*/

int &getArrayValue(int arr[], int index) {
  return arr[index]; // 返回的是引用
}

void printS(const int &a) {
  // a = 10; 错误，常量引用不可修改
  cout << a << endl;
}

int main() {
  // 引用和指针 写法对比
  int a = 10;
  int &b = a;
  b = 20;
  cout << a << " " << b << endl;

  int aa = 10;
  int *bb = &aa;
  *bb = 20;
  cout << aa << " " << *bb << endl;

  // 引用作为函数返回值
  int arr[] = {1, 2, 3, 4, 5};
  getArrayValue(arr, 2) = 10; // 将a[2]
  cout << arr[2] << endl;

  //常量引用
  int a2;
  const int &b2 = a2; //常量引用，引用的值不可变
  // 常量引用 = 常量指针常量

  return 0;
}
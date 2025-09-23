#include <iostream>
using namespace std;

// 代码区 全局区 堆区 栈区
/*
代码区： 存放函数的二进制代码

全局区： 全局变量、静态变量、常量

堆区： new/malloc 分配的内存, 程序决定生命周期
// malloc   free C 申请和释放内存
// new      delete C++ 申请和释放内存

栈区： 函数的参数值、局部变量, 操作系统决定生命周期

*/

int *getV(int c) {
  int *a = new int(c); // int* a 是一个栈上的变量
  cout << a << endl; // *a 也就是a解引用以后得到的值，是存储在堆上面的
  return a; // 函数返回的时候，虽然栈上的变量a被操作系统释放了，但是a指向的内存还是存在的
}

int g_a = 1;
int g_b = 2;
const int g_c = 3;  // 常量区
static int g_d = 4; // 静态区

int *getGapList(int *arr, int size) {
  int *parr = new int[size - 1];
  for (int i = 0; i < size - 1; i++) {
    parr[i] = arr[i + 1] - arr[i];
  }
  return parr;
}

int main() {
  int a = 5;
  int b = 6;

  cout << "全局变量地址:" << &g_a << " " << &g_b << " " << &g_c << " " << &g_d
       << endl; // 0x10ac640c0 0x10ac640c4 0x10ac5ff5c 0x10ac640c8
  cout << "局部变量地址:" << &a << " " << &b
       << endl;                            // 0x7ff7b52a2728 0x7ff7b52a2724
  cout << "常量地址:" << &g_c << endl;     // 0x10ac5ff5c
  cout << "静态变量地址:" << &g_d << endl; // 0x10ac640c8

  int *p = getV(10);
  cout << *p << endl;
  cout << p << endl;

  int *ptr = new int(20); // 申请了一个int类型的内存，值为20
  *ptr = 520;
  cout << *ptr << endl;

  delete ptr; // 释放内存
  ptr = NULL; // 避免野指针

  char arr[3] = {'a', 'b', 'c'};
  cout
      << (void *)arr
      << endl; // void*（无类型指针）是一种特殊的指针类型，它可以指向任何数据类型的内存地址，但不包含关于所指向数据的类型信息。

  int arr1[5] = {1, 2, 4, 7, 11};
  int *parr1 = getGapList(arr1, 5);
  for (int i = 0; i < 4; i++) {
    cout << parr1[i] << " ";
  }
  delete[] parr1;
  parr1 = NULL;

  return 0;
}
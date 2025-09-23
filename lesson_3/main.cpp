// 数组指针
#include <iostream>
using namespace std;

int main() {
  int t = 0;
  char s[5] = {'0', '1', '2', '3', '4'};
  cout << '6' << s + 3
       << endl; //指针偏移 当使用 s + 6 时，数组名 s 会隐式转换为指针
                // s[0]的指针，s + 6 则表示指向 s[6] 的指针（即从第
                // 7个元素开始的子串）， cout返回的是对应位置的子串
  //   int *p = new int[10];
  int a[5] = {1, 2, 3, 4, 5};
  char c[6] = "01234"; // 等价于 char a[6] ={'0', '1', '2', '3', '4', '\0'}
  //   字符数组要以'\0'结尾，5个字符 占用6个空间
  cout << a + 3 << endl;
  int *pa = a;
  // 获取对应位置的 三种方式
  cout << *(pa + 1) << endl;
  cout << pa[1] << endl;
  cout << a[1] << endl;

  cout << pa + 1 << endl;
  cout << a + 1 << endl;

  //   delete[] p;

  return 0;
}
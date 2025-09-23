// 联合体
#include <iostream>
using namespace std;

// 定义一个联合体, 其成员共享同一块内存
union DataU {
  int i;
  float f;
  char str[20];
};

struct Info{
    char _name[20];
    int _role; // 0学生 1老师， 当为学生时，score有效，当为老师时，course有效，节省内存
    union {
        int score;
        char course[20];
    } _sc;
};

int main() {
  DataU data;
  data.i = 10;
  cout << "data.i: " << &data.i << endl;
  data.f = 220.5;
  cout << "data.f: " << &data.f << endl;
  data.str[0] = 'a';
  cout << "data.str: " << &data.str << endl;
  cout << "data.i: " << data.i << endl;

  return 0;
}
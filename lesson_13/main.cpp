// 内存泄漏 赋值表达式重载
#include <iostream>
using namespace std;

class Hero {
public:
  Hero() : m_Data(NULL) {}
  Hero(int data) {
    m_Data = new int; // new int返回的是指向该内存的指针
    *m_Data = data;
  }
  ~Hero() {
    if (m_Data) {    // if(指针)判断的指针是否为空指针
      delete m_Data; //删除m_Data指向地址的内存
      m_Data = NULL;
    }
  }

  Hero &operator=(Hero &a) {
    if (m_Data) {
      delete m_Data;
      m_Data = NULL;
    }
    m_Data = new int;
    *m_Data = *a.m_Data;
    // m_Data = a.m_Data; //错误 此处我们需要复制的是m_Data所指向的值，而不是地址，不然还是会存在内存泄漏问题
    return *this;
  }

  int *m_Data;
};

int main() {
  Hero hero1(1);
  Hero hero2(2);
  Hero hero3(3);
  hero2 = hero1; // 内存泄漏， 这种情况下，hero1.m_Data原始指向的地址将访问不到
  cout << hero1.m_Data << " " << hero2.m_Data
       << endl; //由于m_Data为指针，指向地址相同
  hero3 = (hero2 = hero1);
  cout << *hero1.m_Data << " " << *hero2.m_Data << " " << *hero3.m_Data << endl;

  return 0;
}
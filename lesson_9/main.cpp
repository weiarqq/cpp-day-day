#include <iostream>
using namespace std;

/*
静态成员变量的特点：
1. 所有的对象共享同一份数据
2. 编译阶段分配内存
3. 需要在类中进行声明，在类外进行初始化


静态成员函数：
1. 所有对象共享函数
2. 静态成员函数只能使用静态成员变量，无法使用普通成员变量

*/





class Hero {
private:
  string m_Name;
  int m_Hp;

public:
  Hero() : m_Name("剑圣"), m_Hp(100) {}
  ~Hero() {}
  static int m_HeroCount; //静态变量 全局共享

  static int GetHeroCount(){ //静态成员函数 全局共享
    return m_HeroCount;
  }
};

int Hero::m_HeroCount = 100;

int main() {
  Hero h;
  cout << h.m_HeroCount << endl;
  h.m_HeroCount = 101;
  cout << Hero::m_HeroCount << endl;
  cout << &(h.m_HeroCount) << " " << &(Hero::m_HeroCount) << endl;
  cout << Hero::GetHeroCount() << endl;

  return 0;
}
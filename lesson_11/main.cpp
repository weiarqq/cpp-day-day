#include <iostream>
#include <string>
using namespace std;

/*
友元的目的
放一个类 或者函数能够访问另一个类型的私有成员

友元的关键字: friend
三种友元
1. 全局函数作为友元
2. 类作为友元
3. 成员函数作为友元
*/
class Friend;
class People;
class Custom {
private:
  string name;

public:
  string visitPeople(People &p);
};

class People {
  friend string getName(People &p);             //全局函数作为友元
  friend class Friend;                          //类作为友元
  friend string Custom::visitPeople(People &p); // 成员函数作为友元

private:
  string name;

public:
  int age;
  People() : name("wangqi"), age(18) {}
};

class Friend {
private:
  string name;

public:
  string visitFriend(People *p);
};

string Friend::visitFriend(People *p) {
  cout << p->name << endl;

  return p->name;
}

string Custom::visitPeople(People &p) {
  cout << p.name << endl;
  return p.name;
}

string getName(People &p) {
  cout << p.age << endl;
  cout << p.name << endl;
  return p.name;
}

int main() {

  People p;
  string name = getName(p);
  Friend f;
  f.visitFriend(&p);
  Custom c;
  c.visitPeople(p);
}
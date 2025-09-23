// 结构体
#include <iostream>
#include <string>
using namespace std;

struct Author {
  string name;
  int age;
};

struct Book {
  string name;
  double price;
  int value;
  Author author;
};

int main() {
  Book b1 = {"C++", 99.9, 10};
  Book b2;
  b2.name = "Java";
  b2.price = 88.8;
  b2.value = 20;
  cout << b1.name << " " << b1.price << " " << b1.value << endl;
  // 结构体数组
  Book books[2] = {{"C++", 99.9, 10}, {"Java", 88.8, 20}};
  // 结构体指针
  Book go = {"Go", 77.7, 30};
  Book *p = &go;
  p->name = "Golang";
  cout << go.name << endl;

  Author a = {"wangqi", 18};
  Book b = {"C++", 99.9, 10, a};
  cout << b.author.name << " " << b.author.age << endl;

  return 0;
}
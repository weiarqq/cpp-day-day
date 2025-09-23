#include <iostream>
#include <vector>
using namespace std;

/*
类模板
template <class T>         class替换为typename也可
class 类名{
};

类模板实例化时，必须显示指定类型

创建时机
类模板的成员函数，在调用时才会生成；

*/

// 类内实现
template <class T> class DynamicArray {
private:
  T *elements;
  int size;

public:
  DynamicArray() : size(100) { elements = new T[size]; }
  DynamicArray(int size) { elements = new T[size]; }

  ~DynamicArray() { delete[] elements; }

  T &operator[](int index) { return elements[index]; }

  void update(int index, T value) { elements[index] = value; }
};

//类外实现
template <class T> class DynamicArrayN {
private:
  T *elements;
  int size;

public:
  DynamicArrayN(int n);
  ~DynamicArrayN();
  T &operator[](int index);
  void update(int index, T value);
};
template <class T> DynamicArrayN<T>::DynamicArrayN(int n) : size(n) {
  elements = new T[n];
}

template <class T> DynamicArrayN<T>::~DynamicArrayN<T>() { delete[] elements; }

template <class T> T &DynamicArrayN<T>::operator[](int index) {
  return elements[index];
}

template <class T> void DynamicArrayN<T>::update(int index, T value) {
  elements[index] = value;
}

//类模板实例化的对象作为入参时
template <class Value1, class Value2> class TempClass {
private:
  Value1 value1;
  Value2 value2;

public:
  TempClass(Value1 value1, Value2 value2) {
    this->value1 = value1;
    this->value2 = value2;
  }
};
//当需要把TempClass作为函数参数类型时，有如下三种方法实现

//直接指定类型
void test1(TempClass<string, int> &t) {}

// 参数模板化
template <typename Value1, typename Value2>
void test2(TempClass<Value1, Value2> &t) {}

// 类模版化
template <typename T> void test3(T &t) {}

template <class T1, class T2, class T3>
class TempClassLow : public TempClass<T1, T2> {
  T3 t3;
};

int main() {
  int n = 10;
  int a[n];            // 标准C++中是 不允许的
  int *p = new int[n]; //可以使用这种方式

  DynamicArrayN<double> array(100); // 必须显示指定 比如vector<int>
  array[10] = 10.1;
  array.update(9, 9.01);
  cout << array[10] << " " << array[9] << endl;

  TempClass<string, int> tc("wangqi", 30);
  test1(tc);
  test2(tc);
  test3(tc);
  return 0;
}
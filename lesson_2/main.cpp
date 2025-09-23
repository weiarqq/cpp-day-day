// 指针
#include <cstdio>
#include <iostream>

using namespace std;

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int *getArray(int a, int d, int n) {
  int *ret = new int[n];
  for (int i = 0; i < n; i++) {
    ret[i] = a + i * d;
  }
  return ret;
}

// Declare a function pointer

// Define the function to be pointed to
double funccc(int a, int b, int c) { return 0.0; }

// 函数指针类型定义
typedef double (*fptr)(int a, int b, int c);

int main() {
  int a = 10;
  int b = 20;
  printf("%p\n", (void *)&a); // 地址
  // 指针定义
  int *pa = &a; // 指针变量
  int *pb = &b;
  printf("%p %p\n", pa, pb);

  // 指针解引用
  *pa = 7;
  printf("a = %d\n", *pa);
  printf("指针内存大小 %zu\n", sizeof(int *)); // 8字节

  // 空指针
  int *p = NULL;
  printf("p = %p\n", p); // 0x0

  // 指针常量 指针的值是一个常量 指针的值只的就是地址，即指针指向的地址不可变，但指向地址的值可变
  int *const cp = &a;

  // 常量指针 指向常量的指针，常量指针指向的地址可变，但是地址指向的值可变
  const int *pc = &a;
  // pc = &b; //错误

  // 常量指针常量
  const int *const cpc = &a;

  // 指针 数组
  // 利用指针访问数组
  int arr[5] = {1, 2, 3, 4, 5};
  int *parr = arr; // 数组指针指向首地址
  for (int i = 0; i < 5; i++) {
    printf("%d ",
           *(parr + i)); // 指针地址+1 数组的下一位置，数组元素地址是连续的
  }
  printf("\n");

  // 指针数组
  char ca[] = "I";
  char cb[] = "love";
  char cc[] = "China";
  char *ppa[3];
  ppa[0] = ca;
  ppa[1] = cb;
  ppa[2] = cc;
  for (int i = 0; i < 3; i++) {
    printf("%s ", ppa[i]);
  }
  printf("\n");

  // 数组指针
  int(*pap)[5];
  printf("%p\n", pap);

  // 指针作为函数参数
  printf("a = %d, b = %d\n", a, b);
  swap(&a, &b);
  printf("a = %d, b = %d\n", a, b);

  // 指针函数
  int *ans = getArray(5, 3, 6);
  for (int i = 0; i < 6; i++) {
    printf("%d ", ans[i]);
    printf("%d ", *(ans + i));
  }

  // 函数指针
  double (*ptr)(int a, int b, int c);
  ptr = funccc;
  ptr(1, 2, 3);

  fptr ptr1 = funccc;
  ptr1(1, 2, 3);
}
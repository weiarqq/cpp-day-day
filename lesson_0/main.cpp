
#include "global.h"
#include <cstdlib>
#include <iostream>
#include <thread>

using namespace std;

// 自动存储
void func() {
    int a = 10;
    auto b = 10; // C++11后auto用于类型推断，仍为自动存储
}

// 静态存储
static int A =
    100; // 全局静态变量，在文件作用域定义，仅当前文件可见，避免命名冲突。

void func_static() {       // 在函数内定义，只初始化一次，函数调用结束后不销毁。
    static int st_a = 100; // 仅第一次调用时初始化
}

// 外部存储
// 用于声明在其他文件中定义的全局变量或函数，实现跨文件共享。
// global.cpp 定义了全局变量 shared_var
// extern int shared_var;

// void func_extern() { cout << shared_var << endl; }

// 线程存储 每个线程拥有独立的变量副本，避免线程间数据竞争。
thread_local int thread_id;
void func_thread(int d) {
    thread_id = d;
    cout << thread_id << endl;
}

// noexcept 函数不抛出异常
void func_noexcept() noexcept {
    int a = 0; // Avoid division by zero
    double b = 3.0 / a;
    cout << "Result: " << b << endl;
}

// 建议编译器将函数调用处替换为函数体本身,而不会在代码区构建函数
// 注意：inline是编译器建议，而非强制命令。编译器会根据函数复杂度（如是否有循环、递归等）决定是否真正内联。
inline int func_inline(int a, int b) { return a + b; }
// 若 T 的移动构造函数不抛异常，则当前函数也不抛异常
template <typename T>
void func_move_data(T& a, T& b) noexcept(noexcept(T(std::move(a)))) {
    b = std::move(a);
}

constexpr int MAX_SIZE = 100;
int arr[MAX_SIZE];

constexpr int square(int x) { return x * x; }

constexpr int result = square(5); // 编译期计算，结果为25

const int aaa = rand(); // 合法，运行时确定值
// constexpr int bbbb = rand(); // 错误，rand()不是编译期可计算的

int main() {
    func();
    func_static();
    func_thread(0);
    func_inline(1, 2); // 编译时会把func_inline替换为实际的运行代码
    func_noexcept();
    // func_extern();
    return 0;
}
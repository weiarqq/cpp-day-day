// 函数模板
#include <iostream>
using namespace std;

/*
template<typename T, typename T2, typename T3>
函数的定义

模版默认无法进行隐式转换，比如int->double
当使用显示指定类型时，可以进行隐式类型转换 add<int>(int, double)

函数模版支持多个类型参数
一旦类型不能推导，则会导致编译报错
返回值类型无法作为推导依据， 即返回值类型不能单独作为typename

1. 当普通函数和模版函数同名时，优先调用普通函数,
 1.1 当显示指定类型，或者添加<>可以强制调用函数模版，add<>
 1.2
需要发生隐式类型转换时，优先使用模版，发生隐式转换时，普通函数不是最优先匹配
*/

template <typename T> T addInt(T a, T b) {
    cout << "函数模版" << endl;
    return a + b;
}
int addInt(int a, int b) {
    cout << "普通函数" << endl;
    return a + b;
}

// 通用模板：比较两个值
template <typename T> T addTemp(T a, T b) {
    return a + b; // 对指针会比较地址（非内容）
}

// 全特化：针对const char*（字符串）
template <> std::string addTemp<std::string>(std::string a, std::string b) {
    return a + b; // 比较字符串内容
}

template <typename T1, typename T2> T2 add2(T1 a, T2 b) {
    return a + b;
} // 多参数

int main() {
    double a = 10;
    double b = 1.1;
    int d = 10;
    int aaa = addInt(5, 6);
    double c = addInt(a, b);
    double cc = addInt<double>(a, b);
    int ccc = addInt<int>(a, d);
    cout << c << endl;
    cout << cc << endl;
    cout << ccc << endl;

    // string sss = addInt("hello", " world");
    double xx = add2(1, 1.1);
    cout << xx << endl;
    cout << addTemp(5, 5) << endl; // 1（正确）
    std::string sa = "hello ";
    std::string sb = "world";
    const char* sc = "hello world";
    cout << addTemp(sa, sb) << endl; // 1（特化后正确比较内容）
    std::string sss;
    return 0;
}
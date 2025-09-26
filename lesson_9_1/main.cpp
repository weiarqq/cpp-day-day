
#include <iostream>

using namespace std;
class String {
  public:
    explicit String(const char* str) {
        // 构造函数实现
    }
    // String(const char* str) {
    //     // 构造函数实现
    // }
};

int main() {
    String s1("hello");  // 直接初始化，OK
    String s2 = "hello"; // 错误！禁止隐式转换

    // 需要显式转换
    String s3 = String("hello");
    String s4 = static_cast<String>("hello");
}
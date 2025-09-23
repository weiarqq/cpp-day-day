#include <iostream>
using namespace std;

void printBinary(int num) {
    // int类型通常为32位，从最高位开始检查
    for (int i = 31; i >= 0; i--) {
        // 检查第i位是否为1
        if (num & (1 << i)) {
            cout << "1";
        } else {
            cout << "0";
        }

        // 每4位添加一个空格，便于阅读
        if (i % 4 == 0) {
            cout << " ";
        }
    }
    cout << endl;
}

// 位或： 有1即1
// 逻辑或： 有真即真
int main() {
    int a = 0b10101;
    int b = 0b1100;
    printf("a = %d, b = %d\n", a, b);
    printf("a|b = %d\n", a | b); // 1110
    printBinary(a | b);
    printf("a&b = %d\n", a & b); // 1000
    printBinary(a & b);
    printf("a^b = %d\n", a ^ b); // 0110
    printBinary(a ^ b);

    // 原码 反码 补码 移码//0x

    return 0;
}
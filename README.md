## C++  Learn(C++ 入门教程)

### 数据类型

|数据类型|类型|字节数|取值范围|
| ---- | ---- |---- | ---- |
|  short   | 短整型 | 2 |-2^15~2^15-1|
| unsigned short     | 无符号短整型   | 2       | 0～2^16-1                               |
| int                | 整型           | 4       | -2^31~2^31-1                            |
| unsigned int       |无符号整型|4|0~2^32-1|
| long               | 长整型         | 4       | 取决于平台（通常为 -2^31 到 2^31-1 等） |
| unsigned long      | 无符号长整型   | 4       | 取决于平台（通常为 0 到 2^32-1 等）     |
| long long          | 长长整型       | 8       | -2^63~2^63-1                            |
| unsigned long long | 无符号长长整型 | 8       | 0~2^64-1                                |
| float              | 单精度浮点型   | 4  8E23M | 约 ±3.4×10^38（精度约 6-7 位小数）      |
| double             |双精度浮点型|8  11E52M|约 ±1.7×10^308（精度约 15-17 位小数）|
|long double|长双精度浮点型|8/10/16|取决于平台（精度通常高于`double`）|
|char|字符型|1|-128 ~ 127 或 0 ~ 255（取决于实现）|
|signed char|有符号字符型|1|-128 ~ 127|
|unsigned char|无符号字符型|1|0~255|
|bool|1布尔型|1|`true`（真）或 `false`（假）|
|wchar_t|宽字符类型|||
|`char8_t`|UTF-8 字符类型|||
|`char16_t`|UTF-16 字符类型|||
|char32_t|UTF-32 字符类型|||

`Int` 占4字节，每个字节有8位，则可以表示为32位，符号位(正/负)占一位，数字占31位，即可以表示31的二进制数，即2^31

`float`: 

在 C/C++ 中，`float`类型占用 4 字节（32 位），其取值范围和精度是通过**IEEE 754 单精度浮点数标准**定义的，内部结构分为三部分：

| 组成部分    | 位数  | 作用                                               |
| ----------- | ----- | -------------------------------------------------- |
| 符号位（S） | 1 位  | 表示正负（0 为正，1 为负）                         |
| 指数位（E） | 8 位  | 决定数值的数量级（偏移量为 127）                   |
| 尾数位（M） | 23 位 | 表示数值的精度（隐含一位整数 1，实际精度为 24 位） |

取值范围的计算方式：

float类型，会把数字按照指数形式表示，比如2123.1231 = 1.02345... × 2¹¹（二进制里的 "科学计数法"）

1. **指数位（E）的范围**：8 位无符号整数的取值范围是 0~255，但标准规定：
   - E=0 且 M=0 时，表示 0
   - E=255 且 M=0 时，表示无穷大（±∞）
   - E=255 且 M≠0 时，表示 NaN（非数值）
   - 有效指数范围为 1~254，对应的实际指数为 **E-127**（范围：-126~+127） 1~254 偏移127 -> ~126 ~+127
2. **尾数位（M）的贡献**：尾数位表示小数部分，加上隐含的整数位 1，实际值为 `1.M`（二进制），范围是 `[1.0, 2.0)`。
3. **最终范围**：结合符号位，`float`的典型取值范围为：
   - 最小值（接近 0 的正数）：约 `1.175×10^-38`
   - 最大值：约 `3.402×10^38`
   - 可表示正负值，因此完整范围是 `±1.175×10^-38 ~ ±3.402×10^38`

> 假设浮点数：2123.1231
>
> 按照科学计数法：2123.1231 = 1.02345... × 2¹¹（二进制里的 "科学计数法"）
>
> 然后拆成三部分记下来（总共 32 个格子）：
>
> - 第 1 个格子：记正负（0 代表正，1 代表负）
> - 接下来 8 个格子：记指数（这里是 11，但要加 127 变成 138，因为指数可以是负数）
> - 最后 23 个格子：记小数点后的部分（.02345... 的二进制）
>
> 这样 32 个格子就把 2123.1231"挤" 进去了。
>
> 因为只有 23 位记小数，所以不能完全精确，就像用有限的格子记圆周率，总会有点误差。这就是为什么 float 能表示很大的范围，但精度有限。

### 关键字

以下是C++关键字的汇总表格：

| 关键字             | 类别                  | 作用                                               |
| ------------------ | --------------------- | -------------------------------------------------- |
| `bool`             | 基本数据类型          | 表示布尔类型，取值为`true`或`false`                |
| `char`             | 基本数据类型          | 表示字符类型，通常占1字节                          |
| `int`              | 基本数据类型          | 表示整数类型，通常占4字节                          |
| `float`            | 基本数据类型          | 表示单精度浮点类型，占4字节                        |
| `double`           | 基本数据类型          | 表示双精度浮点类型，占8字节                        |
| `void`             | 基本数据类型          | 表示无类型，用于函数返回值或空指针                 |
| `wchar_t`          | 基本数据类型          | 表示宽字符类型，用于存储多字节字符                 |
| `char8_t`          | 基本数据类型（C++20） | 表示UTF-8字符类型                                  |
| `char16_t`         | 基本数据类型（C++11） | 表示UTF-16字符类型                                 |
| `char32_t`         | 基本数据类型（C++11） | 表示UTF-32字符类型                                 |
| `signed`           | 类型修饰符            | 修饰整数类型为有符号类型                           |
| `unsigned`         | 类型修饰符            | 修饰整数类型为无符号类型                           |
| `short`            | 类型修饰符            | 修饰整数类型为短整数                               |
| `long`             | 类型修饰符            | 修饰整数或浮点类型为长类型                         |
| `long long`        | 类型修饰符（C++11）   | 修饰整数类型为更长的整数                           |
| **`auto`**         | 存储与类型            | 自动推断变量类型（C++11后增强）                    |
| `register`         | 存储类别              | 建议编译器将变量存储在寄存器中                     |
| `static`           | 存储类别              | 声明静态变量或函数，延长生命周期或限制作用域       |
| `extern`           | 存储类别              | 声明外部变量或函数，提示编译器在其他文件中寻找定义 |
| `mutable`          | 存储类别              | 允许在`const`成员函数中修改类的成员变量            |
| `thread_local`     | 存储类别（C++11）     | 声明线程局部变量，每个线程有独立副本               |
| `if`               | 控制语句              | 条件判断语句                                       |
| `else`             | 控制语句              | 与`if`配合使用的分支语句                           |
| `switch`           | 控制语句              | 多分支选择语句                                     |
| `case`             | 控制语句              | `switch`中的分支标签                               |
| `default`          | 控制语句              | `switch`中的默认分支                               |
| `for`              | 控制语句              | 循环语句                                           |
| `while`            | 控制语句              | 循环语句                                           |
| `do`               | 控制语句              | 与`while`配合使用的循环语句， do... while          |
| `break`            | 控制语句              | 跳出当前循环或`switch`语句                         |
| `continue`         | 控制语句              | 跳过当前循环的剩余部分，进入下一次迭代             |
| `goto`             | 控制语句              | 无条件跳转语句（不推荐使用）                       |
| `return`           | 函数相关              | 函数返回语句                                       |
| **`inline`**       | 函数相关              | 建议编译器将函数作为内联函数处理，减少函数调用开销 |
| `noexcept`         | 函数相关（C++11）     | 声明函数不会抛出异常                               |
| `constexpr`        | 函数相关（C++11）     | 声明常量表达式，可在编译期计算                     |
| `class`            | 类与对象              | 定义类类型                                         |
| `struct`           | 类与对象              | 定义结构体，与`class`类似但默认成员为公有          |
| `union`            | 类与对象              | 定义联合体，成员共享同一块内存                     |
| `enum`             | 类与对象              | 定义枚举类型                                       |
| `enum class`       | 类与对象（C++11）     | 定义强类型枚举，避免枚举值冲突                     |
| `public`           | 访问控制              | 类成员的公有访问控制符                             |
| `private`          | 访问控制              | 类成员的私有访问控制符                             |
| `protected`        | 访问控制              | 类成员的保护访问控制符                             |
| `this`             | 类与对象              | 指向当前对象的指针                                 |
| `friend`           | 类与对象              | 声明友元，允许外部函数或类访问私有成员             |
| **`explicit`**     | 类与对象              | 防止构造函数的隐式类型转换                         |
| `operator`         | 类与对象              | 用于运算符重载                                     |
| **`virtual`**      | 继承与多态            | 声明虚函数，实现多态                               |
| `override`         | 继承与多态（C++11）   | 显式声明重写基类的虚函数                           |
| `final`            | 继承与多态（C++11）   | 禁止派生类重写虚函数或禁止类被继承                 |
| `static_assert`    | 编译期检查（C++11）   | 编译期断言，用于检查编译期条件                     |
| `dynamic_cast`     | 类型转换              | 动态类型转换，用于多态场景下的安全转换             |
| `static_cast`      | 类型转换              | 静态类型转换，用于相关类型间的转换                 |
| `reinterpret_cast` | 类型转换              | 重新解释类型转换，用于不相关类型间的转换           |
| `const_cast`       | 类型转换              | 移除变量的`const`或`volatile`属性                  |
| `const`            | 常量相关              | 声明常量，不可修改的变量或成员函数                 |
| `volatile`         | 类型修饰              | 声明易变变量，防止编译器过度优化                   |
| `sizeof`           | 运算符                | 计算类型或变量占用的字节数                         |
| `typedef`          | 类型定义              | 为已有类型定义别名                                 |
| `using`            | 命名空间/类型         | 引入命名空间成员或定义类型别名（C++11后）          |
| `namespace`        | 命名空间              | 定义命名空间，避免命名冲突                         |
| `try`              | 异常处理              | 异常处理的尝试块                                   |
| `catch`            | 异常处理              | 捕获并处理异常                                     |
| `throw`            | 异常处理              | 抛出异常                                           |
| `delete`           | 内存管理              | 释放动态分配的单个对象内存                         |
| `new`              | 内存管理              | 动态分配单个对象内存                               |
| `new[]`            | 内存管理              | 动态分配数组内存                                   |
| `delete[]`         | 内存管理              | 释放动态分配的数组内存                             |
| `nullptr`          | 指针相关（C++11）     | 空指针常量，替代`NULL`                             |
| `alignas`          | 内存对齐（C++11）     | 指定变量或类型的对齐方式                           |
| `alignof`          | 内存对齐（C++11）     | 获取类型的对齐要求                                 |
| `typeid`           | 类型信息              | 获取表达式或类型的类型信息（需包含`<typeinfo>`）   |

说明：
1. 表格包含了C++标准中的主要关键字，部分关键字在C++11及以后版本中新增（已标注）。
2. 关键字不能作为标识符（变量名、函数名等）使用。
3. 部分关键字的作用可能因上下文略有差异，表格中为主要作用说明。

### 内存管理

**代码区**

- **用途**：存储程序的二进制机器指令（即编译后的可执行代码）。
- **特点**：
  - 只读（防止程序意外修改指令）。
  - 共享（多个进程运行同一程序时，可共享同一份代码）。
  - 大小在程序运行前已确定。
- **生命周期**：程序加载时分配，程序结束时释放。

**全局区(静态区)**

- **用途**：存储全局变量、静态变量（`static` 修饰）和字符串常量。
- **细分**：
  - **全局变量区**：定义在函数外的变量（如 `int g_var;`）。
  - **静态变量区**：`static` 修饰的变量（包括全局静态变量和局部静态变量）。
  - **常量区**：存储字符串常量（如 `"hello"`）和 `const` 修饰的全局常量。
- **特点**：
  - 变量在程序编译时分配内存。
  - 未初始化的全局变量和静态变量会被自动初始化为 0。
- **生命周期**：程序启动时分配，程序结束时释放（与程序生命周期一致）。

```c++
// 全局变量（存于全局区）
int g_var = 10;
static int g_static_var = 20;  // 全局静态变量（存于全局区）

int main() {
    static int l_static_var = 30;  // 局部静态变量（存于全局区）
    const char* str = "hello";     // "hello" 字符串常量（存于常量区）
    return 0;
}
```

**堆区**

- **用途**：存储动态分配的内存（程序员手动申请和释放）。
- **特点**：
  - 内存大小不固定，可动态增长或缩减。
  - 由程序员通过 `new`/`delete`（C++）或 `malloc`/`free`（C）手动管理。
  - 分配效率低于栈区，但灵活性更高（生命周期可自定义）。
- **生命周期**：从 `new`/`malloc` 申请时分配，到 `delete`/`free` 释放时回收；若未手动释放，程序结束后由操作系统回收（可能导致内存泄漏）。

```c++
int main() {
    // 堆区分配
    int* p1 = new int(100);    // 动态分配一个 int
    int* p2 = new int[5];      // 动态分配 int 数组
    
    // 必须手动释放，否则内存泄漏
    delete p1;
    delete[] p2;
  	p1 = NULL;
  	p2 = NULL;
    return 0;
}
```

**栈区**

- **用途**：存储函数的局部变量、函数参数、返回地址等。
- **特点**：
  - 内存自动管理（由编译器自动分配和释放）。
  - 遵循 “先进后出”（FILO）原则，类似栈数据结构。
  - 大小固定（编译时确定，通常为几 MB），溢出会导致 “栈溢出” 错误（如递归过深）。
- **生命周期**：变量在函数调用时分配，函数执行结束后自动释放。

```c++
void func(int param) {  // param 存于栈区
    int a = 10;         // 局部变量，存于栈区
    // 函数结束时，a 和 param 自动释放
}

int main() {
    func(20);
    return 0;
}
```

**总结对比** 

| 区域   | 存储内容                 | 分配方式       | 生命周期               | 特点                     |
| ------ | ------------------------ | -------------- | ---------------------- | ------------------------ |
| 代码区 | 二进制指令               | 系统自动分配   | 程序加载到结束         | 只读、共享               |
| 全局区 | 全局变量、静态变量、常量 | 编译时分配     | 程序启动到结束         | 自动初始化，大小固定     |
| 堆区   | 动态分配的内存           | 程序员手动申请 | `new` 到 `delete` 之间 | 灵活，需手动管理，易泄漏 |
| 栈区   | 局部变量、函数参数       | 编译器自动分配 | 函数调用到结束         | 高效，大小有限，自动释放 |



### 运算符

| 类别           | 运算符                                                       | 说明                                                         |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **算术运算符** | `+` `-` `*` `/` `%`                                          | 加、减、乘、除、取余（取余仅用于整数）                       |
|                | `++` `--`                                                    | 自增、自减（前缀：先运算后使用；后缀：先使用后运算）         |
| **赋值运算符** | `=`                                                          | 基本赋值                                                     |
|                | `+=` `-=` `*=` `/=` `%=`                                     | 复合赋值（如 `a += b` 等价于 `a = a + b`）                   |
|                | `<<=` `>>=` `&=` `^=` `|=`                                   | 位运算复合赋值                                               |
| **比较运算符** | `==` `!=`                                                    | 等于、不等于                                                 |
|                | `<` `>` `<=` `>=`                                            | 小于、大于、小于等于、大于等于                               |
| **逻辑运算符** | `&&`                                                         | 逻辑与（短路求值：左侧为假则不执行右侧）                     |
|                | `||`                                                         | 逻辑或（短路求值：左侧为真则不执行右侧）                     |
|                | `!`                                                          | 逻辑非                                                       |
| **位运算符**   | `&` `|` `^`                                                  | 按位与、按位或、按位异或                                     |
|                | `~`                                                          | 按位取反                                                     |
|                | `<<` `>>`                                                    | 左移（乘以 2 的 n 次方）、右移（除以 2 的 n 次方，符号位处理取决于类型） |
| **条件运算符** | `?:`                                                         | 三目运算符（`condition ? expr1 : expr2`，条件为真返回 expr1，否则 expr2） |
| **指针运算符** | `*`                                                          | 解引用（获取指针指向的值）                                   |
|                | `&`                                                          | 取地址（获取变量的内存地址）                                 |
| **成员访问符** | `.`                                                          | 直接成员访问（用于对象）                                     |
|                | `->`                                                         | 间接成员访问（用于指针）                                     |
| **其他运算符** | `sizeof`                                                     | 计算类型 / 变量的字节大小                                    |
|                | `typeid`                                                     | 获取类型信息（需包含 `<typeinfo>`）                          |
|                | `new` `delete`                                               | 动态内存分配、释放                                           |
|                | `new[]` `delete[]`                                           | 动态数组分配、释放                                           |
|                | `cast运算符`（`static_cast` `dynamic_cast` `const_cast` `reinterpret_cast`） | 类型转换运算符                                               |
|                | `throw`                                                      | 抛出异常                                                     |
|                | `,`                                                          | 逗号运算符（按顺序执行，返回最后一个表达式结果）             |

**位运算符**

```c++
#include <iostream>
using namespace std;

int main() {
    int a = 0b10101;
    int b = 0b1100;
  
    // 如果 a和b的位数不同，则在前面补0即可
    // int a = 0b10101;
    // int b = ob01100

    printf("a|b = %d\n", a | b); // 11101 对应位置 有1即1
    
    printf("a&b = %d\n", a & b); // 0100  对应位置 都为1则1
    
    printf("a^b = %d\n", a ^ b); // 11001 对应位置 不同则1
   

    // 原码 反码 补码 移码//0x

    return 0;
}
```



### 常量

如下两种方式

```c++
#define A "常量A"
const int B "常量B"
```



### 指针

**指针定义** 

```c++
int a = 10;
//指针定义
int* point_a = &a; 

// 指针解引用
*point_a = 7; 

// 空指针
int *p = NULL;

//野指针以及发生的场景
// 1.指针指向的内存被释放后未置空
int *p_new = new int(20);
delete p_new; //delete后，p_new变为野指针
p_new = NULL; // 变为空指针，防止野指针

// 2.指针未初始化
int *p; //未初始化的野指针，指向随机地址, 可以写成 int* p = NULL;
*p = 10; // 危险：向随机内存写入数据，可能崩溃

// 3.指针越界访问
int arr[3] = {1, 2, 3};
int* p = arr;
p += 5;  // 越界，指向数组外的无效内存，成为野指针
*p = 100; // 危险：修改未知内存


// 指针常量, 指针的值是一个常量(指针的值只的就是地址)，即指针指向的地址不可变，但指向地址的值可变
int *const cp = &a;

// 常量指针, 指向常量的指针，常量指针指向的地址可变，但是地址指向的值可变
const int *pc = &a;
// 常量指针常量
const int *const cpc = &a; 

// 指针作为返回值
int* getArray(int a, int d, int n) {
    int* ret = new int[n]; // 需要new,不然函数结束会释放内存
    for (int i = 0; i < n; i++) {
        ret[i] = a + i * d;
    }
    return ret;
}
int* ans = getArray(5, 3, 6);

// 利用指针访问数组
int arr[5] = {1, 2, 3, 4, 5};

// 数组指针指向首地址, 其他类型下，int*parr = &arr,但是数组不能这么使用，int *parr = arr 等价于 int *parr = &arr[0];
// 多数情况下数组变量会被隐式转换为指向数组首元素的指针，这种行为称为 “数组名退化”（array decay）。
int *parr = arr; 

int (*parr) = &arr;

for (int i = 0; i < 5; i++) {
  printf("%d ",*(parr + i)); // 指针地址+1 数组的下一位置，数组元素地址是连续的
}
          
```

**数组读取和char数组**

```c++
int t = 0;
char s[5] = {'0', '1', '2', '3', '4'};
cout << '6' << s + 3
     << endl; //指针偏移 当使用 s + 6 时，数组名 s 会隐式转换为指针
              // s[0]的指针，s + 6 则表示指向 s[6] 的指针（即从第
              // 7个元素开始的子串）， cout返回的是对应位置的子串
//   int *p = new int[10];
int a[5] = {1, 2, 3, 4, 5};
char c[6] = "01234"; // 等价于 char a[6] ={'0', '1', '2', '3', '4', '\0'}
//   字符数组要以'\0'结尾，5个字符 占用6个空间，不添加'\0'时，指针溢出，会循环整个数组内存的数据，即会读取到s的内存

cout << a + 3 << endl;
int *pa = a;
// 获取对应位置的 三种方式
cout << *(pa + 1) << endl;
cout << pa[1] << endl;
cout << a[1] << endl;

cout << pa + 1 << endl;
cout << a + 1 << endl;
```



**数组指针** 

> 直接定义一个指针，指针一个二维数组的行首元素

```c++
// 数组指针
int (*p)[5]; // 表示 p指针一个列为5的二维数组内存地址, 即p访问的是每行的首元素
int a[2][5] = {{1,2,3,4,5}, {2,3,4,5,6}};
p = a;

char arrr[5] = {'1', '2', '3', '4', '5'};

char* p_arrr = arrr;
char* pp_arrr = &arrr[0];

// 获取的是整个数组的地址（类型为 char(*)[5]，即 “指向包含 5 个 char 的数组的指针”）, 即 指针+1，是移动5个内存位置
char (*ppp_arrr)[5] = &arrr;

// 以上三个指针指向的地址相同，但ppp_arrr指向的是整个数组的指针， ppp_arrr+1 != (pp_arrr+1 = p_arrr+1)
cout << (void*)p_arrr << " " << (void*)pp_arrr << " " << (void*)ppp_arrr
     << endl; // 0x7ff7b43585db 0x7ff7b43585db 0x7ff7b43585db

cout << (void*)(p_arrr + 1) << " " << (void*)(pp_arrr + 1) << " "
         << (void*)(ppp_arrr + 1)
         << endl; // 0x7ff7b794a5dc 0x7ff7b794a5dc 0x7ff7b794a5e0




```

**指针数组**

> 用数组来存储指针

```c++
char ca[] = "I";
char cb[] = "love";
char cc[] = "China";
char* ppa[3]; // 要区分和 char (*ppa)[3]的区别 char* ppa[3]，表示数组中的元素是指针类型
ppa[0] = ca; 
ppa[1] = cb;
ppa[2] = cc;
for (int i = 0; i < 3; i++) {
    printf("%s ", ppa[i]);
}
```



****



**指针函数**

```c++

double funccc(int a, int b, int c) { return 0.0; }

// 函数指针类型定义
typedef double (*fptr)(int a, int b, int c);

// 函数指针定义
double (*ptr)(int a, int b, int c);

// 使用函数指针声明
double (*ptr)(int a, int b, int c);
ptr = funccc;
ptr(1, 2, 3);

// 使用函数指针类型声明
fptr ptr1 = funccc;
ptr1(1, 2, 3);
```



### 结构体和类

> 结构体和类的核心区别是**默认访问权限**（`struct` 默认为 `public`，`class` 默认为 `private`）和**默认继承方式**（`struct` 默认为 `public` 继承，`class` 默认为 `private` 继承）。除此之外，两者功能完全一致，选择使用哪一种更多取决于编程习惯和代码的语义表达。

### 结构体

> C语言兼容性：C 语言中的 `struct` 仅能包含数据成员，无成员函数，C++ 的 `struct` 是对 C 的扩展，保持了兼容性。

```c++
struct Book {
  string name;
  double price;
  int value;
  Author author;
};

// 结构体初始化
Book book = {"C++", 99.9, 10};
// 结构体初始化
Book books[2] = {{"C++", 99.9, 10}, {"Java", 88.8, 20}};

// 结构体指针
Book go = {"Go", 77.7, 30};
Book *p = &go;
p->name = "Golang";
```

**联合体**

```c++
// 定义一个联合体, 其成员共享同一块内存, 即如下三个变量 i,f,str共享内存，只能有一个有值，其他的会把覆盖
union DataU {
  int i;
  float f;
  char str[20];
};

struct Info{
    char _name[20];
    int _role; // 0学生 1老师， 当为学生时，score有效，当为老师时，course有效，节省内存
    union {
        int score;
        char course[20];
    } _sc;
};
```

### 类

**三大特征:**

- 封装 

- 继承 

- 多态

#### 封装

> **将数据（成员变量）和操作数据的方法（成员函数）捆绑在一起，并通过访问控制限制外部对内部数据的直接操作**。
>
> 简单说，封装就像 “黑盒”：外部只能通过预设的接口（函数）与内部交互，无法直接触碰内部细节。

**模板**

```
class 类名{
访问权限：
    属性(成员变量)
    行为(成员函数)
}
```



**访问权限**:

- private：私有权限   类内可以访问，类外不可以访问, 子类不可以访问
- protected：保护权限  类内可以访问，类外不可以访问，子类可以访问
- public：公共权限  类内可以访问，类外也可以访问，子类可以访问

**构造函数**
作用：在对象创建时自动调用，用于初始化对象的成员变量、分配资源（如内存、文件句柄等）。

- 函数名称和类名一致

- 函数返回值不用写

- 可以被重载（定义多个参数不同的构造函数）。

- 如果未显式定义，编译器会自动生成一个默认构造函数（无参数，不做任何操作）。



**析构函数**
作用：在对象销毁时自动调用，用于释放对象占用的资源（如动态内存、关闭文件等），避免内存泄漏。

- 函数名称和类名一致，在前面添加一个~
- 函数返回值不用写
- 不能有参数
- 对象销毁时（如离开作用域、被 delete 释放）自动调用。
- 如果未显式定义，编译器会生成默认析构函数（不做任何操作）。

**实例**

```c++
class Hero {

private:
  string name;
  int hp;
  mutable int count; // mutable 允许在`const`成员函数中修改类的成员变量

public:
  Hero() { cout << "构造函数使用" << endl; }; 						// 无参构造函数
  Hero(string name, int hp) : name(name), hp(hp) { 			// 初始化列表
    cout << "初始化列表使用" << endl;
  }

  Hero(string name) {																		// 有参构造函数
    this->name = name;																	// this指针，解决命名冲突问题，this指向的是对象本身
    cout << "有参构造函数使用" << endl;
  }
  ~Hero() { cout << "析构函数使用" << endl; }							// 析构函数，程序自动调用 释放内存
  Hero(const Hero &hero) {
    name = hero.name;
    cout << "拷贝构造函数使用" << endl;
  }
  
  static int m_count; 																	// 静态变量 全局共享
  static int getMCount(){																// 静态成员函数 全局共享， 只能使用静态成员变量
    return m_count;
  } 
  
  string setCount() const{															// 常函数
    // this->name = "weah"; 														// 常量成员函数不能修改成员变量
    count++; 																						// mutable 修饰变量可以在常函数中进行修改
  }
  
};

int main() {
  Hero heroo;
  Hero hero("wangqi");
  Hero hero2("swen", 100);
  Hero hero1(hero);
  Hero *hero3 = new Hero(); // new一个类

  delete hero3;
  cout << "锚点" << endl; //锚点后，即程序结束前默认调用析构函数

  return 0;
}
```

**静态成员**

- 所有的对象共享同一份数据

- 编译阶段分配内存

- 需要在类中进行声明，在类外进行初始化

**静态成员函数**

- 所有对象共享函数

- 静态成员函数只能使用静态成员变量，无法使用普通成员变量

**常函数**

在 C++ 中，**常函数（const member function）** 是指用 `const` 关键字修饰的类成员函数，声明形式为：

```c++
返回类型 函数名(参数列表) const;
```

其核心作用是**保证函数不会修改类的成员变量**，主要有以下用途：

1. **保护数据安全性**常函数内部不能修改类的非静态成员变量（除非变量被 `mutable` 修饰），也不能调用非 const 成员函数（防止间接修改数据）。这避免了函数意外修改对象状态，尤其适合只读操作（如查询、打印等）。
2. **支持 const 对象调用**const 修饰的对象（如 `const 类名 对象;`）只能调用常函数，不能调用非 const 成员函数。这确保了 const 对象的状态不会被任何操作改变，是 const 关键字 "只读" 语义的延伸。
3. **提高代码可读性与可维护性**函数声明中的 `const` 是一种 "契约"，明确告诉开发者和编译器：该函数仅用于查询，不改变对象状态。这让代码意图更清晰，减少了误修改数据的风险。



**对象生命周期**

C++类对象的生命周期会随其作用域或管理方式结束而终止，此时会主动调用析构函数，并非只有程序结束时才会调用析构函数。程序结束时调用析构函数，只是针对“生命周期与程序一致” 的对象（如全局对象），而非所有对象。
要理解这个问题，核心是先明确 C++类对象的三种常见生命周期场景，不同场景下析构函数的调用时机完全不同：

1. 局部对象：作用域结束时调用析构函数定义在函数、代码块（如 if/for 内部）中的局部对象，其生命周期与 “所在的作用域”绑定 ——离开作用域时，对象会自动销毁，析构函数立即调用，和程序是否结束无关。

2. 动态对象：delete 时调用析构函数
用 new 动态创建的对象（如 Test* t = new Test()），其生命周期不绑定作用域，而是由程序员手动管理 ——只有调用 delete时，对象才会销毁，析构函数才会调用；如果忘记delete，就是内存泄漏（但程序结束时仍会被操作系统回收）。

3. 全局 / 静态对象：程序结束时调用析构函数
定义在函数外部的全局对象、或用 static修饰的静态对象（包括局部静态对象），其生命周期与程序一致——程序启动时创建，程序结束时才销毁，析构函数在此时调用。 这是唯一“程序结束时才调用析构函数” 的场景，但仅针对这类特殊对象，并非所有对象。



#### 继承

> 在 C++ 中，**继承（Inheritance）** 是面向对象编程的三大核心特性之一，它允许一个类（称为**派生类 / 子类**）继承另一个类（称为**基类 / 父类**）的属性和方法，从而实现代码复用和层次化设计。
>
> 简单说，继承就像 “儿子继承父亲的财产”—— 子类可以直接使用父类的成员，还能在此基础上添加新功能或修改已有功能。

```c++
class 子类名： 继承方式 父类名 {};
class Child: public Parent{};
```

**继承方式**

- 公共 public
- 保护 protected
- 私有 private

子类访问父类成员的权限会因为继承方式而改变
| 继承方式\父类成员访问权限 | public | protected | private |
| ------------------------- | ------ | --------- | ------- |
|public                              |public     | protected   |无法访问|
|protected                          | protected | protected  | 无法访问|
|private                             |private     |private     |无法访问|

**构造函数顺序**

继承中的父类子类构造函数和析构函数顺序
构造链中，先构造的后析构，先构造父类再构造子类

```C++
#include <iostream>
using namespace std;

class Animal {
public:
  Animal() { cout << "父类构造函数" << endl; }
  void eat() { cout << this->name << "吃" << endl; }

  void drink() { cout << this->name << "喝" << endl; }
  string name;

  ~Animal() { cout << "父类析构函数" << endl; }
};

class Dog : public Animal {
public:
  Dog() {
    name = "狗";
    cout << "子类 狗 构造函数" << endl;
  }
  string name;
  ~Dog() { cout << "子类 狗 析构函数" << endl; }
  void eat() { cout << this->name << "吃" << endl; }
};

class Cat : public Animal {
public:
  Cat() {
    name = "猫";
    cout << "子类 猫 构造函数" << endl;
  }
  string name;
  void eat() { cout << this->name << "吃" << endl; }
  ~Cat() { cout << "子类 猫 析构函数" << endl; }
};

int main() {
  Dog dog;
  Cat cat;
  cout << cat.Animal::name << endl; 			// 同名属性访问,访问父类同名属性
  dog.eat();
  dog.Animal::eat(); 											// 同名函数访问，访问父类同名函数
  cat.drink();
  return 0;
}
```



**多继承**

```c++
class 类名: public 父类1, public 父类2,...{
}
class Son: public Mother, public Father{
  
}
```



#### 多态

> 在 C++ 中，**多态（Polymorphism）** 是面向对象编程的核心特性之一，指**同一接口（函数调用）在不同对象上表现出不同行为**的能力。简单说就是：“一个接口，多种实现”。
>
> 多态的实现基础，多态主要通过**虚函数（virtual function）** 和**继承**实现，核心机制是**动态绑定（运行时绑定）**：
>
> - 编译时，编译器不确定要调用哪个函数
> - 运行时，根据对象的实际类型确定调用的函数版本

```c++
#include <iostream>
using namespace std;

// 基类
class Animal {
public:
    // 虚函数：声明为virtual，允许派生类重写
    virtual void makeSound() const {
        cout << "动物发出声音" << endl;
    }
    
    // 非虚函数：不支持多态
    void eat() const {
        cout << "动物吃东西" << endl;
    }
};

// 派生类1
class Dog : public Animal {
public:
    // 重写（override）基类的虚函数
    void makeSound() const override {
        cout << "汪汪汪" << endl;
    }
};

// 派生类2
class Cat : public Animal {
public:
    // 重写基类的虚函数
    void makeSound() const override {
        cout << "喵喵喵" << endl;
    }
};

// 多态的关键：通过基类指针/引用调用虚函数
void animalSound(const Animal& animal) {
    animal.makeSound(); // 运行时根据实际对象类型调用对应版本
}

int main() {
    Animal animal;
    Dog dog;
    Cat cat;
    
    animalSound(animal); // 输出：动物发出声音
    animalSound(dog);    // 输出：汪汪汪（调用Dog的版本）
    animalSound(cat);    // 输出：喵喵喵（调用Cat的版本）
    
    return 0;
}
```



#### 纯虚函数和抽象类

纯虚函数定义：

```c++
virtual 返回类型 函数名()=0;
```

 **抽象类**:包含纯虚函数的类，称为抽象类，抽象类不能实例化，必须被继承；

```c++
// 纯虚函数和抽象类

#include <iostream>
using namespace std;

class Animal {
public:
  virtual void
  eat() = 0; // 设置 =0 则为纯虚函数, 此时继承的话 子类必须重写，不重写的话
             // 子类也会成为抽象类,
             // 包含纯虚函数的类，称为抽象类，抽象类不能实例化，必须被继承；
  void dink() {}
};

class Cat : public Animal {
public:
  string name;
  void eat() { cout << "猫吃东西" << endl; }
};

int main() {
  Cat cat;
  cat.eat();

  return 0;
}
```



#### 虚析构函数和纯虚析构函数

> 纯虚析构函数，此时BaseA变为抽象类, 并且需要在**类外实现**;虚析构函数，若为多态时，释放内存时会执行子类和父类的虚构函数

```c++
// 虚析构函数和纯虚析构函数
#include <iostream>
using namespace std;

class BaseA {
public:
  BaseA() {}
  //   ~BaseA() { cout << "父类析构函数执行" << endl; }
  //   virtual ~BaseA() { cout << "父类析构函数执行" << endl; } //
  //   虚析构函数，此时多态时，释放内存时会执行子类和父类的虚构函数
  virtual ~BaseA() = 0; // 纯虚析构函数，此时BaseA变为抽象类, 并且需要在类外实现
};

BaseA::~BaseA() { cout << "父类纯虚析构函数执行" << endl; }

class BaseB : public BaseA {
public:
  BaseB() {}
  ~BaseB() { cout << "子类析构函数执行" << endl; }
};

int main() {
  //   BaseA *a = new BaseB();
  //   delete a;
  BaseB b;
  return 0;
}
```



#### 友元

```c++
#include <iostream>
#include <string>
using namespace std;

/*
友元的目的
友元（friend） 是一种打破类封装性的特殊机制，允许指定的外部函数、其他类或类成员函数访问当前类的 private（私有） 或 protected（保护） 成员。


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
```



#### 运算符重载

```c++
// 运算符重载

#include <iostream>
#include <ostream>
using namespace std;

class Complex {
  friend Complex operator-(Complex &a, Complex &b);
  friend Complex &operator++(Complex &a);
  friend ostream &operator<<(ostream &cout, const Complex &a);

private:
  int real;
  int image;

public:
  Complex() : real(0), image(0) {}
  Complex(int real, int image) {
    this->real = real;
    this->image = image;
  }
  Complex operator+(Complex &other) {				// +号重载
    Complex c;
    c.real = other.real;
    c.image = other.image;
    return c;
  }
  Complex &operator++() { 									// 前置++重载 ++a
    this->real += 1;
    return *this;
  }

  Complex operator++(int) { 								// 后置++重载 a++，多类一个单独int的入参，和前置的区别：创建了一个新的对象          					
    Complex c = *this;
    this->real += 1;
    return c;																// 不要返回引用，因为函数内成员会被释放
  }
  void Print() { cout << this->real << "+" << this->image << "i" << endl; }
};

Complex operator-(Complex &a, Complex &b) {
  Complex c;
  c.real = a.real - b.real;
  c.image = a.image - b.image;
  return c;
}

Complex &operator++(Complex &a) {
  a.real += 1;
  return a;
}

ostream &operator<<(ostream &cout,
                    const Complex &a) { // const   cout << c++ << endl报错;
                                        // 非常量引用不能作为函数返回值
  cout << a.real << "+" << a.image << "i" << endl;
  return cout;
}

class A {};

A func1() { return A(); }

void func2(const A &a) {} //const可以

int main() {
  Complex ta(10, 10);
  Complex tb(20, 15);
  Complex c = ta + tb;
  c.Print();
  Complex d = ta - tb;
  d.Print();
  cout << c << endl;
  cout << c++ << endl;

  func2(func1()); // 非常量引用的初始值必须为左值，func1的返回值不是左指，如果是非常量引用，函数执行完后，内部成员会被释放

  return 0;
}
```

**赋值表达式重载**

```C++
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
  hero2 = hero1; // 内存泄漏， 这种情况下，hero2.m_Data原始指向的地址将访问不到
  //m_Data为指针，hero2.m_Data被hero1.m_Data覆盖，则hero2.m_Data原始指向的地址将访问不到了
  cout << hero1.m_Data << " " << hero2.m_Data
       << endl; //由于m_Data为指针，指向地址相同
  hero3 = (hero2 = hero1);
  cout << *hero1.m_Data << " " << *hero2.m_Data << " " << *hero3.m_Data << endl;

  return 0;
}
```

**函数调用运算符重载**

```c++
// 函数调用运算符的重载
#include <iostream>
using namespace std;

class AddFunction {
public:
  AddFunction() : count(0) {}
  int operator()(int a, int b) {
    count++; // 可以用来记录状态
    return a + b + count;
  }

private:
  int count;
};

int main() {
  AddFunction add;
  cout << add(5, 6) << endl;
  cout << add(5, 6) << endl;
  cout << add(5, 6) << endl;
  cout << add(5, 6) << endl;
}
```



#### 内存泄漏

1. **忘记释放动态内存**

   使用`new`分配内存后未用`delete`释放，或使用`new[]`分配数组后未用`delete[]`释放。

   ```cpp
   void func() {
       int* p = new int; // 动态分配内存
       // ... 未使用 delete p; 释放
   } // 函数结束后，p被销毁，但它指向的内存未释放，造成泄漏
   ```

   

2. **释放方式不匹配**

   new` 对应 `delete`，`new[]` 对应 `delete[]`，混用会导致未定义行为（可能部分释放或完全不释放）。

   ```cpp
   int* arr = new int[10];
   delete arr; // 错误：应为 delete[] arr;
   ```

   

3. **异常导致释放代码未执行**

   若在分配内存后、释放前发生异常，释放语句可能被跳过。

   ```cpp
   void func() {
       int* p = new int;
       if (someCondition) {
           throw "Error"; // 抛出异常，跳过 delete
       }
       delete p; // 若发生异常，此句不执行
   }
   ```

   

4. **指针被重新赋值**

   指针指向新地址后，原动态内存的地址丢失，无法释放。

   ```cpp
   int* p = new int;
   p = new int; // 原内存地址被覆盖，无法释放
   delete p; // 仅释放了第二次分配的内存
   ```

   

5. **全局 / 静态指针未释放**

   全局或静态指针分配的内存若未在程序结束前释放，会导致整个程序运行期间的内存泄漏。



### 模版

#### 函数模版

**函数模版定义**：

```c++
template<typename T, typename T2, ...>
返回类型 函数名称(T& t){};
```

**函数模板的工作原理** 

1. **模板定义**：编译器看到 `template <typename T>` 时，会将其视为 "函数蓝图"，不会立即生成具体代码。
2. **类型推导与实例化**：当调用模板函数时（如 `swapValues(x, y)`），编译器会：
   - 根据传入的参数类型自动推导出 `T` 的具体类型（如 `int`）
   - 生成该类型的具体函数（如 `void swapValues(int& a, int& b)`）
3. **编译检查**：对每个实例化的函数进行类型检查，确保操作对该类型有效（如 `T` 必须支持赋值操作）

**注意事项**：

- 模板定义通常需要放在头文件中（因为编译器需要在调用处看到完整定义才能实例化）。
- 模版默认无法进行隐式转换，比如int->double，但当使用显示指定类型时，可以进行隐式类型转换 add<int>(int, double)
- 当普通函数和模版函数同名时，优先调用普通函数，当显示指定类型，或者添加<>可以强制调用函数模版，例如：add<>
- 需要发生隐式类型转换时，优先使用模版，发生隐式转换时，普通函数不是最优先匹配



```c++
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

template <typename T1, typename T2> T2 add2(T1 a, T2 b) { return a + b; } //多参数

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
  double xx = add2(1, 1.1);
  cout << xx << endl;

  return 0;
}
```



#### 类模版

**类模版定义**：

```c++
类模板
template <class T>         //class替换为typename也可
class 类名{
};
```

**注意事项**:

- 类模板实例化时，必须显示指定类型
- 类模板的成员函数，在调用时才会生成；

```c++
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
```



#### 模版特化

C++ 中的**模板特化（Template Specialization）** 是泛型编程的重要补充，允许为特定类型或特定参数组合定制模板的实现。当通用模板无法满足某些类型的特殊需求时，特化机制能提供更精准、高效或正确的实现。

**模板特化的分类**

模板特化分为**函数模板特化**和**类模板特化**，每种又可细分为**全特化**和**偏特化**（类模板专属）。

1. 函数模板特化（仅支持全特化）

函数模板特化是为**特定类型**完全重写模板函数的实现，语法如下：

```cpp
// 通用模板
template <typename T>
返回类型 函数名(参数列表) {
    // 通用实现
}

// 全特化：为特定类型T=Type定制实现
template <>
返回类型 函数名<Type>(参数列表) {
    // 针对Type的特化实现
}
```

**示例**：为字符串指针特化比较函数
```cpp
#include <cstring>
#include <iostream>
using namespace std;

// 通用模板：比较两个值
template <typename T>
bool isEqual(T a, T b) {
    return a == b; // 对指针会比较地址（非内容）
}

// 全特化：针对const char*（字符串）
template <>
bool isEqual<const char*>(const char* a, const char* b) {
    return strcmp(a, b) == 0; // 比较字符串内容
}

int main() {
    cout << isEqual(5, 5) << endl;               // 1（正确）
    cout << isEqual("hello", "hello") << endl;   // 1（特化后正确比较内容）
    return 0;
}
```

2. 类模板特化

类模板特化更灵活，支持**全特化**和**偏特化**（部分参数固定）。

（1）类模板全特化

为**所有模板参数**指定具体类型，完全重写类的实现：

```cpp
// 通用类模板
template <typename T1, typename T2>
class MyClass {
public:
    void print() { cout << "通用版本" << endl; }
};

// 全特化：T1=int, T2=double
template <>
class MyClass<int, double> {
public:
    void print() { cout << "特化版本：int, double" << endl; }
};

// 使用
MyClass<char, float> obj1;
obj1.print(); // 输出：通用版本

MyClass<int, double> obj2;
obj2.print(); // 输出：特化版本：int, double
```

（2）类模板偏特化

只固定**部分模板参数**，其余仍保持泛型（仅类模板支持）：

```cpp
// 通用模板：两个类型参数
template <typename T1, typename T2>
class Pair {
public:
    void show() { cout << "通用 Pair: T1, T2" << endl; }
};

// 偏特化1：固定T2为int
template <typename T1>
class Pair<T1, int> {
public:
    void show() { cout << "偏特化: T1, int" << endl; }
};

// 偏特化2：两个参数都为指针类型
template <typename T1, typename T2>
class Pair<T1*, T2*> {
public:
    void show() { cout << "偏特化: T1*, T2*" << endl; }
};

// 使用
Pair<double, string> p1;  // 通用版本
p1.show();

Pair<string, int> p2;     // 偏特化1
p2.show();

Pair<int*, double*> p3;   // 偏特化2
p3.show();
```

模板特化的核心意义

1. **处理特殊类型**：通用模板逻辑可能对某些类型（如指针、bool、自定义类）不适用，特化可修正行为。
2. **性能优化**：为高频使用的类型（如int、double）提供更高效的实现（如用快速排序替代通用排序）。
3. **语义适配**：针对类型特性定制逻辑（如`std::vector<bool>`特化为位存储，节省空间）。

注意事项

- **函数模板不支持偏特化**：若需类似功能，可通过函数重载替代。
- **特化版本需独立实现**：特化类/函数的成员需重新定义，不继承通用模板的实现。
- **特化优先级**：编译器会优先选择最匹配的特化版本，其次是通用模板。


模板特化是C++泛型编程的“灵活调节阀”，既保持了通用模板的复用性，又能为特殊场景提供精准控制，是标准库（如STL）实现高效、通用功能的核心技术之一。


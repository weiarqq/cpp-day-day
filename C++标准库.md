C++标准库是C++语言官方定义的一套功能丰富的代码集合，它封装了基础数据结构、算法、输入输出、内存管理等核心功能，目的是让开发者避免重复造轮子，同时保证代码的可移植性和效率。

C++标准库的内容非常庞大，通常可分为**三大核心部分**：

- 标准模板库（STL）
- C标准库兼容部分
- C++特有的扩展库（如字符串、智能指针、正则等）


### STL
STL是C++标准库的灵魂，基于模板（Template）实现，支持泛型编程，核心是“数据结构+算法”的分离设计，主要包含以下5个组件：

#### 容器(Containers)

容器是用于存放数据的类模板，按功能分为**序列容器**、**关联容器**、**无序关联容器**和**适配器容器**四类，不同容器对应不同的数据结构，适用场景差异极大。

| 容器类型         | 具体容器                               | 底层数据结构         | 核心特点                                                     | 适用场景                                           |
| ---------------- | -------------------------------------- | -------------------- | ------------------------------------------------------------ | -------------------------------------------------- |
| **序列容器**     | `vector`                             | 动态数组             | 随机访问快，尾部插入/删除快，单一连续内存块                  | 频繁读取、尾部操作（如存储列表数据）               |
|                  | `deque`                                | 分段动态数组         | 首尾插入/删除快，支持随机访问，非单一连续内存块，而是由**多个固定大小的内存块**组成： | 是一种双端队列容器，支持在两端高效插入和删除操作。 |
|                  | `array`                                | 固定大小数组         | 栈上存储，随机访问快，大小编译期确定                         | 存储固定长度数据（如坐标(x,y,z)）                  |
|                  | `list`                                 | 双向链表             | 任意位置插入/删除快，不支持随机访问                          | 频繁插入/删除（如实现队列、链表）                  |
|                  | `forward_list`                         | 单向链表             | 内存占用小，仅支持单向遍历                                   | 内存敏感、仅需单向访问的场景                       |
| **关联容器**     | `set` / `multiset`                     | 红黑树               | 元素有序，`set`去重，`multiset`允许重复                      | 需有序存储且去重/允许重复（如排序的ID列表）        |
|                  | `map` / `multimap`                     | 红黑树               | 键值对有序，`map`键唯一，`multimap`允许重复                  | 需通过键快速查找值（如字典、配置表）               |
| **无序关联容器** | `unordered_set` / `unordered_multiset` | 哈希表               | 元素无序，查找/插入/删除平均O(1)                             | 无需排序、追求快速查找（如判重）                   |
|                  | `unordered_map` / `unordered_multimap` | 哈希表               | 键值对无序，查找/插入/删除平均O(1)                           | 高频查找键值对（如缓存、计数统计）                 |
| **适配器容器**   | `stack`                                | 基于`deque`/`vector` | 后进先出（LIFO），仅能访问栈顶                               | 实现栈操作（如表达式求值、递归替代）               |
|                  | `queue`                                | 基于`deque`/`list`   | 先进先出（FIFO），仅能访问队首/队尾                          | 实现队列操作（如任务排队）                         |
|                  | `priority_queue`                       | 基于`vector`         | 优先级最高的元素先出（大根堆默认）                           | 实现优先任务调度（如TOP-K问题）                    |

#### 算法(Algorithms)

STL算法是一组通用函数模板，不依赖具体容器，通过迭代器（见下文）操作容器中的数据，涵盖排序、查找、修改、遍历等常见操作，定义在 `<algorithm>` 头文件中。

常用算法可分为以下几类：
| 算法            | 类别         | 说明                         | 示例                                           |
| --------------- | ------------ | ---------------------------- | ---------------------------------------------- |
| `find`          | **查找算法** | 查找元素                     | `auto it = find(v.begin(), v.end(), 5);`       |
| `binary_search` | **查找算法** | 二分查找（要求容器有序）     |                                                |
| `count`         | **查找算法** | 统计元素个数                 |                                                |
| `sort`          | **排序算法** | 快速排序变体（平均O(nlogn)） | `sort(v.begin(), v.end());`（默认升序）        |
| `stable_sort`   | **排序算法** | 稳定排序                     |                                                |
| `reverse`       | **排序算法** | 反转元素                     |                                                |
| `copy`          | **修改算法** | 复制元素                     |                                                |
| `swap`          | **修改算法** | 交换两个元素                 |                                                |
| `replace`       | **修改算法** | 替换元素                     |                                                |
| `remove`        | **修改算法** | 删除元素                     |                                                |
| `accumulate`    | **数值算法** | 累加（需`<numeric>`头文件）  | `int sum = accumulate(v.begin(), v.end(), 0);` |
| `inner_product` | **数值算法** | 内积                         |                                                |



#### 迭代器(Iterators)

迭代器是一种“行为类似指针”的对象，用于遍历容器中的元素，它屏蔽了不同容器的底层差异，让算法可以统一操作任意容器。

迭代器按功能强弱分为5类，常用的是前3类：
1. **输入迭代器**：仅支持“读”和“单向移动”（如`istream_iterator`，从输入流读数据）。
2. **输出迭代器**：仅支持“写”和“单向移动”（如`ostream_iterator`，向输出流写数据）。
3. **前向迭代器**：支持“读写”和“单向移动”（如`forward_list`的迭代器）。
4. **双向迭代器**：支持“读写”和“双向移动”（如`list`、`map`的迭代器）。
5. **随机访问迭代器**：支持“读写”、“双向移动”和“随机访问”（如`vector`、`deque`的迭代器，可直接用`+/-`偏移，类似指针）。

**使用示例**：用迭代器遍历`vector`
```cpp
vector<int> v = {1,2,3,4};
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " "; // 解引用迭代器，获取元素
}
// 输出：1 2 3 4
```


#### 函数对象(Functors)
函数对象是重载了`()`运算符的类或结构体，它可以像普通函数一样被调用，同时还能存储状态（比普通函数更灵活）。STL中常用作算法的“比较函数”或“操作函数”。

- 示例1：自定义函数对象（比较大小）
  ```cpp
  struct MyCompare {
      bool operator()(int a, int b) {
          return a > b; // 降序比较
      }
  };
  // 用自定义函数对象排序
  vector<int> v = {3,1,4,2};
  sort(v.begin(), v.end(), MyCompare()); 
  // 排序后：4 3 2 1
  ```

- 示例2：STL内置函数对象（定义在`<functional>`头文件）
  - `less<T>()`：默认比较（a < b）
  - `greater<T>()`：大于比较（a > b）
  - `plus<T>()`：加法（a + b）
  ```cpp
  // 用内置greater排序（降序）
  sort(v.begin(), v.end(), greater<int>());
  ```


#### 分配器(Allocators)
分配器是STL容器的“内存管理模块”，负责容器的内存分配与释放，默认情况下容器会使用`std::allocator`，但开发者也可自定义分配器（如实现内存池，优化频繁内存申请的性能）。

通常开发者无需直接操作分配器，容器会自动调用，例如`vector<int>`的默认内存管理就是由`allocator<int>`完成的。

自定义Allocators

```c++
template<typename T>
class MyAllocator {
public:
    using value_type = T;
    
    MyAllocator() = default;
    
    template<typename U>
    MyAllocator(const MyAllocator<U>&) {}
    
    T* allocate(std::size_t n) {
        std::cout << "Allocating " << n << " elements\n";
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }
    
    void deallocate(T* p, std::size_t n) {
        std::cout << "Deallocating " << n << " elements\n";
        ::operator delete(p);
    }
};

// 使用自定义分配器的 vector
std::vector<int, MyAllocator<int>> v;

// vector模版 _Allocator 设置了默认类型
template <class _Tp, class _Allocator = std::allocator<T>>
class vector : private __vector_base<_Tp, _Allocator> {
    // ...
};
// 创建vector时
std::vector<int> vec // 等价于 std::vector<int, std::allocator<int>> vec 

v.push_back(1);
v.push_back(2);
```




### C标准库兼容部分
C++兼容了几乎所有C标准库（如`<stdio.h>`、`<stdlib.h>`），但在C++中推荐使用带`c`前缀且无`.h`后缀的头文件（如`<cstdio>`、`<cstdlib>`），这些头文件中的内容位于`std`命名空间下，避免全局命名污染。

常用的C兼容库包括：
- **输入输出**：`<cstdio>`（`printf`、`scanf`）
- **字符串操作**：`<cstring>`（`strlen`、`strcpy`，注意：C++更推荐用`std::string`）
- **数值计算**：`<cmath>`（`sin`、`cos`、`sqrt`）
- **内存管理**：`<cstdlib>`（`malloc`、`free`，C++更推荐用`new`/`delete`或智能指针）
- **时间处理**：`<ctime>`（`time`、`clock`）


### C++特有的扩展库
除了STL和C兼容库，C++标准库还包含许多针对C++特性设计的扩展模块，这些是C语言没有的。

#### 字符串处理(std::string)

> 定义在<string>

`std::string`是C++封装的字符串类，比C语言的`char*`更安全、易用，支持自动内存管理、字符串拼接、查找、替换等操作。

常用操作示例：
```cpp
string s1 = "Hello";
string s2 = "World";
string s3 = s1 + " " + s2; // 拼接："Hello World"
cout << s3.size(); // 输出长度：11
cout << s3.substr(0, 5); // 截取子串（从0开始，5个字符）："Hello"
if (s1 == s2) { ... } // 直接用==比较，无需strcmp
```

#### 输入输出流(IO Streams)

> 定义在`<iostream>`、`<fstream>`等

C++的IO流库用面向对象的方式封装了输入输出，核心是`istream`（输入流，如`cin`）和`ostream`（输出流，如`cout`），支持格式化和非格式化IO。

- 常用流对象：
  - `cin`：标准输入流（对应键盘）
  - `cout`：标准输出流（对应屏幕）
  - `cerr`：标准错误流（无缓冲，直接输出错误）
  - `fstream`：文件流（读写文件）

- 示例：文件读写
  ```cpp
  // 写文件
  ofstream ofs("test.txt");
  ofs << "Hello C++ IO Stream";
  ofs.close();
  
  // 读文件
  ifstream ifs("test.txt");
  string content;
  ifs >> content; // 读入字符串（空格分隔）
  cout << content; // 输出："Hello"
  ifs.close();
  ```

#### 智能指针(Smart Pointers)

> C++11新增，定义在`<memory>`

智能指针是封装了原始指针的类模板，能自动管理内存（离开作用域时自动释放），从根本上避免“内存泄漏”问题，是C++推荐的内存管理方式（替代`new`/`delete`手动管理）。

常用智能指针有3种：
- **`unique_ptr`**：独占所有权的智能指针，同一时间只能有一个`unique_ptr`指向同一对象，不支持拷贝（防止浅拷贝问题）。
  ```cpp
  unique_ptr<int> p1 = make_unique<int>(10); // 推荐用make_unique创建（C++14）
  // unique_ptr<int> p2 = p1; // 错误：不支持拷贝
  unique_ptr<int> p2 = move(p1); // 正确：用move转移所有权（p1此后为空）
  ```

- **`shared_ptr`**：共享所有权的智能指针，多个`shared_ptr`可指向同一对象，内部用“引用计数”跟踪引用次数，当计数为0时自动释放内存。
  ```cpp
  shared_ptr<int> p1 = make_shared<int>(20); // 推荐用make_shared创建
  shared_ptr<int> p2 = p1; // 正确：引用计数变为2
  cout << p1.use_count(); // 输出：2（查看引用计数）
  ```

- **`weak_ptr`**：弱引用智能指针，不增加引用计数，用于解决`shared_ptr`的“循环引用”问题（如两个`shared_ptr`互相指向，导致计数无法归零）。

  ```c++
  std::shared_ptr<Obj> sp4_shared = std::make_shared<Obj>(5, 6);
  std::weak_ptr<Obj> sp4 = sp4_shared; // weak_ptr不影响引用计数
  ```

  



#### 其他常用扩展库
- **正则表达式（Regex，C++11新增，`<regex>`）**：支持正则匹配、替换，如验证邮箱格式、提取字符串中的数字。

  ```c++
  
  #include <iostream>
  #include <regex>
  
  int main() {
      std::string regx_str = "hello world 123 hello 456";
      std::regex regex_pattern("\\d+");
      // 匹配
      if (std::regex_match(regx_str, regex_pattern)) {
          std::cout << "match" << '\n';
      }
      // 查找是否存在
      if (std::regex_search(regx_str, regex_pattern)) {
          std::cout << "search match" << '\n';
      }
  
      // 遍历所有匹配项
      std::regex_iterator<std::string::const_iterator> iter(
          regx_str.begin(), regx_str.end(), regex_pattern);
      std::regex_iterator<std::string::const_iterator> end;
      for (; iter != end; iter++) {
          std::cout << iter->str() << " ";
      }
      std::cout << '\n';
  
      // 替换
      std::string replace_str =
          std::regex_replace(regx_str, regex_pattern, "###");
      std::cout << replace_str << '\n';
  }
  ```

- **线程库（Threads，C++11新增，`<thread>`）**：跨平台的多线程支持，包括`thread`（线程对象）、`mutex`（互斥锁）、`condition_variable`（条件变量）等，解决多线程同步问题。
- **日期时间库（Chrono，C++11新增，`<chrono>`）**：用于时间的获取、计算和转换，如计算程序运行时间。
  ```cpp
  auto start = chrono::high_resolution_clock::now();
  // 执行耗时操作...
  
  std::this_thread::sleep_for(std::chrono::seconds(2));
  auto end = chrono::high_resolution_clock::now();
  // 计算耗时（毫秒）
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
  cout << "耗时：" << duration << "ms";
  ```





### 标准库的使用原则

1. **优先使用标准库，而非自定义实现**：标准库经过严格测试，效率高、稳定性强，且可移植（不同编译器/平台下行为一致）。
2. **理解容器的底层实现，选对容器**：例如“频繁查找”选`unordered_map`，“需要有序”选`map`，“尾部操作多”选`vector`。
3. **避免使用过期特性**：如`auto_ptr`（C++11已废弃，用`unique_ptr`替代）、`bind2nd`（用`bind`替代）。
4. **注意命名空间**：标准库的所有内容都在`std`命名空间下，使用时需加`std::`（如`std::vector`），或通过`using namespace std;`省略（但大型项目不推荐，避免命名冲突）。



### C++多线程

#### 线程管理 (`std::thread`)

| 函数/类成员                        | 说明                                   | 示例                                                    |
| ---------------------------------- | -------------------------------------- | ------------------------------------------------------- |
| **`std::thread t(func, args...)`** | 创建线程对象并执行函数 `func(args...)` | `std::thread t(foo, 42);`                               |
| **`join()`**                         | 阻塞等待线程完成，等待启动的线程完成，才会继续往下执行。   | `t.join();`                                            |
| **`detach()`**                    | 线程分离，不再由当前线程管理，若主线程结束，则程序结束，不等待detach线程结束 | `t.detach();`                                           |
| `t.joinable()`                     | 判断一个线程是否可 join()/detach() | `if (t.joinable())`                                     |
| `std::this_thread::sleep_for(dur)` | 让当前线程休眠一段时间                 | `std::this_thread::sleep_for(std::chrono::seconds(1));` |
| `std::this_thread::yield()`        | 主动让出 CPU 时间片                    | `std::this_thread::yield();`                            |
| `std::this_thread::get_id()`       | 获取当前线程 ID                        | `auto id = std::this_thread::get_id();`                 |

---

#### 互斥锁与同步 (`std::mutex` 系列)

| 函数/类                        | 说明                                 | 示例                                                       |
| ------------------------------ | ------------------------------------ | ---------------------------------------------------------- |
| **`std::mutex` **                  | 基本互斥锁，不可递归                 | `std::mutex mtx; mtx.lock(); mtx.unlock();`                |
| **`std::lock_guard<std::mutex>`**  | RAII 风格自动加锁/解锁               | `std::lock_guard<std::mutex> lock(mtx);`                   |
| **`std::unique_lock<std::mutex>`** | 更灵活的 RAII 锁，支持延迟锁、超时等 | `std::unique_lock<std::mutex> lock(mtx, std::defer_lock);` |
| `std::recursive_mutex`         | 可递归互斥锁                         | `std::recursive_mutex rmtx;`                               |
| `std::try_lock(mtx1, mtx2...)` | 尝试同时锁定多个锁，避免死锁         | `std::try_lock(mtx1, mtx2);`                               |
| `std::lock(mtx1, mtx2...)`     | 锁定多个锁，内部避免死锁             | `std::lock(mtx1, mtx2);`                                   |

---

#### 条件变量 (`std::condition_variable`)

| 函数                       | 说明               | 示例                                  |
| -------------------------- | ------------------ | ------------------------------------- |
| **`cv.wait(lock)`**            | 等待条件变量被唤醒 | `cv.wait(lock);`                      |
| **`cv.wait(lock, predicate)`** | 等待直到条件成立   | `cv.wait(lock, []{ return ready; });` |
| **`cv.notify_one()`**          | 唤醒一个等待线程   | `cv.notify_one();`                    |
| **`cv.notify_all()`**        | 唤醒所有等待线程   | `cv.notify_all();`                    |

---

#### 原子操作 (`std::atomic`)

| 操作             | 说明               | 示例                         |
| ---------------- | ------------------ | ---------------------------- |
| **`std::atomic<T>`** | 原子类型模板       | `std::atomic<int> count{0};` |
| `fetch_add(n)`   | 原子加法，返回旧值 | `count.fetch_add(1);`        |
| `fetch_sub(n)`   | 原子减法           | `count.fetch_sub(1);`        |
| `operator++()`   | 前置自增           | `++count;`                   |
| `operator--()`   | 前置自减           | `--count;`                   |
| `load()`         | 原子读取           | `int v = count.load();`      |
| `store(v)`       | 原子写入           | `count.store(42);`           |
| `exchange(v)`    | 原子交换           | `count.exchange(0);`         |

---

#### 异步任务 (`std::async`, `std::future`)

| 函数/类                                             | 说明                 | 示例                                                  |
| --------------------------------------------------- | -------------------- | ----------------------------------------------------- |
| **`std::async(std::launch::async, func, args...)`** | 异步执行任务         | `auto fut = std::async(std::launch::async, foo, 42);` |
| **`std::future<T>`**                                | 存储异步结果         | `int res = fut.get();`                                |
| **`std::shared_future<T>`**                         | 可多次 get 的 future | `std::shared_future<int> sf = fut.share();`           |
| `fut.wait()`                                        | 等待结果可用         | `fut.wait();`                                         |
| `fut.wait_for(dur)`                                 | 超时等待             | `fut.wait_for(std::chrono::milliseconds(100));`       |

---

#### 其他并发工具

| 工具                             | 说明                        | 示例                                                         |
| -------------------------------- | --------------------------- | ------------------------------------------------------------ |
| **`std::packaged_task<R(Args...)>`** | 包装可调用对象，生成 future | `std::packaged_task<int()> task(foo);`                       |
| **`std::promise<T>`**                | 承诺在未来提供一个值        | `std::promise<int> prom; auto fut = prom.get_future();`      |
| `std::call_once`                 | 确保某段代码只执行一次      | `std::once_flag flag; std::call_once(flag, init);`           |
| `std::timed_mutex`               | 带超时的互斥锁              | `std::timed_mutex tmtx; tmtx.try_lock_for(std::chrono::seconds(1));` |


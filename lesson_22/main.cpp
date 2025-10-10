// STL 容器
#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main() {

    // vector 初始化
    // std::vector<std::string> word1({"hello", "world", "nihao"});
    std::vector<std::string> word1{"hello", "world", "nihao"};
    std::vector<std::string> word2(word1.begin(), word1.end());
    std::vector<std::string> word3(word1);
    constexpr int kExpandSize = 10;
    std::vector<std::string> word4(kExpandSize, "hello");

    // vector遍历
    for (auto iter = word4.begin(); iter != word4.end(); iter++) {
        std::cout << *iter << " ";
    }
    for (auto& iter : word4) {
        std::cout << iter << " ";
    }

    // vector 访问元素
    std::cout << word1[0] << '\n';
    std::cout << word1.at(0) << '\n'; // 下标越界检测

    std::cout << word1.front() << '\n'; // 第一个元素
    std::cout << word1.back() << '\n';  // 最后一个元素

    std::cout << word1.data() << '\n'; // 返回指向首元素的指针
    // word1.begin() word1.end() 为迭代器对象
    std::cout << *word1.begin() << '\n';     // 输出首元素的值,
    std::cout << *(word1.end() - 1) << '\n'; // end指向最后一个元素的下一个位置

    std::cout << *word1.rbegin() << '\n';     // 输出最后一个元素的值
    std::cout << *(word1.rend() - 1) << '\n'; // rend指向第一个元素的前一个位置

    if (!word1.empty()) { // 判断vector是否为空
        std::cout << "word1 not empty" << '\n';
    }

    word1.insert(word1.begin() + 2, ","); // 在指定位置插入元素
    for (auto& iter : word1) {
        std::cout << iter << " ";
    }
    std::cout << '\n';

    std::cout << word3.size() << '\n';     // 当前元素个数
    std::cout << word3.max_size() << '\n'; // vector能容纳的最大元素个数
    std::cout << word3.capacity() << '\n'; // 当前分配的内存空间
    word1.reserve(10);                     // 自定义分配内存空间
    std::cout << word3.capacity() << '\n';

    word1.clear(); // 清空元素 但不释放内存
    std::cout << word3.size() << '\n';
    std::cout << word3.capacity() << '\n'; // 容量不变 10

    word1 = {"hello", "world", "nihao"};
    word1.erase(word1.end() - 1); // 删除指定位置元素

    for (auto& iter : word1) {
        std::cout << iter << " ";
    }

    word1.push_back(std::string("c++")); // 先构造临时string，再移动
    word1.emplace_back("c++");           // 直接用"c++"构造，无临时对象
    word1.pop_back();                    // 删除最后一个元素
    word1.resize(5);                     // 扩展到5个元素，默认值初始化
    std::vector<std::string> tmp_v;
    word1.swap(tmp_v);
    std::cout << "tmp_v size: " << tmp_v.size() << '\n';
    std::cout << "word1 size: " << word1.size() << '\n';
    std::vector<std::string>().swap(tmp_v); // 清空vector并释放内存
    std::cout << "tmp_v size: " << tmp_v.size() << '\n';

    std::deque<int> deque = {1, 2, 3, 4, 5};

    deque.push_front(0); // 前端插入元素
    deque.push_back(6);
    for (auto& iter : deque) {
        std::cout << iter << " "; // 0 1 2 3 4 5 6
    }
    std::cout << '\n';

    deque.emplace_front(-1); // 前端直接构造元素
    deque.emplace_back(7);
    for (auto& iter : deque) {
        std::cout << iter << " "; // 0 1 2 3 4 5 6
    }

    std::cout << '\n';

    std::array<int, 5> array = {1, 2, 3, 4, 5}; // 固定大小内存
    for (auto& iter : array) {
        std::cout << iter << " ";
    }
    std::cout << '\n';
    std::list<int> list = {1, 2, 3, 4, 5};
    list.push_back(6);  // 链表尾部添加元素
    list.push_front(0); // 链表头部添加元素
    for (auto& item : list) {
        std::cout << item << " ";
    }
    std::cout << '\n';

    std::list<int> list1 = {2, 4, 7};
    std::list<int> list2 = {1, 3, 9};
    list1.merge(list2); // 合并两个有序链表
    for (auto& iter : list1) {
        std::cout << iter << " ";
    }

    std::cout << '\n';
    std::list<int> list3 = {1, 2, 3, 4, 5};
    list3.splice(list3.begin(), list2); // 在指定位置插入另一个链表
    for (auto& iter : list3) {
        std::cout << iter << " ";
    }
    std::cout << '\n';

    list3.remove(3); // 删除指定元素
    for (auto& iter : list3) {
        std::cout << iter << " ";
    }
    std::cout << '\n';

    list3.reverse(); // 反转链表
    for (auto& iter : list3) {
        std::cout << iter << " ";
    }
    std::cout << '\n';

    list3.sort(); // 链表排序
    for (auto& iter : list3) {
        std::cout << iter << " ";
    }
    std::cout << '\n';

    std::list<int> list4 = {1, 1, 1, 2, 2, 2};
    list4.unique();
    for (auto& iter : list4) {
        std::cout << iter << " ";
    }
    std::cout << '\n';

    std::forward_list<int> forward_list = {1, 2, 4, 5};
    forward_list.insert_after(std::next(forward_list.begin(), 1),
                              3); // 使用std::next获取下一个迭代器
    for (auto& iter : forward_list) {
        std::cout << iter << " ";
    }
    std::cout << '\n';
    auto item_before =
        forward_list
            .before_begin(); //  返回前置迭代器
                             //  forward_list链表最开始位置是虚拟节点，before_begin()返回的就是这个虚拟节点
    auto iter_forward =
        forward_list
            .begin(); // begin()返回第一个元素的位置，但不是链表的开始位置
    std::cout << *(++item_before) << '\n'; //
    std::cout << *iter_forward << '\n';

    // 关联容器
    std::set<int> set = {1, 2, 3, 4, 5};
    set.insert(3); // 插入元素，set会自动去重

    std::multiset<int> multiset;

    std::unordered_set<int> un_set;

    std::unordered_multiset<int> unordered_multiset;

    std::map<int, std::string> map = {{1, "hello"}, {2, "world"}};
    // map 遍历
    for (auto& pair : map) {
        std::cout << pair.first << " : " << pair.second << '\n';
    }
    map[3] = "nihao"; // 插入元素
    map.insert({4, "c++"});
    if (map.find(2) != map.end()) {
        std::cout << "find key 2" << '\n';
    }
    if (map.count(2) > 0) {
        std::cout << "count key 2" << '\n';
    }
    std::string value = map[2];
    std::cout << "value: " << value << '\n'; // value为空字符串

    std::multimap<int, std::string> multimap;

    std::unordered_map<int, std::string> un_map;

    std::unordered_multimap<int, std::string> unordered_multimap;

    // 适配器容器
    std::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.pop();

    std::queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.pop();

    std::priority_queue<int> pri_que;
    pri_que.push(3);
    pri_que.push(1);
    pri_que.push(2);
    pri_que.pop(); // 弹出堆顶元素
};
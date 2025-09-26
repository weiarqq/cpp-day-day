// STL 容器
#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void printVector(vector<int>& v) {
    for (vector<int>::iterator iter = v.begin(); iter < v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {

    // 序列容器
    std::vector<int> vector; // 动态数组 数组大小可动态调整，连续内存数组

    std::list<int> list;

    std::deque<int> deque;

    std::array<int, 5> array;

    std::forward_list<int> forward_list;

    // 关联容器
    std::set<int> set;

    std::multiset<int> multiset;

    std::unordered_set<int> un_set;

    std::unordered_multiset<int> unordered_multiset;

    std::map<int, string> map;

    std::multimap<int, string> multimap;

    std::unordered_map<int, string> un_map;

    std::unordered_multimap<int, string> unordered_multimap;

    // 适配器容器
    std::stack<int> stack;

    std::queue<int> queue;

    std::priority_queue<int> pri_que;

    return 0;
};
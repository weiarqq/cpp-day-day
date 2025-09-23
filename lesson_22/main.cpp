#include <deque>
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
    // std::vector veci = {1, 2, 3, 4, 5};
    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(0);
    int a = vec.at(0);

    // vector<int> v3(v);
    // vector<int> v4(v.begin(), v.end());
    // vector<int> v5(0);
    // vector<int> v6(0, 8);

    // cout << "begin->" << *v.begin() << endl;   // 迭代器取首位指针
    // cout << "end->" << *(v.end() - 1) << endl; // 迭代器取末尾指针

    // cout << "front:" << v.front() << endl; // 取首位
    // cout << "back:" << v.back() << endl;   // 取末尾
    // printVector(v);

    std::string str;

    std::deque<int> deq;

    std::stack<int> sta;

    std::queue<int> que;

    std::list<int> list;

    std::set<int> set;

    std::map<int, string> map;

    std::priority_queue<int> pri_que;

    std::unordered_set<int> un_set;

    std::unordered_map<int, string> un_map;

    return 0;
};
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>

template <typename T> void print_vector(const std::vector<T>& vec) {
    for (auto& iter : vec) {
        std::cout << iter << " ";
    }
    std::cout << '\n';
}
int main() {
    std::vector<int> num_vector = {1, 2, 3, 4, 5, 2, -1, 0};
    // 全部元素是否满足条件
    bool is_right = std::all_of(num_vector.begin(), num_vector.end(),
                                [](int x) { return x > 0; });
    // 是否有任意元素满足条件
    bool is_any = std::any_of(num_vector.begin(), num_vector.end(),
                              [](int x) { return x > 3; });
    std::cout << std::boolalpha << is_right << '\n';
    std::cout << std::boolalpha << is_any << '\n';
    std::vector<std::string> str_vector = {"A", "B", "C", "D", "D"};
    if (std::find(str_vector.begin(), str_vector.end(), "C") !=
        str_vector.end()) {
        std::cout << "find C" << '\n';
    }
    int count = std::count(str_vector.begin(), str_vector.end(), "D");
    std::cout << "count D: " << count << '\n';

    std::sort(num_vector.begin(), num_vector.end(),
              [](int a, int b) { return a >= b; });
    print_vector(num_vector);
    std::reverse(num_vector.begin(), num_vector.end());
    print_vector(num_vector);

    std::vector<std::string> str_vector2 = {"A", "B", "C", "D", "D"};
    std::vector<std::string> str_vector3 = {"AA", "BB", "CC", "D", "E"};
    std::swap(str_vector2, str_vector3);
    print_vector(str_vector3);

    std::vector<int> vec_replace = {1, 2, 3, 4, 5, 2, -1, 0};

    std::replace(vec_replace.begin(), vec_replace.end(), -1, 0);
    print_vector(vec_replace);

    auto ed = std::remove(vec_replace.begin(), vec_replace.end(), 0);
    print_vector(vec_replace);
    int sum = std::accumulate(vec_replace.begin(), vec_replace.end(), 0);
    std::cout << "sum: " << sum << '\n';

    std::vector<int> a{1, 2, 3, 4, 5};
    std::vector<int> b{6, 7, 8, 9, 10};
    int res = std::inner_product(a.begin(), a.end(), b.begin(), 0);
    std::cout << "res: " << res << '\n';
}
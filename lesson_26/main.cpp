
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
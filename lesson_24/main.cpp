#include <fstream>
#include <iostream>
#include <iterator>

int main() {
    std::ifstream ifs("./test.txt");
    // 按行读取
    // std::string content;
    // while (getline(ifs, content)) {
    //     std::cout << content << '\n';
    // }
    // 全文读取
    // istreambuf_iterator<char>(fin) 创建一个迭代器，它会逐个读取 fin
    // 的缓冲区中的字符。 istreambuf_iterator<char>()
    // 这是一个**“结束迭代器”**（空构造），表示流的末尾。
    std::string all_content((std::istreambuf_iterator<char>(ifs)),
                            std::istreambuf_iterator<char>());
    std::cout << all_content << '\n';

    std::ofstream ofs("./test_out.txt", std::ios::app); // ios::app 追加写入
    ofs << "file write test" << '\n';
    ofs.close();
}
#include <functional>
#include <future>
#include <iostream>
#include <thread>



auto func = [](const char* msg, int i){ // 常量引用：
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << msg << '\n';
    return "task"+std::to_string(i);
};



int main(){
    auto res1 = std::async(func, "task-one", 1);
    auto res2 = std::async(func, "task-two", 2);

    std::cout << res1.get() << '\n';
    std::cout << res2.get() << '\n';
}

#include <iostream>
#include <thread>
#include <future>
#include <functional>
// #include <promise>

auto func = [](std::future<std::string>& fut){
    std::string x = fut.get();
    std::cout << "获取"<< x << '\n';
};


int main(){
    std::promise<std::string> prom;
    std::future<std::string> fut = prom.get_future();
    std::thread t(func, std::ref(fut));
    prom.set_value("MC");
    t.join();

}
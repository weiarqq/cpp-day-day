
#include <functional>
#include <future>
#include <iostream>
#include <thread>
#include <string>

auto func = [](int a, int b){
    return std::to_string(a+b);
};

int main(){
    std::packaged_task<std::string(int, int)> task(func); //std::packaged_task<R(Args...)>  R：任务的返回类型  Args...：任务的参数类型列表
    std::future<std::string> fut = task.get_future();
    // 转换为 shared_future 
    std::shared_future<std::string> shared_fut = fut.share(); // 可复制future std::future 只可get一次

    std::thread t(std::move(task), 1, 2); // std::packaged_task 是只可移动（move-only）类型，不能复制 需要使用std::move
    t.join();
    // std::cout << fut.get() << '\n';
    // std::cout << fut.get() << '\n';
    std::cout << shared_fut.get() << '\n';
    std::cout << shared_fut.get() << '\n';
}
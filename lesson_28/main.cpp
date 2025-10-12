#include <chrono>
#include <iostream>
#include <thread>

auto func = [](const char* args, int s = 0) {
    std::cout << "[" << args << "] "
              << "this thread id:" << std::this_thread::get_id() << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(s));
};

void test_join() {
    func("主线程", 2);
    std::thread thread1(func, "线程1", 3);
    std::thread thread2(func, "线程2", 3);
    // if (t1.joinable()) {
    //     std::cout << "Main thread: t1 is joinable." << '\n';
    // }
    // t1.joinable() 判断一个线程是否可 join()/detach()
    std::cout << "thread1 thread statues joinable is " << thread1.joinable()
              << '\n';
    if (thread1.joinable()) {
        thread1.join();
    }
    thread2.join();
    std::cout << "thread2 thread statues joinable is " << thread2.joinable()
              << '\n';
}

void test_detach() {
    func("主线A");
    std::thread thread1(func, "线程1", 3);
    std::thread thread2(func, "线程2", 3);
    std::cout << "thread1 thread statues joinable is " << thread1.joinable()
              << '\n'; // true 还未detach()
    std::cout << "thread2 thread statues joinable is " << thread2.joinable()
              << '\n'; // false 已被detach()
    thread1.detach();
    thread2.detach();
    // detach 之后 主线程不等待子线程结束,相当于后台线程
    // 如果主线程运行结束，程序则结束。所以我们这里让主线程睡眠10秒
    std::this_thread::sleep_for(std::chrono::seconds(10));
}

int main() {

    auto start = std::chrono::high_resolution_clock::now();
    test_join();
    // test_detach();
    auto end = std::chrono::high_resolution_clock::now();
    int cost_time =
        std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    std::cout << "Main thread: all threads joined. cost senconds:" << cost_time
              << "s" << '\n';

    return 0;
}
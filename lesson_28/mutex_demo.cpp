#include <algorithm>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::timed_mutex tmtx;

auto func = [](const char* args, int num = 0) {
    std::cout << args << " thread id:" << std::this_thread::get_id() << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(3));
    mtx.lock();
    for (int i = 0; i < num; i++) {
        std::cout << "[" << args << "]" << "thread num: " << i << '\n';
    }
    mtx.unlock();
};
auto func_time_mutex = [](const char* args, int num = 0) {
    std::cout << args << " thread id:" << std::this_thread::get_id() << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(3));
    tmtx.try_lock_for(std::chrono::milliseconds(20));
    for (int i = 0; i < num; i++) {
        std::cout << "[" << args << "]" << "thread num: " << i << '\n';
    }
    tmtx.unlock();
};

auto func_lock = [](const char* args, int num = 0) {
    std::cout << args << " thread id:" << std::this_thread::get_id() << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::lock_guard<std::mutex> lock(mtx);
    // std::unique_lock<std::mutex> lock(mtx);
    for (int i = 0; i < num; i++) {
        std::cout << "[" << args << "]" << "thread num: " << i << '\n';
    }
};

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::thread thread1(func, "线程1", 10);

    std::thread thread2(func, "线程2", 10);
    thread1.join();
    thread2.join();
    auto end = std::chrono::high_resolution_clock::now();
    int cost_time =
        std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    std::cout << "cost time" << cost_time << "s" << '\n';
    std::array<std::thread, 5> thread_arr;
    for (std::size_t i = 0; i < thread_arr.size(); i++) {
        std::string thread_name = "数组线程" + std::to_string(i + 1);
        thread_arr[i] = std::thread(func_lock, thread_name.c_str(), 10);
    }
    std::for_each(thread_arr.begin(), thread_arr.end(),
                  [](std::thread& t) { t.join(); });

    // 线程数组
}
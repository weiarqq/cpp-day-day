
#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

struct MutexCounter {
    int count = 0;
    std::mutex mtx;
    void add() {
        std::unique_lock<std::mutex> lock(mtx);
        ++count;
    }

    void sub() {
        std::unique_lock<std::mutex> lock(mtx);
        --count;
    }

    int get() {
        std::unique_lock<std::mutex> lock(mtx);
        return count;
    }
};

struct AtomicCounter {
    std::atomic<int> count{0};
    void add() { ++count; }
    void sub() { --count; }
    int get() { return count.load(); }
};

// typedef AtomicCounter Counter;
typedef MutexCounter Counter;
int main() {
    const int thread_num = 100;
    const int cal_num = 100;
    Counter counter;
    std::array<std::thread, thread_num> thread_arr;
    
    for (int i = 0; i < thread_num; ++i) {
        thread_arr[i] = std::thread(
            [&](int times) {
                for (int j = 0; j < times; ++j)
                    counter.add();
            },
            cal_num);
    }
    
    for (auto& t : thread_arr) {
        t.join();
    }
    
    std::cout << "num is:" << counter.get() << '\n'; // 应该输出 10000
}
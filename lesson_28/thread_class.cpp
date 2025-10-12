

#include <chrono>
#include <iostream>
#include <thread>

enum class ThreadAction { join, detach };

class ThreadGuard {
  public:
    ThreadGuard(std::thread&& t, ThreadAction a) : t_(std::move(t)), a_(a) {};

    ~ThreadGuard() {
        if (t_.joinable()) {
            if (a_ == ThreadAction::join) {
                t_.join();
            } else {
                t_.detach();
            }
        }
    }

    ThreadGuard(ThreadGuard&& t) = default;
    ThreadGuard& operator=(ThreadGuard&& t) = default;

    std::thread& get() { return this->t_; }

  private:
    std::thread t_;
    ThreadAction a_;
};

auto func = [](const char* args, int seconds = 0) {
    std::cout << args << " thread id:" << std::this_thread::get_id() << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
};

int main() {
    ThreadGuard thread1(std::thread(func, "线程1", 3), ThreadAction::join);
}
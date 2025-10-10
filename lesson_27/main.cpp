#include <chrono>
#include <iostream>
#include <thread>

int main() {

    auto start = std::chrono::high_resolution_clock::now();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "sleep for "
              << std::chrono::duration_cast<std::chrono::milliseconds>(stop -
                                                                       start)
                     .count()
              << "ms" << '\n';
}
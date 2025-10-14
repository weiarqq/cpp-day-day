#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

class TaskQueue {
public:
    TaskQueue(int max_job_times) : max_job_times(max_job_times) {}

    void send_task(std::string msg) {
        std::unique_lock<std::mutex> lock(mtx);
        if(count >= max_job_times){
        cv_.notify_all();
        return;
        }
        task_queue.push(msg);
        std::cout << "send task:" << msg << '\n';
        cv_.notify_one(); // 呼叫线程处理任务
    }

    void finish_task() {
        while(true){
            std::unique_lock<std::mutex> lock(mtx);
            cv_.wait(lock, [this](){return !task_queue.empty();});
            if(count >= max_job_times){
                break;
            }
            std::string msg = task_queue.front();
            task_queue.pop();
            count += 1;
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::cout << "finish task:" << msg << '\n';
        }
    }


private:
    std::condition_variable cv_;
    mutable std::mutex mtx;
    int max_job_times;
    int count = 0;
    std::queue<std::string> task_queue;
};
int generate_random_int(){
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(50, 300);

    // 模拟随机工作时间
    int work_time = dist(rng);
    return work_time;
}

// 工作线程函数
void worker(TaskQueue& taskq, int id) {
    // 模拟随机工作时间
    int work_time = generate_random_int();
    std::this_thread::sleep_for(std::chrono::milliseconds(work_time));

    std::cout << "Thread " << id << " finished work (took " << work_time << "ms)\n";
    taskq.send_task("task"+std::to_string(id));
}

void work_finish(TaskQueue& taskq){
    taskq.finish_task();
}

int main() {
    TaskQueue taskq(10);

    std::cout << "Main thread starting" << " worker threads...\n";

    std::vector<std::thread> send_threads;
    send_threads.reserve(20);

    std::vector<std::thread> finish_threads;
    finish_threads.reserve(5);

    // 创建并启动工作线程
    for (int i = 0; i < 20; ++i) {
        send_threads.emplace_back(worker, std::ref(taskq), i + 1);
    }
    
    for(int i = 0; i< 5; i++){
        finish_threads.emplace_back(work_finish, std::ref(taskq));
    }
    for (auto& t : send_threads) {
        t.join();
    }

    // 等待所有工作线程完成
    std::cout << "Main thread waiting for all workers to finish...\n";
    for(auto& t:finish_threads){
        t.join();
    }

    std::cout << "All workers finished. Main thread continuing.\n";



    return 0;
}
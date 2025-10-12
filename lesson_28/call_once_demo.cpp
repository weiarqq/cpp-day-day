
#include <iostream>
#include <thread>


std::once_flag onceflag;

int main(){

    std::thread thread[10];
    for(int i = 0; i < 10; ++i){
        // 此处不能使用捕获 i 的方式，i的值会发生变化
        thread[i] = std::thread([](int x){
            std::call_once(onceflag, [](){
                std::cout << " just once" << '\n';
            });
            std::cout << "线程=" << x << '\n';
        }, i);
    }

    for(auto& t:thread){
        t.join();
    }



}
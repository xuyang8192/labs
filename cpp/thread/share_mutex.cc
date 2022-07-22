#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <shared_mutex>

// RW lock since C++ 14
std::shared_timed_mutex M;
std::mutex COUT_M;

void f1(int nId) {

    // https://en.cppreference.com/w/cpp/thread/shared_lock
    // template for std::shared_lock require specific member function, eg lock_shared / unlock_shared
    // auto invoke _M->lock_shared() in constructor
    // auto invoke _M->unlock_shared() in destructor
    std::shared_lock<std::shared_timed_mutex> mw(M);

    COUT_M.lock();
    std::cout << "Thread " << nId << " enter lock" << std::endl;    
    COUT_M.unlock();

    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main() {

    std::thread t1(f1, 1);
    std::thread t2(f1, 2);

    t1.join();
    t2.join();

    return 0;
}

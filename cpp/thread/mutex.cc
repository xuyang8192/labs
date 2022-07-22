#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

#define LOOP_CNT 10000000

int N1;
int N2;
std::mutex m;

void f1() {
    for (int i = 0; i < LOOP_CNT; ++i) {
        ++N1;
    }
}

void f2() {
    for (int i = 0; i < LOOP_CNT; ++i) {
        m.lock();
        ++N2;
        m.unlock();
    }
}

int main() {

    std::chrono::system_clock::time_point u1 = std::chrono::system_clock::now();

    std::thread t1(f1);
    std::thread t2(f1);

    t1.join();
    t2.join();

    std::chrono::system_clock::time_point u2 = std::chrono::system_clock::now();

    std::thread t3(f2);
    std::thread t4(f2);

    t3.join();
    t4.join();

    std::chrono::system_clock::time_point u3 = std::chrono::system_clock::now();

    std::cout << "LOOP_CNT=" << LOOP_CNT << "\n";
    std::cout << "N1=" << N1 << ", cost=" << std::chrono::duration_cast<std::chrono::milliseconds>(u2-u1).count() << "ms\n";
    std::cout << "N2=" << N2 << ", cost=" << std::chrono::duration_cast<std::chrono::milliseconds>(u3-u2).count() << "ms\n";

    // LOOP_CNT=10000000
    // N1=10766122, cost=51ms
    // N2=20000000, cost=1725ms

    return 0;
}

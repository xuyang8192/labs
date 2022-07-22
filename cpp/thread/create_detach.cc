#include <iostream>
#include <thread>
#include <chrono>

void f() { 
	std::cout << "Thread f start\n"; 
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Thread f exit\n";
}

void threadCreator() {
	std::cout << "Thread creator invoked\n";
	std::thread t(f); // thread created on stack, which is going to be destroyed at function exit

	// apart inner data from current stack
	// commenting this line causes abortion with core dump
	t.detach();

	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Thread creator exit\n";
}

int main() {
	threadCreator();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}



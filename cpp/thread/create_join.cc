#include <iostream>
#include <thread>

// note that std::cout is not thread safe;

void f0() { std::cout << "Thread void func void\n"; }

void f1(int idx) { std::cout << "Thread void func int " << idx << "\n"; }

int fi(void) { std::cout << "Thread int func void\n"; return 0; }

// callable class
class cc {
public:
	cc(int n_) { n = n_; }
	void operator()() { std::cout << "Thread callable class " << n << "\n"; }
private:
	int n = 0;
};

// an instance of the object is needed when creating new thread with a member function
class cm {
public:
	void f() {
		std::cout << "Thread member function\n";
	}
};

int main()
{
	std::cout << "------ basic creation ------\n";

	std::thread t0(f0);
	std::thread t1_1(f1, 100);
	std::thread t1_2(f1, 200);
	std::thread ti(fi);

	t0.join();
	t1_1.join();
	t1_2.join();
	ti.join();

	std::cout << "------ callable class creation ------\n";

	cc cc_1(100);
	cc cc_2(200);

	std::thread tcc_1(cc_1);
	std::thread tcc_2(cc_2);

	tcc_1.join();
	tcc_2.join();

	std::cout << "------ member function creation ------\n";

	cm cm_1;
	std::thread tcm_1(&cm::f, &cm_1); // std::thread arguments must be invocable after conversion to rvalues
	tcm_1.join();

	return 0;
}



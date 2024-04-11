#include "../../include/common.hh"

using namespace std;

class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<std::mutex> lck(mtx_);
            while (signal_%2 != 0) cv_.wait(lck); 
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            signal_++;  
            cv_.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<std::mutex> lck(mtx_);
            while (signal_%2 != 1) cv_.wait(lck); 
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            signal_++;  
            cv_.notify_all();            
        }
    }

private:
    mutex mtx_;  
    condition_variable cv_;  
    int signal_ = 0; 
};
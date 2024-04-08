#include "../../include/common.hh"

using namespace std;

class Foo {
public:
    Foo() {}

    void first(function<void()> printFirst) {
        unique_lock<std::mutex> lck(mtx_);
        while (signal_%3 != 0) cv_.wait(lck);          
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        signal_++;  
        cv_.notify_all();        
    }

    void second(function<void()> printSecond) {
        unique_lock<std::mutex> lck(mtx_);  
        while (signal_%3 != 1) cv_.wait(lck);         
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        signal_++;  
        cv_.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<std::mutex> lck(mtx_);  
        while (signal_%3 != 2) cv_.wait(lck);        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        signal_++;  
        cv_.notify_all();        
    }

private:
    mutex mtx_;  
    condition_variable cv_;  
    int signal_ = 0; 
};
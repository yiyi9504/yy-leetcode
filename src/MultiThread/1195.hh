#include "../../include/common.hh"

using namespace std;

class FizzBuzz {
private:
    int n_;
    int id_ = 1;
    mutex mtx_;
    condition_variable cv_;

public:
    FizzBuzz(int n) {
        this->n_ = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i=1; i<=n_; i++) {
            unique_lock<std::mutex> lck(mtx_);
            while(i > id_) cv_.wait(lck);
            if (i%3==0 && i%5 !=0) {
                printFizz();
                id_++;
                cv_.notify_all();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i=1; i<=n_; i++) {
            unique_lock<std::mutex> lck(mtx_);
            while(i > id_) cv_.wait(lck);
            if (i%3!=0 && i%5 ==0) {
                printBuzz();
                id_++;
                cv_.notify_all();
            }
        }        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i=1; i<=n_; i++) {
            unique_lock<std::mutex> lck(mtx_);
            while(i > id_) cv_.wait(lck);
            if (i%3==0 && i%5 ==0) {
                printFizzBuzz();
                id_++;
                cv_.notify_all();
            }
        }        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i=1; i<=n_; i++) {
            unique_lock<std::mutex> lck(mtx_);
            while(i > id_) cv_.wait(lck);
            if (i%3!=0 && i%5 !=0) {
                printNumber(i);
                id_++;
                cv_.notify_all();
            }
        }        
    }
};
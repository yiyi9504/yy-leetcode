#include "../../include/common.hh"

using namespace std;

class H2O {
public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<std::mutex> lck0(mtx_num);
        int h_id = h_num_++;
        r_num_ = min(h_num_/2, o_num_);
        cv_print.notify_all();
        lck0.unlock();

        unique_lock<std::mutex> lck1(mtx_print);
        while(h_id > r_num_*2|| p_num_ % 3 == 0) cv_print.wait(lck1);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        p_num_++;
        cv_print.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<std::mutex> lck0(mtx_num);
        int o_id = o_num_++;
        r_num_ = min(h_num_/2, o_num_);
        cv_print.notify_all();
        lck0.unlock();

        unique_lock<std::mutex> lck1(mtx_print);
        while(o_id > r_num_ || p_num_ % 3 != 0) cv_print.wait(lck1);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        p_num_++;
        cv_print.notify_all();
    }

private:
    mutex mtx_num, mtx_print;
    condition_variable cv_print;  
    int h_num_ = 1;
    int o_num_ = 1;
    int r_num_ = 0;
    int p_num_ = 0;
};
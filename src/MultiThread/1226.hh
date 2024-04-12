#include "../../include/common.hh"

using namespace std;

class DiningPhilosophers {
public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int id = philosopher;
        while (1)
        {
            bool lcked_0 = false;
            bool lcked_1 = false;
            int left_f = ( id + 1 ) % 5;
            int right_f = id % 5;
            for (int repeat = 3; repeat; repeat--) {
                if (mux_[left_f].try_lock()) {
                    lcked_0 = true;
                    // pickLeftFork
                    pickLeftFork();
                    break;
                }
                this_thread::sleep_for(std::chrono::microseconds(3));
            }
            if (lcked_0) {
                for (int repeat = 3; repeat; repeat--) {
                    if (mux_[right_f].try_lock()) {
                        lcked_1 = true;
                        // pickRightFork
                        pickRightFork();
                        break;
                    }
                    this_thread::sleep_for(std::chrono::microseconds(3));
                }
                if (lcked_1) {
                    // eat、putLeftFork、putRightFork
                    eat();
                    putLeftFork();
                    putRightFork();
                    mux_[left_f].unlock();
                    mux_[right_f].unlock();
                    break;
                } else {
                    putLeftFork();
                    mux_[left_f].unlock();
                    this_thread::sleep_for(std::chrono::microseconds(10)); 
                }
            } else {
                this_thread::sleep_for(std::chrono::microseconds(10));
            }  
        }
    }

private:
    mutex mux_[5];
};
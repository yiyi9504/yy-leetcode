#include "../src/MultiThread/1226.hh"

void pickLeftFork() { cout << "11" ;}
void pickRightFork() { cout << "21" ;}
void eat() { cout << "03" ;}
void putLeftFork() { cout << "12" ;}
void putRightFork() { cout << "22" ;}

int main() {
    DiningPhilosophers dp;
    for (int n=0; n<1; n++) {
        vector<thread> threads;
        for (int i=0; i<5; i++) {
            threads.emplace_back( [&dp,i]() { dp.wantsToEat(i,pickLeftFork,pickRightFork,
                                                    eat,putLeftFork,putRightFork); } );
        }
        for (auto& t: threads) { t.join(); }         
    }
    return 0;  
}
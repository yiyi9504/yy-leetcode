#include "../src/MultiThread/1117.hh"

void releaseHydrogen() { cout << "H" ;}
void releaseOxygen() { cout << "O" ;}

int main() {  
    H2O h2o;
    vector<int> ans;
    vector<thread> threads;
    string input = "OOOHHHHHHHOH";
    for (char c : input) {
        if (c == 'H') {
            threads.emplace_back( [&h2o]() { h2o.hydrogen(releaseHydrogen); } ); 
        } else {
            threads.emplace_back( [&h2o]() { h2o.oxygen(releaseOxygen); } ); 
        }      
    }
    for (auto& t: threads) { t.join(); } 
    return 0;  
}
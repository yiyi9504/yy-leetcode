#include "../src/Array/1052.hh"

int main() {
    Solution opt;
    vector<int> customers{1,0,1,2,1,1,7,5};
    vector<int> grumpy{0,1,0,1,0,1,0,1};
    int minutes = 3;
    int aws = opt.maxSatisfied(customers, grumpy, minutes);
    cout << aws;
    return 0;  
}
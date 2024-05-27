#include "../src/Array/2028.hh"

int main() {
    vector<int> rolls = {6,3,4,3,5,3};//{1,5,6};//{1,2,3,4};//{3,2,4,3};
    vector<int> awns;
    int mean = 1;
    int n = 6;
    Solution opt;
    awns = opt.missingRolls(rolls,mean,n);
    for (int x : awns) 
        cout << x << ' ';
    return 0;
}
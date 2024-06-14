#include "../src/Tree/3072.hh"

int main() {
    vector<int> nums = {5,14,3,1,2}; // {2,1,3,3} {5,14,3,1,2} {3,3,3,3}
    Solution opt;
    vector<int> anws = opt.resultArray(nums);
    for (int x : anws) cout << x << ' ';
    cout << endl;
    return 0;  
}

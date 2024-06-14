#include "../src/Tree/307.hh"

int main() {
    vector<int> nums = {1,3,5}; // {1,3,5}
    NumArray* obj = new NumArray(nums);
    char c;
    while(cin.get(c)) {
        if (c=='u') {
            int idx, val;
            cin >> idx >> val;
            // cout << idx << ' ' << val << endl;
            obj->update(idx, val);
        } else if (c=='s') {
            int left, right;
            cin >> left >> right;
            cout << obj->sumRange(left, right) << endl;
        } else {
            continue;
        }
    }
    return 0;  
}
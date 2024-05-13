#include "../../include/common.hh"

using namespace std;

#define INT_MIN_ME -19950426

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            int x = nums[i];
            if (x == INT_MIN_ME) continue;
            nums[i] = i+1;
            if (x>0){
                if (x<=i+1) {
                    nums[x-1] = INT_MIN_ME;
                } else if (x<=nums.size()){
                    if (nums[x-1] == INT_MIN_ME) continue;
                    nums[i] = nums[x-1];
                    nums[x-1] = INT_MIN_ME;
                    i--;
                }
            }
            // for (int s : nums) cout << s << ' ';
            // cout << endl;
        }
        int x = 0;
        for (int i : nums) {
            if (i>0) {
                x = i;
                break;
            }
        }
        if (!x) x = nums.size() + 1;
        return x;
    }
};
#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = nums.size();
        int anws = 0;
        for (int i=0; i<len; i++) {
            if (nums[i]) continue;
            if (len - i >= 3) {
                anws++;
                nums[i+1] = (nums[i+1] + 1) % 2;
                nums[i+2] = (nums[i+2] + 1) % 2;
            } else {
                return -1;
            }
        }
        return anws;
    }
};
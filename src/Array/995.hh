#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> b(len+10, 0);
        int anws = 0;
        for (int i=0; i<len; i++) {
            if ( (nums[i]+b[i])%2 ) {
                b[i+1] = (b[i] + b[i+1]) % 2;
            } else {
                if (len - i >= k) {
                    anws++;
                    b[i+1] = (b[i] + b[i+1] +1) % 2;
                    b[i+k] = (b[i+k] +1) % 2;
                } else {
                    return -1;
                }
            }
        }
        return anws;
    }
};
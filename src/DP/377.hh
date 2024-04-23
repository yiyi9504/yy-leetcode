#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[1010][1010] = {0};
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            dp[0][nums[i]] = 1;
        }
        int aws = dp[0][target];
        for(int i=1; i<1000; i++) {
            int flag = 0;
            for(int j=1; j<=target; j++){
                for(int k=0; k<nums.size(); k++){
                    if (nums[k] > j) break;
                    if (dp[i-1][j-nums[k]]) {
                        dp[i][j] = (int)dp[i][j] + dp[i-1][j-nums[k]]; //规避过程溢出
                    }
                }
                cout << dp[i][j] << ' ';
                flag |= dp[i][j];
            }
            if (!flag) break;
            cout << endl;
            aws += dp[i][target];
        }
        return aws;
    }
};
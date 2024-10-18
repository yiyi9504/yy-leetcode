#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    Solution() {
        memset(an, 0, sizeof(an));
    }
    int findIntegers(int n) {
        // cout << intToBinaryString(n) << endl;
        if (n<2) return n+1;
        binstr_ = intToBinaryString(n);
        len_ = binstr_.size();
        return dfs(len_,1,true)+dfs(len_,0,false);
    }
private:
    int dfs(int len, int high, bool flag) {
        if (len == 1) {
            if (flag && binstr_[len_-1]<high)
                return 0;
            return 1;
        }
        int count = 0;
        int next = binstr_[len_-len+1]-'0';
        if (high) {
            if (!flag) {
                if (an[len-1][0]==0)
                    an[len-1][0] = dfs(len-1,0,false);
                count += an[len-1][0];
            } else {
                if (next) {
                    if (an[len-1][0]==0)
                        an[len-1][0] = dfs(len-1,0,false);
                    count += an[len-1][0];   
                } else {
                    count += dfs(len-1,0,true);
                }                 
            }
        } else {
            if (!flag) {
                if (an[len-1][1]==0)
                    an[len-1][1] = dfs(len-1,1,false);
                count += an[len-1][1]; 
                if (an[len-1][0]==0)
                    an[len-1][0] = dfs(len-1,0,false);
                count += an[len-1][0];
            } else {
                if (next) {
                    count += dfs(len-1,1,true);
                    if (an[len-1][0]==0)
                        an[len-1][0] = dfs(len-1,0,false);
                    count += an[len-1][0];
                } else {
                    count += dfs(len-1,0,true);
                }                 
            }
        }
        return count;
    }

    std::string intToBinaryString(int n) {  
        std::string binaryStr = "";
        bool flag = false;
        // 10^9: 32位int
        for (int i = 31; i >= 0; --i) { 
            if ((n >> i) & 1) {
                binaryStr += '1';
                flag = true;
            } else if (flag) {
                binaryStr += '0';
            } 
        }  
        return binaryStr;  
    }
    string binstr_;
    int len_;
    int an[32][3];
};
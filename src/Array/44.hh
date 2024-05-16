#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // for (auto c : s) cout << c << ' ';
        string pp = "";
        vector<int> need;
        vector<bool> has;
        int neet_x = 0;
        bool flag = false;
        for (auto c : p) {
            if (c=='?') {
                neet_x++;
            } else if (c=='*') {
                flag = true;
            } else {
                pp = pp + c;
                need.push_back(neet_x);
                has.push_back(flag);
                neet_x = 0;
                flag = false;
            }
        }
        need.push_back(neet_x);
        has.push_back(flag);

        bool match = true;
        int idx = 0;
        int len = s.size();        
        for (int i=0; i< pp.size(); i++) {
            char c = pp[i];
            neet_x = need[i];
            flag = has[i];
            int idx_0 = idx;
            int done = false;
            while (idx<len) {
                if (s[idx] == c) {
                    if (idx-idx_0==neet_x || (flag && idx-idx_0>=neet_x)) {
                        done = true;
                        idx++;
                        break;
                    }
                }
                idx++;
            }
            if (!done) {
                match = false;
                break;
            }
        }
        neet_x = need[pp.size()];
        flag = has[pp.size()];
        if (!(len-idx==neet_x || (flag && len-idx>=neet_x))) {
            match = false;
            cout << len-idx << ' ' << neet_x << endl;
        }                   
        return match;
    }
};
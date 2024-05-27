#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int s1 = 0;
        vector<int> awns;
        for(int x : rolls) s1+=x;
        // cout << (s1+n*6) << ' ' << mean*(n+m) << endl;
        if ((s1+n*6) >= mean*(n+m) && s1+n <= mean*(n+m)) {
            int a = (mean*(n+m)-s1) / n;
            int b = (mean*(n+m)-s1) % n;
            // cout << a << ' ' << b << endl;
            for (int i=0; i<b; i++) awns.push_back(a+1);
            for (int i=0; i<(n-b); i++) awns.push_back(a);
        }
        return awns;
    }
};
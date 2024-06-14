#include "../../include/common.hh"

using namespace std;

#define N 110000
#ifndef lowbit
#define lowbit(x) (x & (-x));
#endif

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> cops = nums;
        sort(cops.begin(),cops.end());
        int rep = 0, id = 1;
        for (int x : cops) {
            if (x != rep) {
                idx[x] = id++;
                rep = x;
            }
        }
        cops.clear();

        vector<int> anws_a = {nums[0]};
        vector<int> anws_b = {nums[1]};
        insert_x(an, idx[nums[0]]);
        insert_x(bn, idx[nums[1]]);
        for (int i=2; i<nums.size(); i++) {
            int x = idx[nums[i]];
            int conta = anws_a.size() - search_x(an, x);
            int contb = anws_b.size()  - search_x(bn, x);
            cout << x << ": "<< conta << ' ' << contb << endl;
            if ((conta>contb) || (conta==contb && anws_a.size()<=anws_b.size())) {
                insert_x(an, x);
                anws_a.push_back(nums[i]);
            } else {
                insert_x(bn, x);
                anws_b.push_back(nums[i]);
            }
        }

        anws_a.insert(anws_a.end(),anws_b.begin(),anws_b.end());
        return anws_a;
    }

private:
    int search_x(int* tn, int x) {
        int res = 0;
        while (x > 0) {
            res += tn[x];
            x -= lowbit(x);
        }
        return res;        
    }
    void insert_x(int* tn, int x) {
        while (x < N) {
            tn[x] += 1;
            x += lowbit(x);
        }
    }

    map<int,int> idx;
    int an[N];
    int bn[N];
};
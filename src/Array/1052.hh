#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int len = customers.size();
        int sum = 0, add = 0, max_add = 0;
        for (int i=0; i<len; i++) {
            sum += customers[i] * ((1 + grumpy[i]) % 2);
            if (i < minutes) {
                add += grumpy[i] ? customers[i] : 0;
                max_add = add;
            } else {
                add -= grumpy[i-minutes] ? customers[i-minutes] : 0;
                add += grumpy[i] ? customers[i] : 0;
                if (add > max_add) max_add = add;
            }
        }
        return sum + max_add;
    }
};
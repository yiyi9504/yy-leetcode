#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets==1) return 0;
        int t = minutesToTest / minutesToDie;
        // n <= (t+1) ^ x 
        int anws = 1;
        for (int i=t+1; i<buckets; anws++) {
            i *= (t+1);
        }
        return anws;
    }
};
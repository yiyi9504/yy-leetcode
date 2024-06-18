#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int awns = 0;
        awns += (ax2-ax1)*(ay2-ay1);
        awns += (bx2-bx1)*(by2-by1);
        int y1 = max(ay1,by1);
        int y2 = min(ay2,by2);
        int x1 = max(ax1,bx1);
        int x2 = min(ax2,bx2);
        if (y2-y1>0 && x2-x1>0)
            awns -= (y2-y1)*(x2-x1);
        return awns;
    }
};
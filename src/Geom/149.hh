#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int num = points.size();
        if (num < 3) return num;
        int a, b, c, max_p=0;
        for (int i=0; i<num; i++) {
            for (int j=i+1; j<num; j++) {
                a = points[j][1] - points[i][1];
                b = points[i][0] - points[j][0];
                c = points[j][0] * points[i][1] - points[i][0] * points[j][1];
                int max_x = 0;
                for (int k=0; k<num; k++) {
                    if (k==i || k==j) continue;
                    int a1 = points[k][1] - points[i][1];
                    int b1 = points[i][0] - points[k][0];
                    int c1 = points[k][0] * points[i][1] - points[i][0] * points[k][1];
                    if (b*a1==b1*a && c*a1==c1*a) max_x++;
                }
                if (max_x > max_p) max_p = max_x;
            }
        }
        return max_p+2;
    }
};

// A = y2 - y1
// B = x1 - x2
// C = x2y1 - x1y2
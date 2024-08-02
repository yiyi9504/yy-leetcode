#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        vector<long long> hh;
        vector<long long> ll;
        int h_size = grid.size();
        int l_size = grid[0].size();
        for (int i=0; i<h_size; i++) {
            int count = 0;
            for (int j=0; j<l_size; j++)
                count += grid[i][j];
            hh.push_back(count);
        }
        for (int i=0; i<l_size; i++) {
            int count = 0;
            for (int j=0; j<h_size; j++)
                count += grid[j][i];
            ll.push_back(count);
        } 
        long long anws = 0;
        long long anwx;
        for (int i=0; i<h_size; i++) {
            // long long anwx = ( hh[i] * (hh[i]-1) ) / 2;
            for (int j=0; j<l_size; j++) {
                if (grid[i][j]) {
                    anws += ( (hh[i]-1) * (ll[j]-1) );
                    // cout << i << ' ' << j << ' ' << hh[i]-1 << ' ' << ll[j]-1 << endl;
                }
            }
        }
        return anws;       
    }
};
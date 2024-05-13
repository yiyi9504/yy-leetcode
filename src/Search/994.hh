#include "../../include/common.hh"

using namespace std;

inline bool isIndexValid(int m, int n, int i, int j) {  
    return i>=0 && j>=0 && i<m && j<n;  
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int orange_num=0, fixed=0, max_time=0;
        queue<vector<int>> bfs;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++) {
                if (grid[i][j]) {
                    orange_num++;
                    if (grid[i][j]>1) {
                        fixed++;
                        bfs.push({i,j,0});
                        grid[i][j] = 0;
                    }
                }
            }
        }
        while(!bfs.empty()) {
            auto orange = bfs.front();
            bfs.pop();
            int i = orange[0];
            int j = orange[1];
            int time = orange[2];
            max_time = max_time>time ? max_time : time;
            time++;
            //O
            if (isIndexValid(m,n,i-1,j) && grid[i-1][j]) {
                fixed++;
                bfs.push({i-1,j,time});
                grid[i-1][j] = 0;                
            }
            //U
            if (isIndexValid(m,n,i+1,j) && grid[i+1][j]) {
                fixed++;
                bfs.push({i+1,j,time});
                grid[i+1][j] = 0;                
            }            
            //L
            if (isIndexValid(m,n,i,j-1) && grid[i][j-1]) {
                fixed++;
                bfs.push({i,j-1,time});
                grid[i][j-1] = 0;                
            }            
            //R
            if (isIndexValid(m,n,i,j+1) && grid[i][j+1]) {
                fixed++;
                bfs.push({i,j+1,time});
                grid[i][j+1] = 0;                
            }            
        }
        if (fixed<orange_num) max_time = -1;
        return max_time;
    }
};
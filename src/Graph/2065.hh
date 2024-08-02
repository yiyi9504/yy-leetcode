#include "../../include/common.hh"
#include "../../include/Dijkstra.hh"

using namespace std;

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int num = values.size();
        for (int i=1; i<=num; i++)
            for (int j=1; j<=num; j++)
                w[i][j] = INF;
        for (auto edge : edges) {
            int v1 = edge[0], v2 = edge[1], wx = edge[2];
            w[v1+1][v2+1] = wx;
            w[v2+1][v1+1] = wx;
        }
        dijkstra(num,1);
        
        memset(b,0,sizeof(b));
        b[0]=1;
        dfs(0,values[0],0,values,maxTime);
        return max_w;
    }
private:
    void dfs(int nid, long long wx, long long cost, vector<int>& values, int maxTime) {
        int num = values.size();
        long long min_cost = dis[nid+1];
        vector<int> out_node;
        for (int i=1; i<=num; i++) {
            if (w[nid+1][i] != INF && i!=nid+1) {
                out_node.push_back(i-1);
                if (w[nid+1][i]+dis[i] < min_cost) 
                    min_cost = w[nid+1][i]+dis[i];
            }
        }
        if (cost+min_cost > maxTime) return;
        if (wx > max_w) max_w = wx;

        for (int v : out_node) {
            if (b[v]<=4 && cost+w[nid+1][v+1]<=maxTime) { //可以优化成出边仅走一遍
                b[v] += 1;
                if (b[v]==1) {
                    dfs(v, wx+values[v], cost+w[nid+1][v+1],values,maxTime); 
                } else {
                    dfs(v, wx, cost+w[nid+1][v+1],values,maxTime);
                }
                b[v] -= 1;                    
            }            
        }
    }
    long long max_w = 0;
};
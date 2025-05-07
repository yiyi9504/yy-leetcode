#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<pair<int, bool>>> ans(n, vector<pair<int, bool>>(m, make_pair(-1, false)));

        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        ans[0][0].first = 0;
        ans[0][0].second = true;
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            //shang
            if(i-1 >= 0 && (ans[i-1][j].first <0 || ans[i-1][j].first > max(ans[i][j].first+1, moveTime[i-1][j]+1))){
                ans[i-1][j].first = max(ans[i][j].first+1, moveTime[i-1][j]+1);
                if(!ans[i-1][j].second){
                    ans[i-1][j].second = true;
                    q.push(make_pair(i-1,j));
                }
            }
            //xia
            if(i+1 < n && (ans[i+1][j].first <0 || ans[i+1][j].first > max(ans[i][j].first+1, moveTime[i+1][j]+1))){
                ans[i+1][j].first = max(ans[i][j].first+1, moveTime[i+1][j]+1);
                if(!ans[i+1][j].second){
                    ans[i+1][j].second = true;
                    q.push(make_pair(i+1,j));
                }
            }           
            //zuo
            if(j-1 >= 0 && (ans[i][j-1].first <0 || ans[i][j-1].first > max(ans[i][j].first+1, moveTime[i][j-1]+1))){
                ans[i][j-1].first = max(ans[i][j].first+1, moveTime[i][j-1]+1);
                if(!ans[i][j-1].second){
                    ans[i][j-1].second = true;
                    q.push(make_pair(i,j-1));
                }
            }
            //you
            if(j+1 < m && (ans[i][j+1].first <0 || ans[i][j+1].first > max(ans[i][j].first+1, moveTime[i][j+1]+1))){
                ans[i][j+1].first = max(ans[i][j].first+1, moveTime[i][j+1]+1);
                if(!ans[i][j+1].second){
                    ans[i][j+1].second = true;
                    q.push(make_pair(i,j+1));
                }
            }
            ans[i][j].second = false;
        }
        return ans[n-1][m-1].first;
    }
};
#include "../src/Array/2589.hh"

int main() {
vector<vector<int>> tasks = {{11,16,3},{7,16,6},{4,19,8},{3,10,3}};//{{2,3,1},{4,5,1},{1,5,2}};//{{3,11,2},{5,12,3},{9,20,2},{11,19,2}};//{{1,3,2},{2,5,3},{5,6,2}};//{{2,13,2},{6,18,5},{2,13,3}};
    Solution opt;
    cout << opt.findMinimumTime(tasks) << endl;
    return 0;
}

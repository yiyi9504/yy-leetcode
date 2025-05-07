#include "../src/Search/3341.hh"

int main() {
    vector<vector<int>> moveTime =  {{0,4},{4,4}}; //{{0,1},{1,2}};{{0,0,0},{0,0,0}};
    Solution opt;
    cout << opt.minTimeToReach(moveTime) << endl;
    return 0;
}
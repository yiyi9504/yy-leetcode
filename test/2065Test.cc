#include "../src/Graph/2065.hh"

int main() {
    vector<int> values = {0,32,10,43};
    vector<vector<int>> edges = {{0,1,10},{1,2,15},{0,3,10}};
    int maxTime = 49;
    Solution opt;
    cout << opt.maximalPathQuality(values,edges,maxTime) << endl;
    return 0;
}
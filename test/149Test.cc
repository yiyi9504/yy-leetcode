#include "../src/Geom/149.hh"

int main() {
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}}; // {{1,1},{2,2},{3,3}}; // {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}}
    Solution opt;
    cout << opt.maxPoints(points) << endl;
    return 0;
}
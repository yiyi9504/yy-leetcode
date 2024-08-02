#include "../src/Math/3128.hh"

int main() {
    vector<vector<int>> grid = {{1,0,1},{1,0,0},{1,0,0}};
    Solution opt;
    cout << opt.numberOfRightTriangles(grid) << endl;
    return 0;
}

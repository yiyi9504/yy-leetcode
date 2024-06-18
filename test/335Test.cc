#include "../src/Geom/335.hh"

int main() {
    vector<int> distance = {1,1,1,2,1};//{1,2,3,4}; //{2,1,1,2};
    Solution opt;
    cout << opt.isSelfCrossing(distance) << endl;
    return 0;
}
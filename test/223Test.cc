#include "../src/Geom/223.hh"

int main() {
    int ax1 = 0, ay1 = 2, ax2 = 0, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2;// ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2; //ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
    Solution opt;
    cout << opt.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << endl;
    return 0;
}
#include "../src/Array/44.hh"

int main() {
    string s = "abcabczzzde";//"aa";//"acdcb";
    string p = "*abc???de*";//"aa";//a*c?b";
    Solution opt;
    cout << opt.isMatch(s,p) << endl;
    return 0;
}
#include "../src/Array/32.hh"

int main() {
    string str = ")()())";// "(()(((()"; // ")()())()()(";
    Solution opt;
    cout << opt.longestValidParentheses(str) << endl;
    return 0;
}
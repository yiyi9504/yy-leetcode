#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int anws = 0;
        stack<int> st;
        for (char x : s) {
            if (x=='(') {
                st.push(0);
            } else {
                int w = 2;
                while(!st.empty()) {
                    int rep = st.top();
                    st.pop();
                    if (rep) {
                      w+=rep;  
                    } else {
                      st.push(w); 
                      break; 
                    }
                }
                if (st.empty()) {
                    if (w-2 > anws) anws = w-2;
                }
            }
        }
        int sum = 0;
        while(!st.empty()) {
            int x = st.top();
            st.pop();
            if (x) {
                sum += x;
            } else {
                if (sum > anws) anws = sum;
                sum = 0;
            } 
        }
        if (sum > anws) anws = sum;      
        return anws;
    }
};
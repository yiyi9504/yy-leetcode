#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int num = strs.size();
        int awns = -1;
        std::sort(strs.begin(), strs.end(), [](const std::string& a, const std::string& b) {  
            if (a.length() != b.length()) {  
                return a.length() > b.length();  
            } 
            return a < b;  
        });  
        for (int id=0; id<num; id++) {
            bool is_LUS = true;
            for (int i=0; i<num; i++) {
                if (i==id) continue;
                if (strs[i].length()<strs[id].length()) break;
                if (isSon(strs[i],strs[id])) {
                    is_LUS = false;
                    break;
                } 
            }
            if (is_LUS) {
                if (int(strs[id].length()) > awns) awns = strs[id].length();
                break;
            }
        }
        return awns;
    }
private:
    bool isSon(std::string& a, std::string& b) {
        int it_a=0, it_b=0;
        int num_a = a.length();
        int num_b = b.length();
        while(it_a<num_a && it_b<num_b) {
            if (num_a-it_a < num_b-it_b) break;
            if (a[it_a]==b[it_b]) {
                it_a++;
                it_b++;
            } else {
                it_a++;
            }
        }
        // cout << a << ' ' << b << ' ' << (it_b==num_b) << endl;
        return it_b==num_b;  
    }
};
#include "../../include/common.hh"
#include "../../include/Number.hh"

using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int min_x = min(zero,one);
        int max_x = max(zero,one);
        int tt = max_x/limit -1;
        if (max_x%limit) max_x++;
        if (min_x < tt) return 0;

        initComb1(); // C[i][j]从i里面选j个
        long long CN = C[zero+one][zero];
        cout << "CN " << CN << endl;
        int n = zero+one;
        if (limit >= n) return CN;
        limit++;
        if (zero >= limit) {
            long long C0 = (n-limit+1) * C[n-limit][zero-limit] % mod;
            CN = (CN+mod-C0) % mod;
            cout << "CN C0 " << CN << ' ' << C0 << endl;
        } 
        if (one >= limit) {
            long long C1 = (n-limit+1) * C[n-limit][one-limit] % mod;
            CN = (CN+mod-C1) % mod;
            cout << "CN C1 " << CN << ' ' << C1 << endl;
        }
        if (zero >= limit && one >= limit) {
            long long C01 = (n-limit+1) * (n-limit) / 2;
            for (int i=limit; i<2*limit-1; i++)
                C01 -= (n-i);
            CN = (CN+C01*2) % mod;
            cout << "CN C01 " << CN << ' ' << C01 << endl;
        }
        return CN;
    }
};
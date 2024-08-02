#include "common.hh"
using namespace std;

// C(n, k) = C(n, k - 1) * (n - k + 1) / k;
// 对2~maxn的逆元打表后，利用这个公式可以O(n)时间内求出C(n, k)

void getcom(int x){
    c[0] = c1[0] = 1; c[1] = x; c1[1] = n - x;
    for(int i = 2; i <= x; i++)
                // inv[i] 指i的逆元，可以使用扩展gcd打表
        c[i] = c[i - 1] % mod * (x - i + 1) % mod * inv[i] % mod;
}
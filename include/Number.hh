#include "common.hh"
using namespace std;

const int N=420;
const int mod=1e9+7;
int C[N][N]; // C[i][j]从i里面选j个
void initComb1()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<=i;j++)
        {
            if(j==0) {
                C[i][j]=1;
            } else {
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
            }
        }
}

// typedef long long int LL;
// const int N_max=1e6+10;
// const int mod=1e9+7;
// LL f[N_max],inf[N_max];
// LL quick_mi(LL a,LL b,LL p)
// {
//     LL sum=1;
//     while(b)
//     {
//         if(b&1) sum=sum*a%p;
//         b>>=1;
//         a=a*a%p;
//     }
//     return sum%p;
// }
// void initComb2()
// {
//     f[0]=1,inf[0]=1;
//     for(int i=1;i<N;i++)
//     {
//         f[i]=f[i-1]*i%mod;
//         inf[i]=inf[i-1]*quick_mi(i,mod-2,mod)%mod;
//     }
// }
// LL query(LL a,LL b)//从a里面选b个
// {
//     return f[a]*inf[a-b]%mod*inf[b]%mod;
// }

#include "common.hh"
using namespace std;

int const N=10000;
int const INF=99999999;
int w[N][N];
int dis[N],fa[N],b[N];

void dijkstra(int n,int s)
{
    memset(b,0,sizeof(b));
    memset(fa,-1,sizeof(fa));
    for(int i=1;i<=n;i++)dis[i]=INF;
    dis[s]=0;
    for(int j=0;j<n;j++)
    {
        int k=-1,mmin=INF;
        for(int i=1;i<=n;i++)
            if(!b[i]&&dis[i]<mmin)k=i,mmin=dis[i];
        if(k==-1)break;
        b[k]=1;
        for(int i=1;i<=n;i++)
        {
            if(!b[i]&&dis[i]>dis[k]+w[k][i])
            {
                dis[i]=dis[k]+w[k][i];
                fa[i]=k;
            }
        }
    }
}
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define inf 1000000000

int dist[5000][5000];
int ar[10000][10000];
bool mark[1000][1000];
int x,y;
int I[]= {0,1};
int J[]= {1,0};
struct data
{
    int add,ad,dis;
    data(int a,int a1,int b)
    {
        add=a;
        ad=a1;
        dis=b;
    }
    bool operator<(const data &x)const
    {
        return dis>x.dis;
    }
};
int dijkstra(int start1,int start2,int end1,int end2)
{
    dist[start1][start2]=ar[0][0];
    int i,u,v,t;
    priority_queue<data>Q;
    Q.push(data(start1,start2,dist[start1][start2]));
    while(!Q.empty())
    {
        data rt=Q.top();
        Q.pop();

        if(rt.add==x-1&&rt.ad==y-1)
            return dist[end1][end2];
        for(i=0; i<2; i++)
        {
            u=rt.add+I[i];
            v=rt.ad+J[i];
            if(u>=0&&u<x&&v>=0&&v<y)
            {
                t=dist[rt.add][rt.ad]+ar[u][v];
                if(dist[u][v]>t)
                {
                    dist[u][v]=t;
                    Q.push(data(u,v,dist[u][v]));

                }
            }
        }
    }

}
int main()
{
    int i,k,n,m,p,a,b,z,j,v,ans;

    scanf("%d",&a);

    for(i=0; i<a; i++)
    {
        memset(mark,0,sizeof(mark));
        scanf("%d%d",&x,&y);
        for(j=0; j<x; j++)
        {
            for(k=0; k<y; k++)
            {
                scanf("%d",&ar[j][k]);
                dist[j][k] = inf;
            }
        }
        //memset(dist,10,sizeof(dist));

        ans=dijkstra(0,0,x-1,y-1);
        printf("%d\n",ans);

    }
    return 0;
}




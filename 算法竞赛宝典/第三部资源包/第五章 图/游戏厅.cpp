//游戏厅 
#include <iostream>
using namespace std;
int x[10000+1],y[10000+1],e[10000+1];
int d[10000+1];
int n,m,s,t;
char change;
void init()
{
    cin>>n>>m;//读入点的个数和边的个数
    int i,j;
    for(i=1;i<=m;i++)//采取前向星方式读入
        cin>>x[i]>>y[i]>>e[i];
    cin>>s>>t;
}
void bellman_ford(int s)//bellman-ford
{
    int i,j,k;
    for(i=1;i<=n;i++)
        d[i]=INT_MAX;
    d[s]=0;
    for(i=1;i<n;i++)
        for(j=1;j<=m;j++)
            if(d[x[j]]!=INT_MAX && d[y[j]]>d[x[j]]+e[j])
                d[y[j]]=d[x[j]]+e[j];
    if(d[t]!=INT_MAX)
        cout<<d[t]<<endl;
    else
        cout<<"No Solution!"<<endl;
}
int main()
{
  init();
  bellman_ford(s);
  return 0;
}

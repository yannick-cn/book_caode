#include <iostream>
using namespace std;

int n, m, k;
int link[101]; //例如link[1]=3代表女1与男3相匹配 　　
bool visit [101]; //记录女运动员节点是否被访问过 　　
bool map[101][101];//map[a][b]=1代表a,b顶点有边相连 　　

bool dfs(int a)
{
  for (int i=1;i<=m;i++)//遍历女运动员 
    if (map[a][i]==1&&!visit[i]) //如顶点i与a有边且未被访问 
    {
      visit[i] = true; //标记i为已访问 
      if(link[i]==0||dfs(link[i]))//如i未在匹配M中，或i匹配的节点有增广路 　
      {
        link[i]=a; //异或反转
        return true; //返回 　　
      }
    }
  return false;//无增广路则返回false 
}

int main()
{
  int a,b,ans=0;
  cin>>n>>m>>k;//n,m为男、女运动员个数，k为边数
  for(int i=1;i<=k;i++)
  {
    cin>>a>>b;
    map[a][b]=true;
  }
  for (int i=1; i<=n; i++)//穷举男运动员顶点 
  {
    memset(visit, 0, sizeof(visit));//清空上次节点访问标记
    if (dfs(i))
      ans++; //从节点i尝试扩展
  }
  cout<<ans<<endl;
  return 0;
}

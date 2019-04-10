//宇宙食物链 
#include <iostream>
using namespace std;

int father[50005];
int rank[50005];

void Sent(int x)//初始化集合 
{
  father[x]=x;
  rank[x]=0;
}

//查找x的集合，回溯时压缩路径，并修改x与father[x]的关系 
int Find_set(int x)
{
  int t; 
  if(x!=father[x])
  {
    t = father[x];
    father[x]= Find_set(father[x]);
    //更新x与father[X]的关系 
    rank[x] = (rank[x]+rank[t])%3;
  }
  return father[x];
}

void Union(int x,int y,int d)//合并x,y所在的集合
{
  int xf = Find_set(x);
  int yf = Find_set(y);  
  father[xf] = yf;//将集合xf合并到yf集合上 
  rank[xf]=(rank[y]-rank[x]+3+d)%3;//更新 xf 与father[xf]的关系
}

int main()
{
  int total=0;
  int i,n,k,x,y,d,xf,yf;
  cin>>n>>k;
  for(i=1;i<=n;++i)
    Sent(i);
  while(k--)
  {
    cin>>d>>x>>y;
    if(x>n||y>n||(d==2 && x == y))//如果x或y比n大，或x吃x，是假话
      total++;                 
    else
    {
      xf = Find_set(x);
      yf = Find_set(y);
      //如果x，f的父节点相同 ，那么可以判断给出的关系是否正确的 
      if(xf == yf)
      {
        if((rank[x]-rank[y]+3)%3 != d-1)
          total++;                              
      }
      else
        Union(x,y,d-1);//否则合并x，y 
    }
  }
  cout<<total<<endl;
  return 0;
}



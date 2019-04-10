//无所不在的宗教 
#include<iostream>   
using namespace std;   
  
int father[50001];   
int rank[50001];//rank值记录树的高度   
  
int find(int x)//查找，并把查找路径上的结点都指向跟，以减小树的高度 
{   
  if(x!=father[x])
    father[x]=find(father[x]);//路径压缩   
  return father[x];   
}   
  
void Union(int x,int y)//合并
{   
  int r1=find(x);   
  int r2=find(y);   
  if(r1==r2)//两元素如在同一集合则退出 
    return;   
  if(rank[r1]<rank[r2])////rank值较小的集合合并到大的集合中 
    father[r2]=r1;   
  else
  {   
    if(rank[r1] == rank[r2])//rank值相等的树合并后rank要增加一    
      rank[r2]++;   
    father[r1]=r2;   
  }   
}   
  
int main()
{   
  int m,n, a,b,Case=0,i=0;   
  while(cin>>n>>m,n)
  {    
    Case++;   
    for(i=0;i<n;i++)
    {
      father[i]=i;//注意根结点指向自身   
      rank[i]=0;//树的初始深度为0            
    }   
    for(i=0;i<m;i++)
    {   
      cin>>a>>b;   
      int x=find(a);   
      int y=find(b);   
      if(x!=y)//如在不同的集合，则合并
      {   
        n--;//宗教数减一   
        Union(x,y);   
      }   
    }   
    cout<<"Case "<<Case<<": "<<n<<endl;   
  }   
  return 0;   
}

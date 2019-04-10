//并查集 
#include <iostream>
using namespace std;
int N,M,Q;
int father[20001];

int find(int x) //判断x所属的集合 
{ 
  int root=x;
  while(father[root]>=0)//找到最终的根结点 
    root=father[root];
  while(root!=x) //压缩路径 
  { 
    int temp=father[x]; 
    father[x]=root; 
    x=temp; 
  } 
  return root; 
} 

void Union(int a,int b) //合并两个不同集合的元素 
{ 
  int temp=father[a]+father[b]; 
  if(father[a]>father[b]) //较小的树成为较大的树的子树 
  { 
    father[a]=b; 
    father[b]=temp; 
  } 
  else 
  { 
    father[b]=a; 
    father[a]=temp; 
  } 
}

int main()
{ 
  int i,a,b;
  cin>>N>>M>>Q; 
  for(i=1;i<=N;i++)//初始化 
    father[i]=-1; //各节点的父结点均为-1
  for(i=1;i<=M;i++)
  {
    cin>>a>>b;
    if(find(a)!=find(b))
      Union(a,b);//联通
  }  
  for(i=1;i<=Q;i++)
  {
    cin>>a>>b;
    if(find(a)==find(b))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;              
  }    
 return 0;
} 

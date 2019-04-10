//时间链 
#include<iostream>
using namespace std;
#define N 100005
int ans;

struct node
{
 int left,right;
 int color;//二进制码标记颜色
 int lazy; //标记是否更新
 int mid()
 {
   return (left+right)>>1;
 }
}E[N*4];

void build(int root,int l,int r)//建树
{
  E[root].left=l;
  E[root].right=r;
  E[root].color=1;
  E[root].lazy=0;//初始为未标记 
  if(l==r)
    return;
  else
  {
    int mid=E[root].mid();
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
  }
}

void update(int root,int l,int r,int c)//lazy思想，延迟更新
{
  if(E[root].left==l && E[root].right==r)//恰好为该段 
  {
    E[root].color=c;
    if(l!=r)
      E[root].lazy=1;
    return;
  }
  else
  {
    if(E[root].lazy==1)//如果已做标记 
    {
      E[root<<1].lazy=E[root<<1|1].lazy=1;//两子节点也做标记 
      E[root<<1].color=E[root<<1|1].color=E[root].color;//两子节点更新父节点颜色 
      E[root].lazy=0;//自身清空 
    }
    int mid=E[root].mid();
    if(r<=mid)
      update(root<<1,l,r,c);//更新左节点 
    else if(l>mid)
      update(root<<1|1,l,r,c);//更新右节点 
    else
    {
      update(root<<1,l,mid,c);
      update(root<<1|1,mid+1,r,c);
    }
  }
  E[root].color=E[root<<1].color|E[root<<1|1].color;//位或 
}

int query(int root,int l,int r)
{
  if((E[root].left==l && E[root].right==r) || E[root].lazy==1)
    return E[root].color;
  else
  {
    int mid=E[root].mid();
    if(r<=mid)
      return query(root<<1,l,r);//递归左结点 
    else if(l>mid)
     return query(root<<1|1,l,r);//递归右结点 
    else
     return query(root<<1,l,mid)|query(root<<1|1,mid+1,r);//两段的合并      
  }
}

int code(int x)//将x转换为二进制码 
{
 return 1<<(x-1);//例如x=7时，返回值为64，二进制即1000000 
}

int uncode(int x)//计算二进制的x中有多少个1
{
  int t=0;
  while(x>0)
  {
    if(x%2==1)
      t++;
    x/=2;
  }
  return t;
}

int main()
{
  int i,L,m,t;
  char c;
  while(scanf("%d%d%d",&L,&t,&m)!=EOF)
  {
    build(1,1,L);
    for(i=0;i<m;i++)
    {
      scanf(" %c",&c);
      if(c=='C')
      {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        c=code(c);//将颜色转为二进制 
        cout<<"c="<<c<<endl;
        if(a<b)
          update(1,a,b,c);
        else
          update(1,b,a,c);
      }
      else if(c=='P')
      {
        int st,en;
        scanf("%d%d",&st,&en);
        if(st<en)  
          ans=uncode(query(1,st,en));
        else
          ans=uncode(query(1,en,st));
        printf("%d\n",ans);
      }
    }
   }
   return 0;
}

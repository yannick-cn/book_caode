//太空堡垒 
#include<iostream> 
#include <cstdio>  
using namespace std;  
struct  
{  
  int a,b,sum;  
}t[140000];  
int people[50010],SUM;  //people[50010]存放每个点上的船数，SUM为输出查询结果 
   
void make(int x,int y,int num)//构造线段树  
{  
  t[num].a=x; //确定左端点为x 
  t[num].b=y; //确定右端点为y 
  if(x==y) //如果x==y，说明已经是叶子节点了
    t[num].sum=people[y];//则人数为单个的堡垒飞船数即r[y]   
  else
  {  
    make(x,(x+y)/2,num+num); //递归构造左儿子树   
    make((x+y)/2+1,y,num+num+1); //递归构造右儿子树
    //父节点的人数等于子节点飞船数之和，线段被分成两段   
    t[num].sum=t[num+num].sum+t[num+num+1].sum;    
  }  
} 
 
void query(int i,int j,int num)//初始num为1，即从根节点开始查找  
{  
  if(i<=t[num].a && j>=t[num].b)//找到要求的线段区间，返回其值   
    SUM+=t[num].sum; //SUM初始为零，不断累加飞船数，最后返回的是SUM值 
  else
  {  
    int min=(t[num].a+t[num].b)/2;  
    if(i>min) //要查询的线段在该线段右边，查询该线段的右子节点
      query(i,j,num+num);
    else if(j<=min) //要查询的线段在该线段左边，查询该线段的左子节点 
      query(i,j,num+num+1);  
    else
    {  
      //要查询的线段在该线段中间，分段查询，左右节点都查   
      query(i,j,num+num);  
      query(i,j,num+num+1);  
    }  
  }  
} 
 
void add(int i,int j,int num)//第i个堡垒增加j个飞船，初始num为1  
{  
  //从根节点不断往下更改，只要包含该点i的线段子都增加相应的数量j   
  t[num].sum+=j;  
  if(t[num].a==i && t[num].b==i)//如果找到i的叶子节点，则停止 
    return;   
  if(i>(t[num].a+t[num].b)/2) //如果点i在该线段的右边
    add(i,j,num+num+1);//则递归进入右子节点   
  else 
    add(i,j,num+num);//否则递归进入左子节点   
}  

void sub(int i,int j,int num)  
{  
  t[num].sum-=j;  
  if(t[num].a==i && t[num].b==i) 
    return;  
  if(i>(t[num].a+t[num].b)/2) 
    sub(i,j,num+num+1);  
  else 
    sub(i,j,num+num);  
} 
 
int main(int argc, char* argv[])  
{  
  int n,t,i,j;  
  char command[6];  
  cin>>t;  
  j=0;  
  while(t--)  
  {  
    int temp,a,b;  
    cin>>n;  
    people[0]=0;  
    for(i=1;i<=n;i++)  
      cin>>people[i];  
    make(1,n,1);//从 根节点t[1]开始  
    cout<<"Case "<<++j<<":"<<endl;  
    while(cin>>command)  
    {  
      if(strcmp(command,"End")==0)  
        break;  
      else if(strcmp(command,"Query")==0)  
      {  
        cin>>a>>b;  
        SUM=0;//初始为零  
        query(a,b,1);//从 根节点t[1]开始  
        cout<<SUM<<endl;  
      }
      else if(strcmp(command,"Add")==0)  
      {  
        cin>>a>>b;  
        add(a,b,1);//从 根节点t[1]开始  
      }
      else if(strcmp(command,"Sub")==0)  
      {  
        cin>>a>>b;  
        sub(a,b,1);//从 根节点t[1]开始  
      }  
    }  
  }  
  return 0;  
}  

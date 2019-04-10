//��������������Ұ�� 
#include<iostream>  
#include<string>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
  
const int INF=99999999;  
const int N=100;  
  
int n,m;//nΪ�ߵ�����,m��ʾ�޶�ֵ  
int cnt;//��������Ľ����  
int set[N];  
bool flag[N][N];//�ñ��Ƿ�����С�������ı��  
int G[N][N];  
int ans;  
  
map<string,int> Map;  
  
struct node  
{  
  int x,y,v;  
} a[N*N];  
  
struct edge  
{  
    int x,y,v;  
}dp[N];//dp[v]Ϊ·��v0-v����v0�޹�����Ȩֵ���ı�  
  
int get_num(string s)//���ַ���ӳ�䵽���ֽڵ�
{  
  if(Map.find(s)==Map.end())//û���������ü�ֵ  
    Map[s]=++cnt;//��Ӧ��ͼ,���ַ���ӳ�䵽���ֽڵ�    
  // cout<<"  Map[" << s << "]=="<<Map[s]<<endl;  
  return Map[s];  
}  
  
bool cmp(node a,node b)  
{  
  return a.v<b.v;  
}  
  
int find_father(int x)  
{  
  if(x!=set[x])  
    set[x]=find_father(set[x]);  
  return set[x];  
}  
  
inline void union_set(int x,int y)  
{  
    set[y]=x;  
}  
  
void kruskal()//��m����ͨ��������С������  
{  
  for(int i=1; i<=n; i++)  
  {  
    if(a[i].x==1||a[i].y==1)  
      continue;  
    int x=find_father(a[i].x);  
    int y=find_father(a[i].y);  
    if(x==y)  
      continue;  
    flag[a[i].x][a[i].y]=flag[a[i].y][a[i].x]=true;//���Ϊ��С������  
    set[y]=x;//�ϲ�����  
    ans+=a[i].v;//��С������Ȩֵ�ۼ�  
  }  
} 
 
/*��dp(v)Ϊ·��v0-v����v0�޹�����Ȩֵ���ı�; 
����father(v)Ϊv�ĸ����,�ɴ˿��Եõ�״̬ת�Ʒ���: 
dp(v)=max(dp(father(v)),��(father(v),v)); 
�߽�����Ϊdp[v0]=-��(��Ϊÿ��Ѱ�ҵ�������,����-�޲��ᱻ����),
dp[v']=-��|(v0,v')��E(T);
*/  
void dfs(int x,int father)  
{  
  for(int i=2; i<=cnt; i++)  
    if(i!=father && flag[x][i])//����ߣ�x,i��������������,�Ҳ�������ڵ�ѭ�� 
    {  
      if(dp[i].v==-1)//�������V0��i��Ķ�  
        if(dp[x].v>G[x][i])//dp(v)=max(dp(father(v)),��(father(v),v));    
          dp[i]=dp[x];  
        else  
        {  
          dp[i].v=G[x][i];//���»�·�����ߵ�ֵ  
          dp[i].x=x;  
          dp[i].y=i;  
        }  
      dfs(i,x);//���Ŵ�i�ڵ㿪ʼ����dfs  
    }  
}  
  
void solve()  
{  
  int tmp[N],Min[N];  
  for(int i=1; i<=cnt; i++)  
    Min[i]=INF;  
  sort(a+1,a+1+n,cmp);//�Խڵ��������  
  kruskal();//��С������  
  for(int i=2; i<=cnt; i++) //ö�ٳ�V0�����нڵ�  
    if(G[1][i]!=-1)//���V0��ö�ٵ�i���б����  
    {  
      int t=find_father(i);//���i�������ĸ���ͨ����  
      if(Min[t]>G[1][i])//��ÿ����ͨ�����кͶ���1���ӵ���СȨ��  
      {  
        tmp[t]=i; //ȷ������ͨ������Ҫ��V0���ӵĵ� 
        Min[t]=G[1][i];  
      }  
    }  
      
  int t=0;//t��ʾ��С�޶�  
  for(int i=1; i<=cnt; i++)//��V0����һ���ߵ�����ͨ����������K����С����ֵ  
    if(Min[i]!=INF)  
    {  
      t++;  
      flag[1][tmp[i]]=flag[tmp[i]][1]=true;//�����ӵı߱��Ϊ��С������  
      ans+=G[1][tmp[i]]; //������С������Ȩֵ 
    }  
          
  for(int i=t+1; i<=m; i++)//ö��t��m��������С������,���𲽽�v0��Ķȼ�1��m  
  {  
    memset(dp,-1,sizeof(dp));//dp[v]Ϊ·��v0-v����v0�޹�����Ȩֵ���ı�;  
    dp[1].v=-INF;  
    for(int j=2; j<=cnt; j++)  
      if(flag[1][j])//���V0��j��Ϊ�������ϵı�  
        dp[j].v=-INF;//���ñߵ�Ȩֵ��Ϊ�������  
    dfs(1,-1);//�����������  
    int tmp,Min=INF;  
    for(int j=2; j<=cnt; j++)//�ҵ���V0������ͨ��������С��  
      if(G[1][j]!=-1)  
      {  
        if(Min>G[1][j]-dp[j].v)  
        {  
          Min=G[1][j]-dp[j].v;  
          tmp=j;  
        }  
      }  
    if(Min>=0)//�Ҳ��������ı�,��˵���Ѿ����  
      break;  
    flag[1][tmp]=flag[tmp][1]=true;//�������Ķ���ӵ�MST��  
    int x=dp[tmp].x;//ɾ�����ϵ���������  
    int y=dp[tmp].y;  
    flag[x][y]=false;  
    flag[y][x]=false;  
    ans+=Min;  
  }  
  printf("Total miles driven: %d\n",ans);  
}  

void init()  
{  
  ans=0;  
  cnt=1;  
  Map["Park"]=1;  
  memset(flag,0,sizeof(flag));  
  memset(G,-1,sizeof(G));  
  scanf("%d",&n);  
  for(int i=1; i<N; i++)//���鼯��ʼ��  
    set[i]=i;  
  string s;  
  for(int i=1; i<=n; i++)  
  {  
    cin>>s;  
    a[i].x=get_num(s);//��øõ�ַ��ͼ�еĽڵ����  
    cin>>s;  
    a[i].y=get_num(s);  
    cin>>a[i].v;  
    if(G[a[i].x][a[i].y]==-1)  
      G[a[i].x][a[i].y]=G[a[i].y][a[i].x]=a[i].v;  
    else//���ر�  
      G[a[i].x][a[i].y]=G[a[i].y][a[i].x]=min(G[a[i].y][a[i].x],a[i].v);  
    }  
    scanf("%d",&m);//m��ʾ�޶�ֵ  
}  
 
int main()  
{   
  init();  
  solve();  
  return 0;  
}  

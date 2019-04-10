//¥������ 
#include <iostream>
#include <cstdlib>
using namespace std;

int a[100001],b[100001];
int link[100001],v[100001],p[100001];//v[]����ͳ�Ƽ�¼����Ԫ���±� 
int tot;

void swap(int &a,int &b)//����a��b��ǰ��ֵ
{
  int t;
  t=a;a=b;b=t;
}

void init(int n)//��ʼ���������鵹�� 
{
  int t,i;
  for(i=1;i<=n;i++)
  {t=b[i],b[i]=b[n-i+1],b[n-i+1]=t;}
}

int find(int key)//���ֲ����±�
{
  int mid,L,R;
  L=1,R=tot;
  while(L<=R)
  {
    mid=(L+R)/2;
    if(b[v[mid]]<key)
      L=mid+1;
    else
      R=mid-1;
  }
  return L-1;
}

void sort(int L,int R)
{
  if(L>=R)  
    return ;
  int i,j,k;
  k=a[(L+R)/2];
  i=L,j=R;
  while(i<=j)
  {
    while(a[i]<k)   i++;
    while(a[j]>k)   j--;
    if(i<=j)
    {
      swap(a[i++],a[j--]);
      swap(b[i++],b[j--]);             
    }
  }
  sort(L,j);
  sort(i,R);
}

int main()
{
  freopen("Treasure_map.in","r",stdin);
  freopen("Treasure_map.out","w",stdout);  
  int i,j,n,m,k,L;
  cin>>n>>m>>k;//��һ��m*n�ľ����� k������ 
  for(i=1;i<=k;i++)
    cin>>a[i]>>b[i],p[i]=i;//���ص�����aΪ�����꣬bΪ������ 
  sort(1,n);//�Ժ������������ Ȼ����֮ΪȨ��������������� 
  init(n);
  tot=1,v[tot]=1,link[1]=p[1];
  //totָ����������еĳ��ȣ�p[]��ʾ���е��±꣬link[]��ʾ���� 
  for(i=2;i<=k;i++)
  {
    if(b[p[i]]<=b[v[tot]])
    {
      tot++;
      v[tot]=p[i];
      link[p[i]]=v[tot-1];
    }
    else
    {
      L=find(b[p[i]]);
      v[L+1]=p[i];
      link[p[i]]=v[L];
    }
  }
  cout<<tot<<endl;//ֻ���ӡ���� 
  return 0;
}

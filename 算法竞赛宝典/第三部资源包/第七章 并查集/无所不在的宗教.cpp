//�������ڵ��ڽ� 
#include<iostream>   
using namespace std;   
  
int father[50001];   
int rank[50001];//rankֵ��¼���ĸ߶�   
  
int find(int x)//���ң����Ѳ���·���ϵĽ�㶼ָ������Լ�С���ĸ߶� 
{   
  if(x!=father[x])
    father[x]=find(father[x]);//·��ѹ��   
  return father[x];   
}   
  
void Union(int x,int y)//�ϲ�
{   
  int r1=find(x);   
  int r2=find(y);   
  if(r1==r2)//��Ԫ������ͬһ�������˳� 
    return;   
  if(rank[r1]<rank[r2])////rankֵ��С�ļ��Ϻϲ�����ļ����� 
    father[r2]=r1;   
  else
  {   
    if(rank[r1] == rank[r2])//rankֵ��ȵ����ϲ���rankҪ����һ    
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
      father[i]=i;//ע������ָ������   
      rank[i]=0;//���ĳ�ʼ���Ϊ0            
    }   
    for(i=0;i<m;i++)
    {   
      cin>>a>>b;   
      int x=find(a);   
      int y=find(b);   
      if(x!=y)//���ڲ�ͬ�ļ��ϣ���ϲ�
      {   
        n--;//�ڽ�����һ   
        Union(x,y);   
      }   
    }   
    cout<<"Case "<<Case<<": "<<n<<endl;   
  }   
  return 0;   
}

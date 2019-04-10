//���鼯 
#include <iostream>
using namespace std;
int N,M,Q;
int father[20001];

int find(int x) //�ж�x�����ļ��� 
{ 
  int root=x;
  while(father[root]>=0)//�ҵ����յĸ���� 
    root=father[root];
  while(root!=x) //ѹ��·�� 
  { 
    int temp=father[x]; 
    father[x]=root; 
    x=temp; 
  } 
  return root; 
} 

void Union(int a,int b) //�ϲ�������ͬ���ϵ�Ԫ�� 
{ 
  int temp=father[a]+father[b]; 
  if(father[a]>father[b]) //��С������Ϊ�ϴ���������� 
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
  for(i=1;i<=N;i++)//��ʼ�� 
    father[i]=-1; //���ڵ�ĸ�����Ϊ-1
  for(i=1;i<=M;i++)
  {
    cin>>a>>b;
    if(find(a)!=find(b))
      Union(a,b);//��ͨ
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

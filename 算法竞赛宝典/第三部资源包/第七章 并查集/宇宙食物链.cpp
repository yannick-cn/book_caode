//����ʳ���� 
#include <iostream>
using namespace std;

int father[50005];
int rank[50005];

void Sent(int x)//��ʼ������ 
{
  father[x]=x;
  rank[x]=0;
}

//����x�ļ��ϣ�����ʱѹ��·�������޸�x��father[x]�Ĺ�ϵ 
int Find_set(int x)
{
  int t; 
  if(x!=father[x])
  {
    t = father[x];
    father[x]= Find_set(father[x]);
    //����x��father[X]�Ĺ�ϵ 
    rank[x] = (rank[x]+rank[t])%3;
  }
  return father[x];
}

void Union(int x,int y,int d)//�ϲ�x,y���ڵļ���
{
  int xf = Find_set(x);
  int yf = Find_set(y);  
  father[xf] = yf;//������xf�ϲ���yf������ 
  rank[xf]=(rank[y]-rank[x]+3+d)%3;//���� xf ��father[xf]�Ĺ�ϵ
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
    if(x>n||y>n||(d==2 && x == y))//���x��y��n�󣬻�x��x���Ǽٻ�
      total++;                 
    else
    {
      xf = Find_set(x);
      yf = Find_set(y);
      //���x��f�ĸ��ڵ���ͬ ����ô�����жϸ����Ĺ�ϵ�Ƿ���ȷ�� 
      if(xf == yf)
      {
        if((rank[x]-rank[y]+3)%3 != d-1)
          total++;                              
      }
      else
        Union(x,y,d-1);//����ϲ�x��y 
    }
  }
  cout<<total<<endl;
  return 0;
}



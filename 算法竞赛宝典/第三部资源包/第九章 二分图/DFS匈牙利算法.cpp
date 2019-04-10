#include <iostream>
using namespace std;

int n, m, k;
int link[101]; //����link[1]=3����Ů1����3��ƥ�� ����
bool visit [101]; //��¼Ů�˶�Ա�ڵ��Ƿ񱻷��ʹ� ����
bool map[101][101];//map[a][b]=1����a,b�����б����� ����

bool dfs(int a)
{
  for (int i=1;i<=m;i++)//����Ů�˶�Ա 
    if (map[a][i]==1&&!visit[i]) //�綥��i��a�б���δ������ 
    {
      visit[i] = true; //���iΪ�ѷ��� 
      if(link[i]==0||dfs(link[i]))//��iδ��ƥ��M�У���iƥ��Ľڵ�������· ��
      {
        link[i]=a; //���ת
        return true; //���� ����
      }
    }
  return false;//������·�򷵻�false 
}

int main()
{
  int a,b,ans=0;
  cin>>n>>m>>k;//n,mΪ�С�Ů�˶�Ա������kΪ����
  for(int i=1;i<=k;i++)
  {
    cin>>a>>b;
    map[a][b]=true;
  }
  for (int i=1; i<=n; i++)//������˶�Ա���� 
  {
    memset(visit, 0, sizeof(visit));//����ϴνڵ���ʱ��
    if (dfs(i))
      ans++; //�ӽڵ�i������չ
  }
  cout<<ans<<endl;
  return 0;
}

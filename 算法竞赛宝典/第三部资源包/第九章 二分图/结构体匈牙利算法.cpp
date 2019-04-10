#include <iostream>
#include <cstring>
using namespace std;

//��������
struct link
{
    int data; //�������
    link* next; //ָ����һ���ڵ�
    link(int=0);
};
link::link(int n)//d����link���һ�ּ̳й�ϵ
{
    data=n;
    next=NULL;
}

int n1,n2,m,ans=0;
int result[101]; //��¼n1�еĵ�ƥ��ĵ�ı��
bool state [101]; //��¼n1�е�ÿ�����Ƿ�������
link *head [101]; //��¼n2�еĵ���ڽӽڵ�
link *last [101]; //�ڽӱ����ֹλ�ü�¼

//�ж��ܷ��ҵ��ӽڵ�n��ʼ������·
bool find(const int n)
{
    link* t=head[n];
    while (t!=NULL) //n����δ���ҵ��ڽӽڵ�ʱ
    {
        if (!(state[t->data])) //����ڽӵ�t->dataδ�����ҹ�
        {
            state[t->data]=true; //���t->dataΪ�Ѿ����ҹ�
            if ((result[t->data]==0) || //���t->data������ǰһ��ƥ��M
            (find(result[t->data]))) //���t->dataƥ�䵽�Ľڵ����Ѱ�ҵ�����·
            {
                result[t->data]=n; //��ô���Ը���ƥ��M',����n1�еĵ�t->dataƥ��n
                return true; //����ƥ��ɹ��ı�־
            }
        }
        t=t->next; //����������һ��n���ڽӽڵ�
    }
    return false;
}

int main()
{
    int t1=0, t2=0;
    cin>>n1>>n2>>m;
    for (int i=0; i<m; i++)
    {
        cin>>t1>>t2;
        if (last[t1]==NULL)
            last[t1]=head[t1]=new link(t2);
        else
            last[t1]=last[t1]->next=new link(t2);
    }
    for (int i=1; i<=n1; i++)
    {
        memset(state, 0, sizeof(state));
        if (find(i)) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

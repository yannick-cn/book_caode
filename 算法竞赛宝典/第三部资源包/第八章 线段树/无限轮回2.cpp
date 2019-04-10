//�����ֻأ��߶��� 
#include<iostream>
#define LL(x) ((x)<<1)  //������
#define RR(x) ((x)<<1|1)  //����+1��
using namespace std;

struct Seg_Tree 
{
  int left,right,val;
  int calmid() 
  {
		return (left+right)/2;
  }
}tt[15000];

int val[5001];//�������� 

void build(int left,int right,int idx)
{
	tt[idx].left = left;
	tt[idx].right = right;
	tt[idx].val = 0;
	if(left == right) 
      return ;	
	int mid = tt[idx].calmid();
	build(left,mid,LL(idx));
	build(mid+1,right,RR(idx));
}

//��ѯ��[left��right]�������ж�����������left���������
int query(int left,int right,int idx) 
{
  if(left == tt[idx].left && right == tt[idx].right) 
    return tt[idx].val;
  int mid = tt[idx].calmid();
  if(right <= mid) 
    return query(left,right,LL(idx)); 
  else if(mid < left) 
    return query(left,right,RR(idx)); 
  else 
    return query(left,mid,LL(idx)) + query(mid+1,right,RR(idx));
}

//�������а���id������������valֵ����+1��
void update(int id,int idx) 
{
  tt[idx].val ++;	
  if(tt[idx].left == tt[idx].right) 
    return ;
  int mid = tt[idx].calmid();
  if(id <= mid) 
    update(id,LL(idx));
  else 
    update(id,RR(idx));
}

int main() 
{
  int i,n,sum;
  while(scanf("%d",&n) == 1) 
  {
    build(0,n-1,1);
    for(i=0;i<n;i++)
      sum = 0;	
    for(i=0;i<n;i++)
    {
	  scanf("%d",&val[i]);
      sum += query(val[i],n-1,1);//��ʱval[i]��δ�������� 
      update(val[i],1);//��ʱ����val[i]���������� 
    }
    int ret = sum;
	for(i=0;i<n;i++)
    {
	  sum = sum - val[i] + (n - val[i] - 1);
	  ret=min(ret,sum);
	}
	printf("%d\n",ret);
  }
  return 0;
}

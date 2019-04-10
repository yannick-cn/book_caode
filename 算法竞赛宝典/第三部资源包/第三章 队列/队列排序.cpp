//队列排序 
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define N 100
struct node
{
  int data;
  struct node *next;
};
struct hnode
{
  struct node *link;
} HQ[MAX];

int main()
{
  int A[N],n,i,first=1;
  struct node *p,*s,*head;
  printf("请输入数值的个数n:");
  scanf("%d",&n);
  for (i=0;i<MAX;i++)
    HQ[i].link=NULL;
  for (i=0;i<n;i++)
    do
    {
	  printf("第%d个数:",i+1);
	  scanf("%d",&A[i]);
	} while (A[i]<0 || A[i]>9);
  for (i=0;i<n;i++)
  {
    s=(struct node *)malloc(sizeof(struct node));
    s->data=A[i];s->next=NULL;
	if (HQ[A[i]].link==NULL)
	   HQ[A[i]].link=s;
    else
    {
	  p=HQ[A[i]].link;
	  while (p->next!=NULL)
        p=p->next; /*p指向该链表的最后一个结点*/
      p->next=s;
    }
  }
  head=(struct node *)malloc(sizeof(struct node));
  head->next=NULL;
  for (i=0;i<MAX;i++)
  {
	if (HQ[i].link!=NULL)
    {
      if (first)
      {
        head->next=HQ[i].link;first=0;
	    p=head;
	    while (p->next!=NULL) 
          p=p->next; /*p指向最后结点*/
      }
      else
      {
        p->next=HQ[i].link;
        p=HQ[i].link;
	    while (p->next!=NULL)
          p=p->next;
      }
    }
  }
  printf("\n显示所有元素:\n");
  if (head->next!=NULL)
    head=head->next;
  while (head!=NULL)
  {
    printf("%d ",head->data);
    head=head->next;
  }
  system("pause");
  return 0;
}

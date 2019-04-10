//搭档问题 
#include <iostream>
using namespace std;
#define maxsize 100

typedef struct
{
  char data[maxsize];
  int front,rear;  
}seqQueue;


void iniqueue(seqQueue *M,int m)//队列初始化 
{ 
   scanf("%s",M->data);
   M->front=0;
   M->rear=m;
}

void addqueue(seqQueue *q,int m)//队列插入结点 
{  
   q->front=(q->front+1)%m;
   q->rear=(q->rear+1)%m; 
}

char outqueue(seqQueue *q,int m)//队列删除结点 
{
  if(q->rear==q->front)
    return NULL; 
  else
  {
    q->front=(q->front+1)%m;
    return q->data[q->front];
  }
}

int main()
{
  int n,m,k,i,j;
 
  seqQueue M,F; 
  scanf("%d%d%d",&n,&m,&k);

  iniqueue(&M,n);
  iniqueue(&F,m);
  if(n<m)
  {
    for(i=0;i<k-1;i++)
    {
      for(j=0;j<n;j++)
      {
        addqueue(&M,n);
        addqueue(&F,m);
      }   
    }
    for(i=0;i<n;i++)
    {  
      printf("%c ",M.data[M.front]);
      printf("%c\n",F.data[F.front]);
      addqueue(&M,n);
      addqueue(&F,m);
    }
  }
  else
  {
    for(i=0;i<k-1;i++)
    {
      for(j=0;j<m;j++)
      {
        addqueue(&F,m);
        addqueue(&M,n);
      } 
    }
    for(i=0;i<m;i++)
    {  
      printf("%c ",M.data[M.front]);
      printf("%c\n",F.data[F.front]);
      addqueue(&M,n);
      addqueue(&F,m);
    }
  }
  system("pause");
  return 0;
}

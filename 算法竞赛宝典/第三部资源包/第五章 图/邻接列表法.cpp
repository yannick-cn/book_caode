//�ڽ��б� 
#include <iostream>
using namespace std;
#define Num 6

struct Node
{
  int vertex;
  struct Node *next;
};
typedef struct Node *Graph;
Node Head[Num];

void CreateG(int node1,int node2)
{
  Graph pointer;
  Graph New;
  
  New=(Graph)malloc(sizeof(struct Node));//�����½�� 
  if(New!=NULL)//�����㿪�ٳɹ� 
  {
    New->vertex=node2;
    New->next=NULL;
    pointer=&(Head[node1]);
    while(pointer->next!=NULL)
      pointer=pointer->next;
    pointer->next=New;//���½������ 
  }         
}

void printGraph()//��ӡ�ڽ��б� 
{
  Graph pointer;
  int i,j;
  for(i=0;i<Num;i++)
  {
    pointer=Head[i].next;
    printf("Head[%d]",i);
    while(pointer!=NULL)
    {
      printf("-> %d ",pointer->vertex);
      pointer=pointer->next;                    
    }                                    
    printf("\n");   
  }   
}

int main()
{
  int i,j;  
  int node1;
  int node2;
  for(i=0;i<Num;i++)  //����ֵ 
  {
    Head[i].vertex=i;
    Head[i].next=NULL;                  
  }
  while(1)
  {
    printf("-------------------------\n");      
    printf("��������ʼ��:  ");        
    scanf("%d",&node1);
    if(node1==-1)
      break;
    printf("�����������:  ");
    scanf("%d",&node2);
    
    if(node1==node2)
      printf("����,����ѭ��!\n");
    else if(node1>=Num || node2>=Num)
      printf("����,������Χ!");
    else
      CreateG(node1,node2);              
  }           
  printf("\n�ڽ��б�Ϊ:\n");
  printGraph();  
  system("pause"); 
  return 0; 
}

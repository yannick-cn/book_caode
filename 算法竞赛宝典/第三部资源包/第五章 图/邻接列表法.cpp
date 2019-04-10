//邻接列表法 
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
  
  New=(Graph)malloc(sizeof(struct Node));//开辟新结点 
  if(New!=NULL)//如果结点开辟成功 
  {
    New->vertex=node2;
    New->next=NULL;
    pointer=&(Head[node1]);
    while(pointer->next!=NULL)
      pointer=pointer->next;
    pointer->next=New;//将新结点链接 
  }         
}

void printGraph()//打印邻接列表 
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
  for(i=0;i<Num;i++)  //赋初值 
  {
    Head[i].vertex=i;
    Head[i].next=NULL;                  
  }
  while(1)
  {
    printf("-------------------------\n");      
    printf("请输入起始点:  ");        
    scanf("%d",&node1);
    if(node1==-1)
      break;
    printf("请输入结束点:  ");
    scanf("%d",&node2);
    
    if(node1==node2)
      printf("错误,自身循环!\n");
    else if(node1>=Num || node2>=Num)
      printf("错误,超出范围!");
    else
      CreateG(node1,node2);              
  }           
  printf("\n邻接列表为:\n");
  printGraph();  
  system("pause"); 
  return 0; 
}

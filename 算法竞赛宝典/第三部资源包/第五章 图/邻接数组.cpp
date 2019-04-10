//邻接数组
#include <stdio.h>
#include <stdlib.h>
#define Max 6
int graph[Max][Max]={0};

void printGraph()
{
  int i,j;
  for(i=0;i<Max;i++)
  {
    for(j=0;j<Max;j++)
      printf("%d  ",graph[i][j]);       
    printf("\n");   
  }   
}

int main()
{
  int i,j;  
  int node1;
  int node2;
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
    else if(node1>=Max || node2>=Max)
      printf("错误,超出范围!");
    else
      graph[node1][node2]=1;              
  }           
  printf("\邻接数组为:\n");
  printGraph();  
  system("pause");  
  return 0;
}

//�ڽ�����
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
    printf("��������ʼ��:  ");        
    scanf("%d",&node1);
    if(node1==-1)
      break;
    printf("�����������:  ");
    scanf("%d",&node2);
    
    if(node1==node2)
      printf("����,����ѭ��!\n");
    else if(node1>=Max || node2>=Max)
      printf("����,������Χ!");
    else
      graph[node1][node2]=1;              
  }           
  printf("\�ڽ�����Ϊ:\n");
  printGraph();  
  system("pause");  
  return 0;
}

//基数排序 
#include<iostream>
using namespace std; 

int maxbit(long L[],long n)  //辅助函数，求数据的最大位数 
{  
  int d = 1,i=0; //保存最大的位数 
  int p=10; 
  for(i = 0;i < n; i++) 
  { 
     while(L[i] >= p) 
     { 
       p *= 10; 
       d++; 
     } 
  } 
  return d; 
} 

void radixsort(long L[],long len)//基数排序   
{  
  int d = maxbit(L,len);  
  long * tmp  = (long *)malloc(len*sizeof(long)); 
  long * count  = (long *)malloc(10*sizeof(long));; //计数器,10个桶  
  long i,j,k; 
  int radix = 1; 
  for(i = 1; i <= d; i++) //进行d次排序  
  {      
    for(j = 0; j < 10;j++) //每次分配前清空计数器 
      count[j] = 0;  
    for(j = 0;j < len; j++)//统计每个桶中的记录数  
    {  
      k = (L[j]/radix)%10;  
      count[k]++; 
    } 
    for(j = 1;j < 10; j++) //将tmp中的位置依次分配给每个桶  
      count[j] = count[j-1] + count[j]; 
    for(j = len-1;j >= 0;j--)//将所有桶中记录依次收集到tmp中  
    {  
      k = (L[j]/radix)%10; 
      count[k]--; 
      tmp[count[k]] = L[j]; 
    } 
    for(j = 0;j < len;j++) //将临时数组的内容复制到L中 
      L[j] = tmp[j]; 
    radix = radix*10; 
  }  
  free(tmp); 
  free(count); 
}  

long RandomInteger(long low,long high)//产生随机数 
{ 
  long k; 
  k=(long)(rand()%(high-low+1)+low); 
  return k;  
}  

int main() 
{ 
  long i=0; 
  long * L  = (long *)malloc(10000*sizeof(long));
  srand( (long)time( NULL ) );  
  for(i=0;i<100;i++) 
    L[i]=RandomInteger(0,100); 
  radixsort(L,100); 
  for(i=0;i<100;i++) 
    printf("%7.2ld   ",L[i]); 
  getchar(); 
  return 0; 
}   

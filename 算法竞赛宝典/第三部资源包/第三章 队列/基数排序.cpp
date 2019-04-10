//�������� 
#include<iostream>
using namespace std; 

int maxbit(long L[],long n)  //���������������ݵ����λ�� 
{  
  int d = 1,i=0; //��������λ�� 
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

void radixsort(long L[],long len)//��������   
{  
  int d = maxbit(L,len);  
  long * tmp  = (long *)malloc(len*sizeof(long)); 
  long * count  = (long *)malloc(10*sizeof(long));; //������,10��Ͱ  
  long i,j,k; 
  int radix = 1; 
  for(i = 1; i <= d; i++) //����d������  
  {      
    for(j = 0; j < 10;j++) //ÿ�η���ǰ��ռ����� 
      count[j] = 0;  
    for(j = 0;j < len; j++)//ͳ��ÿ��Ͱ�еļ�¼��  
    {  
      k = (L[j]/radix)%10;  
      count[k]++; 
    } 
    for(j = 1;j < 10; j++) //��tmp�е�λ�����η����ÿ��Ͱ  
      count[j] = count[j-1] + count[j]; 
    for(j = len-1;j >= 0;j--)//������Ͱ�м�¼�����ռ���tmp��  
    {  
      k = (L[j]/radix)%10; 
      count[k]--; 
      tmp[count[k]] = L[j]; 
    } 
    for(j = 0;j < len;j++) //����ʱ��������ݸ��Ƶ�L�� 
      L[j] = tmp[j]; 
    radix = radix*10; 
  }  
  free(tmp); 
  free(count); 
}  

long RandomInteger(long low,long high)//��������� 
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

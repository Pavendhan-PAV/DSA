#include<stdio.h>
#include<string.h>
void main()
{
 char a[100];
 int n,t;
 
 printf("\nEnter characters:",n);
 scanf("%s",a);
 n=strlen(a);
 
 for(int i=0;i<n;++i)
 for(int j=0;j<n-1-i;j++)
 {
  if(a[j]>a[j+1])
  {
   t=a[j];
   a[j]=a[j+1];
   a[j+1]=t;
  }
 }
 printf("\nSorted characters: %s",a); 
 }

#include<stdio.h>
void main()
{
 int i,j,t,n,a[100];
 printf("\nEnter the number of elements:");
 scanf("%d",&n);
 printf("\nEnter the elements:");
 for(int m=0;m<n;m++)
 scanf("%d",&a[m]);
 printf("\nEnter the new number:");
 scanf("%d",&a[n]);
 for(i=0;i<n+1;i++)
 {
  t=a[i];
  j=i;
  while(j>0&&t<a[j-1])
  {
   a[j]=a[j-1];
   j=j-1;
  }
  a[j]=t;
 }
 
 printf("\nThe array is sorted as:");
 for(int m=0;m<n+1;m++)
 printf("\n%d",a[m]);
}  

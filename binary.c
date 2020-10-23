#include<stdio.h>

void main()
{
 char a[100],b;
 int c,beg=0,end,mid,flag=0;
 
 printf("Enter number of characters:");
 scanf("%d",&c);
 end=c;
  
 printf("\nEnter %d characters in ascending order:",c);
 scanf("%s",a);
 
 printf("\nEnter the character to be searched for:");
 scanf("%s",&b);
 
 while(beg<=end)
 { 
  mid=(beg+end)/2;
   if(b==a[mid])
   {
   printf("\nFound at %d position.",mid+1);
   flag=1;
   break;
   }
  
  else if(b>a[mid])
  beg=mid+1;
  
  else
  end=mid-1; 
   
 }
 if(flag==0)
 printf("\nNot found!");
}

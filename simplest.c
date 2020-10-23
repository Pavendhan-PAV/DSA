#include<stdio.h>
struct rational
{
 int num;
 int den;
}r1;

void main()
{
 int gcd,max;
 printf("\nEnter the numerator and denoiminator resp:");
 scanf("%d%d",&r1.num,&r1.den);
 printf("\nGiven rational number: %d/%d",r1.num,r1.den);
 if(r1.num>r1.den)
 max=r1.num;
 
 else max=r1.den;
 
 for(int i=1;i<=max;i++)
 if((r1.num%i==0)&&(r1.den%i==0))
 gcd=i;
 
 r1.num=r1.num/gcd;
 r1.den=r1.den/gcd;
 
 printf("\nSimplest form of the rational number: %d/%d",r1.num,r1.den);
}

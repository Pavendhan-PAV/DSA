#include<stdlib.h>
#include<stdio.h>
#include<math.h>

struct poly
{
 int a;
 int size;
 struct poly *np;
};
struct poly *hp=NULL;

void insert(int c, int i)
{
 struct poly *p2=(struct poly *)malloc(sizeof(struct poly));
 struct poly *thp=hp;
 p2->a=c;
 int j=0;
 if(hp==NULL)
 {
  p2->np=hp;
  hp=p2;
 }
 else
 {
  while(j<i-1)
 {
  thp=thp->np;
  j++;
 }
 p2->np=thp->np; 
 thp->np=p2;
 }
}

void eval(struct poly *p1,int x)
{
 int val=0;
 struct poly *thp=hp;
 for(int i=0;i<p1->size;i++)
  {
   printf("%d",thp->a);
   val=val+((thp->a)*pow(x,i));
   thp=thp->np;
  }
 printf("\nEvaluated value: %d ",val);
}


void main()
{
 int d,x,c,i=0;
 printf("\nEnter the degree of the polynomial:");
 scanf("%d",&d);
 struct poly *p1;
 p1->size=d+1;
 printf("\nEnter the coefficients starting from a0: ");
 while(i<(d+1))
 {
  scanf("%d",&c);
  insert(c,i);
  i++; 
 }
 
 printf("\nEnter the value of x for evaluation:");
 scanf("%d",&x);
 eval(p1,x);
} 
























#include<stdio.h>
#include<math.h>

struct poly
{
 int a[100];
 int size;
};

void insert(struct poly *p1,int c, int i)
{
 p1->a[i]=c;
 p1->size+=1;
}

void eval(struct poly *p1,int x)
{
 int val=0;
 for(int i=0;i<p1->size;i++)
 {
  val=val+((p1->a[i])*pow(x,i));
 }
 printf("\nEvaluated value: %d ",val);
}


void main()
{
 int d,x,c,i=0;
 printf("\nEnter the degree of the polynomial:");
 scanf("%d",&d);
 
 struct poly *p1;
 p1->size=0;
 printf("\nEnter the coefficients starting from a0: ");
 while(i<(d+1))
 {
  scanf("%d",&c);
  insert(p1,c,i);
  i++; 
 }
 
 printf("\nEnter the value of x for evaluation:");
 scanf("%d",&x);
 eval(p1,x);
} 
























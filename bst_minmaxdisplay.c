#include<stdio.h>
#include<stdlib.h>

int a[100],i=0;
struct node
{
 int data;
 struct node *lptr;
 struct node *rptr;
};
struct node *tptr=NULL;

void insert(int x);
void min();
void max();
void io(struct node *ptr);
void m(int a[],int i);
void main()
{
 insert(50);
 //insert(45);
 //insert(47);
 //insert(46);
 //insert(52);
 //insert(74);
 //insert(85);
 //insert(78);
 //insert(76);
//min();
//max(); 
 io(tptr);
 m(a,i);
}

void insert(int x)
{
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 temp->data=x;
 temp->lptr=temp->rptr=NULL;
 if(tptr==NULL)
 tptr=temp;
 else
 {
  struct node *ptr=tptr;
  struct node *pptr=NULL;
  while(ptr!=NULL)
  {
   pptr=ptr;
   if(x<ptr->data)
   ptr=ptr->lptr;
   else
   ptr=ptr->rptr;  
  }
  if(x<pptr->data)
  pptr->lptr=temp;
  else
  pptr->rptr=temp;
 } 
}

void min()
{
 struct node *ptr=tptr;
 struct node *pptr=NULL;
 while(ptr->lptr!=NULL)
 {
  pptr=ptr;
  ptr=ptr->lptr; 
 }
 if(ptr->rptr!=NULL)
 {
  if((ptr->rptr)->data < pptr->data)
  printf("\nMIN 1='%d'\nMIN 2='%d'",ptr->data,(ptr->rptr)->data);
  else
  printf("\nMIN 1='%d'\nMIN 2='%d'",ptr->data,pptr->data);
 }
 else
 printf("\nMIN 1='%d'\nMIN 2='%d'",ptr->data,pptr->data); 
}

void max()
{
 struct node *ptr=tptr;
 struct node *pptr=NULL;
 while(ptr->rptr!=NULL)
 {
  pptr=ptr;
  ptr=ptr->rptr; 
 }
 if(ptr->lptr!=NULL)
 {
  if((ptr->lptr)->data > pptr->data)
  printf("\nMAX 1='%d'\nMAX 2='%d'",ptr->data,(ptr->lptr)->data);
  else
  printf("\nMAX 1='%d'\nMAX 2='%d'",ptr->data,pptr->data);
 }
 else
 printf("\nMAX 1='%d'\nMAX 2='%d'",ptr->data,pptr->data);
}


void io(struct node *ptr)
{
 
 if(ptr!=NULL)
 {
  io(ptr->lptr);
  printf("	%d",ptr->data); 
  a[i]=ptr->data;i+=1;
  io(ptr->rptr);
 }
}

void m(int a[],int i)
{
 if(i-2>=0)
 printf("\nmin1=%d\nmin2=%d\nmax1=%d\nmax2=%d",a[0],a[1],a[i-1],a[i-2]);
 //else if(i=1)
 //printf("\n no tree!");
 else
 printf("\nmin1=%d\nmin2='doesn't exist'\nmax1=%d\nmax2='doesn't exitst'",a[0],a[0]);
}

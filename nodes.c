#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int c=0;
struct node
{
 int data;
 struct node *lptr,*rptr;
};
struct node *tptr=NULL;

void insert(int x);
int height(struct node *ptr);

void main()
{
 insert(2);
 insert(1);
 insert(5);
 insert(7);
 insert(3);
 insert(11);
 insert(4);
 printf("\nNumber of nodes: %d \n",c);
printf("\nHeight: %d\n",height(tptr));
}

void insert(int x)
{
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 c++;
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


int height(struct node *ptr)
{
 while(ptr!=NULL)
 return height(ptr->lptr)>height(ptr->rptr)?height(ptr->lptr)+1:height(ptr->rptr)+1;
} 


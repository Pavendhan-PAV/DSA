#include<stdio.h>
#include<stdlib.h>

struct large
{
 int data; 
 struct large *nptr;
};

struct large *hptr=NULL;

void insert(char c,int pos);
void display();

void main()
{
 int n,j=0;
 char a[100];
 printf("Enter the no. of digits: ");
 scanf("%d",&n);

 printf("\nEnter a large integer of length %d :",n);
 for(int i=0;i<n;i++)
 scanf(" %c",&a[i]);

 while(j<n)
 {
  insert(a[j],j);
  j++;
 }
 display();
}

void insert(char c,int pos)
{
 int i=0;
 struct large *temp=(struct large*)malloc(sizeof(struct large));
 struct large *thptr=hptr;
 temp->data=((int)c-48);
 if(pos==0)
 {
  temp->nptr=hptr;
  hptr=temp;  
 }
 else
 {
  while(i<pos-1)
  {
   thptr=thptr->nptr;
   i++;
  }
  temp->nptr=thptr->nptr;
  thptr->nptr=temp;
 }
} 
 void display()
 {
  struct large *thptr=hptr;
  while(thptr!=NULL)
  {
   printf("%d",thptr->data);
   thptr=thptr->nptr;
  }
 }


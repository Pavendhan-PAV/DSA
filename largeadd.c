#include<stdio.h>
#include<stdlib.h>

struct large
{
 int data; 
 struct large *nptr;
};

struct large *hptr1=NULL,*hptr2=NULL,*hptr3=NULL;

void insert1(char c,int pos);
void display1();

void insert2(char c,int pos);
void display2();

void rev();
void add();


void main()
{
 int n1,j1=0;
 char a[100];
 printf("First number!");
 printf("\nEnter the no. of digits: ");
 scanf("%d",&n1);

 printf("\nEnter a large integer of length %d :",n1);
 for(int i=0;i<n1;i++)
 scanf(" %c",&a[i]);

 while(j1<n1)
 {
  insert1(a[j1],j1);
  j1++;
 }
 
 
 int n2,j2=0;
 char b[100];
 printf("\n\nSecond number!");
 printf("\nEnter the no. of digits: ");
 scanf("%d",&n2);

 printf("\nEnter a large integer of length %d :",n2);
 for(int i=0;i<n2;i++)
 scanf(" %c",&a[i]);

 while(j2<n2)
 {
  insert2(a[j2],j2);
  j2++;
 }
 rev();
 display1();
 display2();

}



void insert1(char c,int pos)
{
 int i=0;
 struct large *temp=(struct large*)malloc(sizeof(struct large));
 struct large *thptr=hptr1;
 temp->data=((int)c-48);
 if(pos==0)
 {
  temp->nptr=hptr1;
  hptr1=temp;  
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

void display1()
{
 struct large *thptr=hptr1;
 while(thptr!=NULL)
 {
  printf("%d",thptr->data);
  thptr=thptr->nptr;
 }
}
 
void insert2(char c,int pos)
{
 int i=0;
 struct large *temp=(struct large*)malloc(sizeof(struct large));
 struct large *thptr=hptr2;
 temp->data=((int)c-48);
 if(pos==0)
 {
  temp->nptr=hptr2;
  hptr2=temp;  
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

void display2()
{
 struct large *thptr=hptr2;
 while(thptr!=NULL)
 {
  printf("%d",thptr->data);
  thptr=thptr->nptr;
 }
} 

void add()
{
 struct large *thptr1=hptr1,*thptr2=hptr2;
 while(thptr1!=NULL)
 thptr1=thptr1->nptr;
 while(thptr2!=NULL)
 thptr2=thptr2->nptr;
  
}

void rev()
{
 struct large *prev1=NULL,*thptr1=hptr1,*next1=NULL;
 while(thptr1!=NULL)
 {
  next1=thptr1->nptr;
  thptr1->nptr=prev1;
  prev1=thptr1;
  thptr1=next1;
 } 
 
 struct large *prev2=NULL,*thptr2=hptr2,*next2=NULL;
  while(thptr2!=NULL)
 {
  next2=thptr2->nptr;
  thptr2->nptr=prev2;
  prev2=thptr2;
  thptr2=next2;
 } 
}



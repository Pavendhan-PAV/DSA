#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *nptr;
};
struct node *hptr[100]={NULL};

struct node* insert(struct node *hptr,int x);
void delete(int x,int n);
int search(int x,int n);

void main()
{
 int n,x;
 printf("\nEnter the size of the array: ");
 scanf("%d",&n);
  
 printf("Enter the elements: ");
 int choice=1;
 for(int i=0;choice==1;i++)
 {
  scanf("%d",&x);
  int index;
  index=x%n;                                            
  hptr[index]=insert(hptr[index],x);
  printf("\nCONTINUE? give 1 else 0: ");
  scanf("%d",&choice);
 }
 
 printf("\nEnter the element to be searched: ");
 scanf("%d",&x);
 search(x,n);
 
 printf("\nEnter the element to be deleted: ");
 scanf("%d",&x);
 if(search(x,n))
 delete(x,n);
 
 for(int i=0;i<n;i++)
 {
  struct node *tptr=hptr[i];
  while(tptr!=NULL)
  {
  printf("\n\t%d\n",tptr->data); 
  tptr=tptr->nptr;
  }
}
}

struct node* insert(struct node *hptr,int x)
{
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 temp->data=x;
 temp->nptr=NULL;
 if(hptr==NULL)
 hptr=temp;
 else
 {
  temp->nptr=hptr;
  hptr=temp;
 }
 return hptr;
}

int search(int x,int n)
{
 int index=x%n;
 struct node *tptr=hptr[index];
 int flag=0;
 while(tptr!=NULL)
 {
  if(tptr->data==x)
  {
   printf("\nPresent in Hash table!");
   flag=1;
   return 1;
  }
  tptr=tptr->nptr;
 }
 if(flag==0)
 {
  printf("\nNot present in Hash table!");
  return 0;
 }  
}

void delete(int x,int n)
{
 int index=x%n;
 struct node *tptr=hptr[index];
 while(tptr!=NULL)
 {
  if(tptr->data==x)
  {
   printf("\n%d is deleted!",tptr->data);
   hptr[index]=tptr->nptr;
   return;
  }  
  
  if((tptr->nptr)->data==x)
  {
   printf("\n%d is deleted!",(tptr->nptr)->data);
   tptr->nptr=(tptr->nptr)->nptr;     
   return;
  }
  tptr=tptr->nptr;
 }
}

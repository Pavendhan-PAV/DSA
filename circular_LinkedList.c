#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *nptr;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int x);
void dequeue();
void display();

void main()
{
 int c,a,i;
 do
 {
 printf("\n1.Insertion \n2.Delete \n3.Display\n");
 scanf("%d",&c);
 
 switch(c)
 {
  case 1: printf("\nEnter the number for insertion:");
          scanf("%d",&i);
          enqueue(i);
          break;
  case 2: dequeue();
          break;
  case 3: display();
          break;
 default: printf("No such choice!");
          break;                            
 }
 printf("\nWant to continue: 1-yes or 2-no");
 scanf("%d",&a);
 }while(a==1);
}

void enqueue(int x)
{
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 temp->data=x;
 if(front==NULL)
 {
  front=rear=temp;
  temp->nptr=front;
 }
 else
 {
  rear->nptr=temp;
  rear=temp;
  temp->nptr=front;
 }
}

void dequeue()
{
 int x;
 if(front==NULL)
 printf("\nUnderflow!");
 else if(front==rear)
 {
  x=front->data;
  front=rear=NULL;
 }
 else
 {
  x=front->data;
  front=front->nptr;
  rear->nptr=front;
 }
 printf("\n%d",x);
} 
 
   
void display()
{
 struct node *thptr=front;
 do
 {
  printf("\t %d",thptr->data);
  thptr=thptr->nptr; 
 }while(thptr!=front);
}

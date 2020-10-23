#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char d[1000];
struct node
{
 char w[100],m[1000];
 struct node *lcptr,*rcptr;
 int h;
}*rptr=NULL;

struct node *insert(char w[100],char m[1000],struct node *ptr);
void Search(struct node *ptr);
int height(struct node *ptr);
struct node *RL(struct node *ptr);
struct node *LR(struct node *ptr);
struct node *L(struct node *ptr);
struct node *R(struct node *ptr);
void inorder(struct node *ptr)
{
 if(ptr)
 {
  inorder(ptr->lcptr);
  printf("%s",ptr->w);
  inorder(ptr->rcptr);
 }
}

void preorder(struct node *ptr)
{
 if(ptr)
 {
  printf("%s",ptr->w);
  inorder(ptr->lcptr);
  inorder(ptr->rcptr);
 }
}

void postorder(struct node *ptr)
{
 if(ptr)
 {
  inorder(ptr->lcptr);
  inorder(ptr->rcptr);
  printf("%s",ptr->w);
 }
}


void main()
{
 char a[100],b[1000];
 int c,c2;
 do{
  printf("\nWORD: ");
  scanf("%s",a);
  printf("MEANING:");
  scanf(" ");
  gets(b);
  rptr=insert(a,b,rptr);
  printf("\n1 to continue else 0:");
  scanf("%d",&c);
 }while(c==1);
 printf("\nInorder:");
 inorder(rptr);
 printf("\nPreorder:");
 preorder(rptr);
 printf("\npostorder:");
 postorder(rptr);
 do{
  printf("\nWORD to be searched: ");
  scanf("%s",d);
  Search(rptr);
  printf("\n1 to continue else 0:");
  scanf("%d",&c2);
 }while(c2==1);
}

struct node *insert(char w[100],char m[1000],struct node *ptr)
{
 if(ptr==NULL)
 {
  ptr=(struct node *)malloc(sizeof(struct node));
  strcpy(ptr->w,w); 
  strcpy(ptr->m,m);
  ptr->lcptr=ptr->rcptr=NULL;
  ptr->h=0;
 }
 else
 {
  if(strcmp(w,ptr->w)<0)
   ptr->lcptr=insert(w,m,ptr->lcptr);
  else
   ptr->rcptr=insert(w,m,ptr->rcptr);
   
   ptr->h=height(ptr);
   
   if((height(ptr->lcptr)-height(ptr->rcptr))==2||(height(ptr->lcptr)-height(ptr->rcptr))==-2)
   {
    if(strcmp(w,ptr->w)<0)
    {
     if(strcmp(w,ptr->lcptr->w))
     ptr=R(ptr);
     else
     ptr=LR(ptr);
    }
    else
    {
     if(strcmp(w,ptr->rcptr->w)<0)
     ptr=RL(ptr);
     else
     ptr=L(ptr);
    } 
   }
  }
  return ptr;
 }

int height(struct node *ptr)
{
 int lh,rh;
 if(ptr==NULL)
 return -1;
 if(ptr->lcptr==NULL)
 lh=-1;
 else
 lh=ptr->lcptr->h;
 if(ptr->rcptr==NULL)
 rh=-1;
 else
 rh=ptr->rcptr->h;
 
 if(lh>rh)
 return lh+1;
 else 
 return rh+1;  
}

struct node *R(struct node *ptr)
{
 struct node *xptr=ptr, *yptr=ptr->lcptr;
 xptr->lcptr=yptr->rcptr;
 yptr->rcptr=xptr;
 
 xptr->h=height(xptr);
 yptr->h=height(yptr);
 return yptr;
}

struct node *L(struct node *ptr)
{
 struct node *xptr=ptr, *yptr=ptr->rcptr;
 xptr->rcptr=yptr->lcptr;
 yptr->lcptr=xptr;
 
 xptr->h=height(xptr);
 yptr->h=height(yptr);
 return yptr;
}

struct node*RL(struct node *ptr)
{
 ptr->rcptr=R(ptr->rcptr);
 ptr=L(ptr);
 return ptr;
}

struct node*LR(struct node *ptr)
{
 ptr->lcptr=L(ptr->lcptr);
 ptr=R(ptr);
 return ptr;
}

void Search(struct node *ptr)
{
 int flag=0;
 if(ptr)
 {
  if(strcmp(ptr->w,d)==0)
  {
   flag=1;
   printf("\nThe meaning is %s",ptr->m);
   return;
  } 
  if(strcmp(ptr->w,d)<0)  
  Search(ptr->lcptr);
  else
  Search(ptr->rcptr);
 }
 if(flag==0)
 printf("\nNot Found!!");
}

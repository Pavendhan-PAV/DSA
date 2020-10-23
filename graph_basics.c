#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int IP[100];
int AM[100][100];
int visit[100];
int n;

void dfs(int n);
void addedge(int a, int b);
void addnode(int a,int *n);
void connectivity(int n);

void main()
{
 int a,b,c;
 
 printf("\nEnter number of the ids: ");
 scanf("%d",&n);
 
 printf("\nEnter the ids: ");
 for(int i=0;i<n;i++)
 scanf("%d",&IP[i]);

 
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
 {
  printf("Is there a link between %d and %d (yes 1 else 0): ",IP[i],IP[j]);
  scanf("%d",&AM[i][j]);
  //AM[j][i]=AM[i][j];
 }
 for(int i=0;i<n;i++)
 visit[i]=0;
 
 printf("\nEnter where you wish to link: ");
 scanf("%d %d",&a,&b);
 addedge(a,b); 
 printf("\nEnter the node you wish to add: ");
 scanf("%d",&c);
 addnode(c,&n);
 
 dfs(0); 

 connectivity(n);
 
}

void dfs(int i)
{
 visit[i]=1;
 printf("\n%d",IP[i]);
 for(int j=1;j<n;j++)
 if(visit[j]==0 && AM[i][j]==1)
 dfs(j);
}

void addedge(int a,int b)
{
 int l,m;
 for(int i=0;i<n;i++)
 {
  if(a==IP[i])
  l=i;
  if(b==IP[i])
  m=i;
 }
AM[l][m]=AM[m][l]=1;
}

void addnode(int c,int *n)
{
 *n=*n+1;
 IP[*n-1]=c;
 for(int i=0;i<*n;i++)
 {
  printf("\nIs there a link between %d and %d:",IP[*n-1],IP[i]);
  scanf("%d",&AM[*n-1][i]);
  AM[i][*n-1]=AM[*n-1][i];
 }
}

void connectivity(int n)
{
 int flag=0;
 for(int i=0;i<n;i++)
 {
  if(visit[i]==0)
  {
   printf("\nNot connected!");
   flag=1;
   break;
  }
 } 
  if(flag==0)
  printf("\nConnected!");
 }


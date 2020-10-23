#include<stdio.h>
#include<stdlib.h>

struct min
{
 int p[100];
 int t[100];
 int last;
};

struct min h;


void insert(int x,int i);
void del();

void main()
{
 h.last=0;
 int i=1,a,c,n;
 printf("\nEnter number of ETs:");
 scanf("%d",&n);
 for(c=1;c<=n;c++)
 {
   printf("\nEnter Execution time for process %d :",c);
   scanf("%d",&a);
   insert(a,c);
 } 

 for(int j=1;j<=h.last;	j++)
  del();
// printf("\nProcess %d : %d units",h.p[j],h.t[j]);
}

void insert(int x,int i)
{
 int j=++h.last;
 
 h.p[j]=i;
 h.t[j]=x;
 printf("\n%d",j);
 int m=j;
 while((m/2>=1) && h.t[m/2]>=h.t[m])
 {
  h.t[m]=h.t[m]^h.t[m/2];
  h.t[m/2]=h.t[m]^h.t[m/2];
  h.t[m]=h.t[m]^h.t[m/2];
  
  h.p[m]=h.p[m]^h.p[m/2];
  h.p[m/2]=h.p[m]^h.p[m/2];
  h.p[m]=h.p[m]^h.p[m/2];
  
  m=m/2;   
 }
}

void del()
{
 int k=h.t[1];
 int l=h.p[1];
 printf("\n PID: %d and ET: %d",l,k);
 h.t[1]=h.t[h.last];
 h.p[1]=h.p[h.last];
 h.last--;
 int m=1;
 int mi;
 while(2*m <=h.last)
 {
  if(2*m+1<=h.last)
  {
   if(h.t[2*m] > h.t[2*m+1])
   mi=2*m;
   else
   mi=2*m+1;
  }
  else
  mi=2*m;
  
  if(h.t[m]>h.t[mi])
  {
   h.t[m]=h.t[m]^h.t[mi];
   h.t[mi]=h.t[m]^h.t[mi];
   h.t[m]=h.t[m]^h.t[mi];
  
   h.p[m]=h.p[m]^h.p[mi];
   h.p[mi]=h.p[m]^h.p[mi];
   h.p[m]=h.p[m]^h.p[mi];
   
   m=mi;  
  } 
  else break;
 }
}
 


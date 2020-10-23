#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char c[100];
int stack1,stack2;
int eval(char c[],int n);
void main()
{
 int n;
 printf("\nEnter postfix exp:");
 scanf("%s",c);
 n=strlen(c);
 
 printf("\n%d",eval(c,n));
}

int eval(char c[],int n)
{
 if(c[0]>=48&&c[0]<=57)
 stack1=c[0]-48;
 else { printf("Invalid"); return 0;}
 
 if(c[1]>=48&&c[1]<=57)
 stack2=c[1]-48;
 else { printf("Invalid"); return 0;}
 
 for(int i=2;i<n;i++)
 {
  if(c[i]>=48&&c[i]<=57)
  stack2=c[i]-48;
  else if(c[i]=='+')
  stack1+=stack2;
  else if(c[i]=='-')
  stack1-=stack2;
  else if(c[i]=='*')
  stack1*=stack2;
  else if(c[i]=='/')
  stack1/=stack2;
  }return stack1;  
 }
 


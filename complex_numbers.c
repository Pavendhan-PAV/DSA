#include<stdio.h>
struct complex
{
 float a;
 float b;
}c1,c2;

void main()
{
 
 printf("\nEnter 2 complex numbers:");
 scanf("%f%f%f%f",&c1.a,&c1.b,&c2.a,&c2.b);
 printf("\nGiven complex numbers:%f+%fi %f+%fi",c1.a,c1.b,c2.a,c2.b);
 
 printf("\nAdditon:%f+%fi",c1.a+c2.a,c1.b+c2.b);
 printf("\nSubtraction:%f+%fi",c1.a-c2.a,c1.b-c2.b);
 printf("\nMultiplication:%f+i%f",(c1.a*c2.a)-(c1.b*c2.b),(c1.a*c2.b)+(c1.b*c2.a));
 printf("\nDivision:%f+i%f",((c1.a*c2.a)+(c1.b*c2.b))/((c2.a*c2.a)+(c2.b*c2.b)),((c1.b*c2.a)-(c1.a*c2.b))/((c2.a*c2.a)+(c2.b*c2.b)));
} 
 

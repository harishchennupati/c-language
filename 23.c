#include<stdio.h>
int top=-1;
void push(int *z,int x)
{
    z[++top]=x;
}
int pop(int *z)
{
top-=1;
return z[top+1];
}
int main(void)
{
int n;
printf("enter the number of elements to be pushed onto the stack\n");
scanf("%d",&n);
int k;
int a[n];
for(int i=1;i<=n;++i)
{   printf("enter the element %d:",i);
    scanf("%d",&k);
    push(a,k);
}
if(n&1)
printf("the middle element is %d\n",a[n/2]);
else
printf("the middle element is &d\n",a[n/2-1]);
printf("the popped element is %d",pop(a));
}
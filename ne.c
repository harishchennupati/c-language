#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int *p=(int*)malloc(4);
    *p=0X8F7E1A2B;
    printf("%lu\n",(unsigned long)p);
    unsigned char *q=(unsigned char*)p;
    printf("%lu\n",(unsigned long)q);
    printf("%d ",*q);
    printf("%X",*q++);
    printf(" %lu\n",(unsigned long)q);
    printf("%d ",*q);
    printf("%X",*q++);
    printf(" %lu\n",(unsigned long)q);
     printf("%d ",*q);
    printf("%X",*q++);
    printf(" %lu\n",(unsigned long)q);
    printf("%d ",*q);
    printf("%X",*q++);
   
}
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    for(int i=1;i<=2;++i)
    {   system("clear");
        fprintf(stdout,"%d",i);
        timeout(10000);
        fseek(stdout,0,0);
    }
}
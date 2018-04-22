#include<stdio.h>
#include<string.h>
void fill(char *s)
{
    for(int i=0;i<100;++i)
    s[i]='\0';
}
int split(char *p)
{   if(p[0]=='x' && p[1]=='x' && p[2]=='x')
     return 0;
    char *c;
    c=p;
    int i=0;
    int cnt=0;
    while(c[i]!='\0')
    {
        if(c[i]==' ')
        {
            while(c[i]!=' ')
            { 
              ++i;
            }
      ++cnt;
        }
        ++i;
    }
    return cnt+1;
}
int main(void)
{
    FILE *f=fopen("essaypro.txt","w");
    char s[1000];
    int len=0;
    do{ fill(s);
        printf("Enter sentence\n");
        fscanf(stdin,"%[^\n]s",s);
        fflush(stdin);
        getchar();
        fprintf(f,"%s\n",s);
        len+=split(s);
    }while(strcmp(s,"xxx")!=0);
    printf("Total number of words :%d\n",len);
       if(len==0)
       printf("file is empty\n");
       if(len>=50)
        printf("your essay is rejected\n");
       if(len<50 && len!=0)
       printf("thank you for participating\n");
}
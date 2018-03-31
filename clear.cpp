#include<iostream>
using namespace std;
void seth(int x)
{
    for(int i=1;i<=x;++i)
    cout<<"_";

}
void space(int i)
{
for(int k=1;k<=i;++k)
cout<<" ";
}
void setv(int x)
{  for(int i=1;i<=6;++i)
{  space(x);
   cout<<"|"<<endl;
}
}

int main(void)
{   int l=5;
    space(0);
    seth(5);
    cout<<endl;
    for(int k=1;k<=5;++k)
    {
        setv(l);
        space(l);
        seth(5);
        l=l+5;
    }
}
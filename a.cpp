#include<iostream>
using namespace std;
void f(int c=1,int b=1,int d=1);
void f(int a,int i,int q){
    cout<<a<<i<<q;
}
int main(void)
{
    f();
}
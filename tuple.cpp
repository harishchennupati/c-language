#include<iostream>
#include<tuple>
using namespace std;
int main(void)
{
    tuple <int,int> s;
    s=make_tuple(0,2);
    cout<<get<0>(s);
}
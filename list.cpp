#include<iostream>
#include<list>
using namespace std;
int main(void)
{
  //  list<int> s(4);
    // s.push_front(1);
    list<int>* p;
    p=new list<int>[4];
    p[0].push_back(1);
    p[0].push_back(2);
    p[0].push_back(3);
    p[1].push_back(2);
    p[2].push_front(4);
    for(int x:p[0])
    {
        cout<<x;
    }
}
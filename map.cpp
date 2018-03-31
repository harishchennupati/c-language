#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(void)
{
map<int,string> s;
map<int,map<int,string>> s1;
s[3]="harish";
s[1]="sriram";
s1[0][1]="hari";
map<int,map<int,string>>:: iterator it;
cout<<s1[0][1];
}
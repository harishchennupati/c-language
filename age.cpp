#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
 using namespace std;
class age
{ public:
 string s1;
 int age1;
 public:
 age(){}
 age(string s1,int d):s1(s1),age1(d){}
 bool operator>(age p){
     return age1>p.age1;
 }
 bool operator ()(age p1,age p)
 {
     return p1.age1>p.age1;
 }
 bool operator()(age p)
 {
     return age1>p.age1;
 }
};
int main(void)
{
    int c=0;
    int a;
    vector<age,greater<int>> s;
    s.push_back(age("swsw",12));
    s.push_back(age("asdasd",23));
    s.push_back(age("asdasdwqe",1231));
    sort(s.begin(),s.end());
    for(int i=0;i<3;++i)
    cout<<s[i].s1<<" "<<s[i].age1<<endl;
}
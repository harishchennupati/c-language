#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void)
{  int input[20]={1,2,2,3,4,4,5,7,8,9,14,50,100};
    vector<int> s(input,input+12);
    vector<int>::iterator i,p;
    i=lower_bound(s.begin(),s.end(),14);
    p=upper_bound(s.begin(),s.end(),52);
    cout<<*i<<" "<<*(p-1);
}
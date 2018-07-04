#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    string str;
    vector<string> ko;
    int cnt=0;
    string s1;
    getline(cin,str,'\n');
    int k;
    cin>>k;
    int l=0;
    stringstream s(str);
    while(s>>s1)
    {
        ko.push_back(s1);
    }
    while(l!=ko.size())
    { cnt+=ko[l].length()+1;
    if(cnt<=k+1)
    {
cout<<ko[l]<<" ";
    }
    else{
        cout<<endl;
        cout<<ko[l]<<" ";
        cnt=ko[l].length()+1;
    }
l+=1;
    }
}
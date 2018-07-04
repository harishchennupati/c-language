#define un unsigned long long int
#include<bits/stdc++.h>
#define inf 10000000000
using namespace std;
int main(void)
{
  un n;
  cin>>n;
  for(un i=1;i<=n;++i)
  {
      un si;
      cin>>si;
      un no;
      vector<un> a1;
      vector<un> a2;
      for(un j=0;j<si;++j)
      {  cin>>no;
         if(j&1)
        a1.push_back(no);
        else
        a2.push_back(no);
      }
      sort(a1.begin(),a1.end());
      sort(a2.begin(),a2.end());
          if(!no&1)
          a2.push_back(inf);
          for(un k=0;k<a1.size();++k)
          {
           if(a2[k]<=a1[k] && a1[k]<=a2[k+1])
           continue;
           else{
           cout<<"Case #"<<i<<":"<<k+1<<endl;
           goto x;
          }
          }
          cout<<"Case #"<<i<<":"<<"OK"<<endl;
          x:
           ;
  }
}
#include<bits/stdc++.h>
using namespace std;
class graph{
    private:
    list<int> *s;
    bool* visited;
    public:
    graph(int size)
    {
        s=new list<int>[size+1];
        visited=new bool[size+1];
    }
    void add_edge(int a,int b)
    {
     s[a].push_back(b);
     s[b].push_back(a);
    }
    unsigned long long int bfs()
    {   queue<int> s2;
        
        s2.push(1);
        visited[1]=true;
        unsigned long long int max=1;
        while(!s2.empty())
        { int z=s2.front();
          s2.pop();
          for(int i=0;i<s[z].size();++i)
          { 
          if(visited[s[z][i]]==false){
          visited[s[z][i]]=true;
          max*=2;
          s2.push(s[z][i]);
          }
          }
        }
        return max;    
}
};
int main(void)
{
    
    int n,m;
    cin>>n>>m;
    int start,end;
    graph t(n);
    for(int i=1;i<=m;++i)
    { cin>>start>>end;
      t.add_edge(start,end);
    }
    cout<<t.bfs();
}
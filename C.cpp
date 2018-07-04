#include<bits/stdc++.h>
using namespace std;
int cn=0;
class graph
{   private:
    int v;
    list<int>* s;
    bool* visited;
    public:
    graph(int n)
    {
        s=new list<int>[n+1];
        v=n;
        visited=new bool[n+1];
        memset(visited,0,sizeof(visited));
    }
    void dfs_real(bool *cat,int u,bool* visited,int cnt,int m)
    { 
    visited[u]=true;
    if(cat[u]==1)
    {
        cnt++;
    }
    else{
        cnt=0;
    }
    if(cnt>m)
    return;
    if(s[u].size()==1 && u!=1)
    {
    cn++;
    return;
    }
    
    int i;
    for_each(s[u].begin(),s[u].end(),i)
    {
        dfs_real(cat,i,visited,cnt,m);
    }
    }
  
    void dfs(bool* cat,int start,int m)
    { int cnt=0;
    dfs_real(cat,start,visited,cnt,m);

    }
    void add_edge(int u,int v)
    {
    s[u].push_back(v);
    s[v].push_back(u);
    }
};
int main(void)
{ 
    int n,m;
    cin>>n>>m;
    graph g(n);
    bool cat[n+1];
    int ch;
    for(int i=1;i<=n;++i)
    {
        cin>>ch;
        if(ch==1)
        cat[i]=1;
        else cat[i]=0;
    }
    int u,v;
    for(int i=1;i<=n-1;++i)
    {
     cin>>u>>v;
     g.add_edge(u,v);
    }
    g.dfs(cat,1,m);
    cout<<cn;
}
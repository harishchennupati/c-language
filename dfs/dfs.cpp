#include<iostream>
#include<list>
using namespace std;
class graph{
    private:
    int v;
    list<int>* p;
    public:
    void addedge(int i,int v);
    graph(int v1);
    void dfs(int start);
    void solve(int i,bool *v);
};
graph::graph(int v1)
{   v=v1;
    p=new list<int>(v1);
}
void graph::addedge(int i,int v)
{
p[i].push_back(v);
}
void graph:: solve(int i,bool* v)
{
    cout<<i<<" ";
    v[i]=true;
   for(list<int> :: iterator it=p[i].begin();it!=p[i].end();++it)
    {
       if(v[*it]==false)
         solve(*it,v);
    }
}
void graph::dfs(int start)
{   bool *v1=new bool[v];
  for(int i=0;i<v;++i)
  v1[i]=false;
    solve(start,v1);
}
int main(void)
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    g.dfs(2);
    return 0;
}
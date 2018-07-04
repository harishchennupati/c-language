#include<bits/stdc++.h>
using namespace std;
class graph{
    bool *arr;
    list<int> *p;
    queue<int> l;
    public:
    graph(int v){
   p=new list<int>[v];
   arr=new bool[v];
   fill(arr,arr+v,false);
    }
    void addedge(int v1,int v2){
        p[v1].push_back(v2);
    }
   void bfs(int v);
};
void graph::bfs(int v)
{ l.push(v);
int x;
 int index;
 arr[v]=true;
    while(!l.empty())
    {
        index=l.front();
        l.pop();
        cout<<index<<"->";
        for(list<int>::iterator it=p[index].begin();it!=p[index].end();++it)
        {  
            if(arr[*it]==false){
            l.push(arr[*it]);
            arr[*it]=true;
        }
    }
}
}
int main(void)
{
graph s(10);
s.addedge(1,2);
s.addedge(1,3);
s.addedge(1,4);
s.addedge(4,5);
s.addedge(4,8);
s.addedge(5,6);
s.addedge(5,7);
s.addedge(6,8);
s.addedge(6,9);
s.addedge(6,7);
s.addedge(9,10);
s.bfs(2);
}
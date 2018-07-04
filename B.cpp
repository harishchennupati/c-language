#include<bits/stdc++.h>
using namespace std;
 int n,m,k;
bool dfs(vector<vector<char> >& matrix,vector<vector<char> >& matrix1,int no,int x,int y)
{  
    if(matrix1[x][y]=='1')
    return false;
    else matrix1[x][y]='1';
    
    if(matrix[x][y]=='#')
     return false;
    if(no==0)
    return true;
    if(x<0 || x>=n || y<0 || y>=m)
    return false;
    
     if( dfs(matrix,matrix1,no-1,x,y+1)){
     matrix1[x][y]='.';
     return true;
    }
    else if(dfs(matrix,matrix1,no-1,x,y-1))
    {   matrix1[x][y]='.';
     return true;
    }
    else if( dfs(matrix,matrix1,no-1,x-1,y))
    {   matrix1[x][y]='.';
     return true;
    }
    else if(dfs(matrix,matrix1,no-1,x+1,y))
    {   matrix1[x][y]='.';
     return true;
    }
    else
    return false;
}
int main(void)
{
   
    cin>>n>>m>>k;
    vector<vector<char> > matrix(n+1,vector<char>(m+1));
    vector<vector<char> >matrix1(n+1,vector<char>(m+1,'0'));
    char ch;
    int cnt=0;
    for(int i=0;i<n;++i)
    {  
        for(int j=0;j<m;++j)
        { 
        cin>>ch;
        if(ch=='#'){
        matrix[n][m]=ch;
        matrix1[n][m]=ch;

               }       
        
        else
        {
            matrix[n][m]=ch;
            ++cnt;
        }
    }
}

for(int i=0;i<n;++i)
{
    for(int j=0;j<m;++j)
    {
     if(matrix[i][j]=='.'){
     dfs(matrix,matrix1,cnt-k-1,i,j);
     goto x;
    }
}
}
x:
for(int i=0;i<n;++i)
{
    for(int j=0;j<m;++j)
    {

        /*if(matrix1[i][j]=='#')
        cout<<"#"<<" ";
        if(matrix1[i][j]=='.')
        cout<<"."<<" ";
        else
        cout<<"X"<<" ";*/
        cout<<matrix1[i][j];
    }
    cout<<endl;
}
}

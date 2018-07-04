#include<iostream>
using namespace std;
char matrix[60][60];
int N,M;
char start_x,start_y;
char color;
bool solve(int x,int y,int n)
{
bool check;
if(x<0 || y<0 || x>=N || y>=M)
return false;
if(n>=4 && x==start_x && y==start_y)
return true;

if(matrix[x][y]==' ' || color!=matrix[x][y])
return false;

chat temp=matrix[x][y];
matrix[x][y]=' ';
check=solve(x+1,y,n+1) || solve(x-1,y,n+1) || solve(x,y+1,n+1) || solve(x,y-1,n+1);
matrix[x][y]=temp;





return check;

}
int main(void)
{

cin>>n>>m;
N=n;
M=m;
char matrix[n][m];
for(int i=0;i<n;++i)
{
    for(int j=0;j<m;++j)
    {
        cin>>matrix[i][j];
    }
}
for(int i=0;i<n;++i)
{
    for(int j=0;j<m;++j)
    {
        if(matrix[i][j]==' ')
        continue;
        start_x=i;
        start_y=j;
        else
        {
            sove(i,j,1);
        }
        
    }
}
solve();

}
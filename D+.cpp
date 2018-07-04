#include<bits/stdc++.h>
using namespace std;
char grid[53][53];
int sr, sc ,N,M;
char color;

bool cfind(int r, int c, int n){
    
    if(r <0 || c< 0 || r>= N || c >= M) return false;
//    DD(r << " " << c)
    if(r == sr && c == sc && n >= 4) return true;
    if(grid[r][c] == ' ' || color != grid[r][c]) return false;
    
    char temp= grid[r][c];
    grid[r][c]= ' ';
    bool stat= cfind(r+1, c, n+1) ||  cfind(r, c+1, n+1)  ||cfind(r-1, c, n+1) || cfind(r, c-1, n+1);
    grid[r][c]= temp;
    return stat;
}
void solve(void){
    int Tc;
    int n, m;
    cin>>n>>m;
    N= n;
    M= m;
    
    for(int i= 0; i<n; i++){
        for(int j= 0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    
    
    bool ff= false;
    for(int i= 0; i<n; i++){
        for(int j= 0; j<m; j++){
            if(grid[i][j] == ' ') continue;
            sr= i;
            sc= j;
            color= grid[i][j];
            
            ff= cfind(i, j, 1);
            grid[i][j]= ' ';
                    
            if(ff) break;
        }
        if(ff) break;
        
    }
    
    cout<< ((ff)? "Yes": "No") <<endl;
    
}


/*FILL ME WITH INPUTS!!!
3 4
AAAA
ABCA
AAAA
2 2
AA
AA
10 20
AAAAAAAAAAAAAAAAAAAA
BBBBBBBBBBBBBBBBBBBA
AAAAAAAAAAAAAAAAAAAA
ABBBBBBBBBBBBBBBBBBB
AAAAAAAAAAAAAAAAAAAA
ABBBBBBBBBBBBBBBBBBA
AAAAAAAAAAAAAAAAAAAA
BBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBA
BBBBBBBBBBBBBBBBBBBA
 
 */


int main(void){
    solve();
    return 0;
}
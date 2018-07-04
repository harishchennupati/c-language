

    #include<bits/stdc++.h>
     int   visited[510][510];
     using namespace std;
    int n,m,k;
    int c=0;
    int s=0;
    char arr[510][510];
  void  dfs(int a,int b)
   {
    
                int re=s-k-1;  
            //     cout<<re<<endl;
        stack<pair<int,int> >s;
        s.push(make_pair(a,b));
        visited[a][b]=1;
         while(!s.empty())
           {
              int x=s.top().first;
              int y=s.top().second;
                  
                  s.pop();
                  int f=0;
                //   cout<<x<<" "<<y<<endl;
                  if(x+1<n && visited[x+1][y]==0 && arr[x+1][y]=='.' )
                   {
                      if(re<=0) arr[x+1][y]='X';
                      
                      visited[x+1][y]=1;
                        s.push(make_pair(x+1,y));
                        f=1;
                        re--;
                      
                   }
                  if(x-1>=0 && visited[x-1][y]==0 && arr[x-1][y]=='.' )
                   {
                     if(re<=0) arr[x-1][y]='X';
                      visited[x-1][y]=1;
                        s.push(make_pair(x-1,y));
                        f=1;
                        re--;
                      
                   }
                    if (y+1<m && visited[x][y+1]==0 && arr[x][y+1]=='.' )
                   {
                        if(re<=0) arr[x][y+1]='X';
                      visited[x][y+1]=1;
                        s.push(make_pair(x,y+1));
                        f=1;
                        re--;
                      
                   }
                    if(y-1>=0 && visited[x][y-1]==0 && arr[x][y-1]=='.' )
                   {
                     if(re<=0) arr[x][y-1]='X';
                      visited[x][y-1]=1;
                        s.push(make_pair(x,y-1));
                        f=1;
                      re--;
                   }
                //cout<<re<<endl;    
            
           }
   }
int main()
 {
   //  freopen("abc.txt","r",stdin);
 
    cin>>n>>m>>k;
     
      for(int i=0;i<n;i++)
       cin>>arr[i];
        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++) if(arr[i][j]=='.') s++;
       int f=0;
      for(int i=0;i<n;i++)
       {
          for(int j=0;j<m;j++)
           {
              if(arr[i][j]=='.')
              {
               dfs(i,j);
                  f=1;
                 break;
              }
                
            
           }
            if(f==1)
             break;
       }
        for(int i=0;i<n;i++)
         {
            cout<<arr[i];
             cout<<endl;
         }
       return 0;
 }
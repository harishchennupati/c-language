#include <iostream>
 using namespace std;
int max(int a, int b) { return (a > b)? a : b; }



 
int main()
{
    int p[] = {0,100,1000,20000};
    int wt[] = {0,4,12,123};
    int  m = 8;
    int n = 4;
   int K[5][9];
   for (int i = 0; i <= n; i++)
   {
       for (int w = 0; w <= m; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i] <= w)
                 K[i][w] = max(p[i] + K[i-1][w-wt[i]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
	 
   cout<<"Optimal Profit is "<<K[n][m];
	
   int i=n;int j=m;
   
   while(i>0 && j>=0)
   {
 	if(K[i][j]==K[i-1][j])
	{
		cout<<i<<"=0"<<endl;
		i--;
	}
	else
	{
		cout<<i<<"=1"<<endl;
		j=j-wt[i];
		i--;
	}
   }

}
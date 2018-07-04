
#include <stdio.h>
#include <limits.h>
#include<stdbool.h>
int n;
int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;
  
   for (int j = 0; j < n; j++)
     if (sptSet[j] == false && dist[j] <= min)
         min = dist[j], min_index =j;
  
   return min_index;
}
int printSolution(int dist[], int n)
{
   printf("nertex   Distance from Source\n");
   for (int i = 0; i < n; i++)
      printf("%d\t\t%d\n", i, dist[i]);
}

void dijkstra(int graph[n][n], int src)
{
     int dist[n];     
     bool sptSet[n]; 
     for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
     dist[src] = 0;
     for (int count = 0; count < n-1; count++)
     {
       int u = minDistance(dist, sptSet);
       sptSet[u] = true;
       for (int i = 0; i < n; i++)
         if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][i] < dist[i])
            dist[i] = dist[u] + graph[u][i];
     }
     printSolution(dist, n);
}
int main()
{
   
   printf("enter the number of vertices\n");
   scanf("%d",&n);
   int graph[n][n];
   for(int i=0;i<n;++i)
   {
       for(int j=0;j<n;++j)
       {
           scanf("%d",&graph[i][j]);
       }
   }
   printf("enter the source vertex\n");
   int start;
   scanf("%d",&start);
   dijkstra(graph,start);
    return 0;
}

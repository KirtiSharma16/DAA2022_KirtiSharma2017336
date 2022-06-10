#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define n 5

int main()
{

    int graph[n][n]={{0,10,5,5,inf},
                     {inf,0,5,5,5},
                     {inf,inf,0,inf,10},
                     {inf,inf,inf,0,20},
                     {inf,inf,inf,5,0}};
    int dist[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dist[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]>(dist[i][k]+dist[k][j]) && dist[i][k]!=inf && dist[k][j]!=inf)
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==inf)
            cout<<"INF   ";
            else
            cout<<dist[i][j]<<"     ";
        }
        cout<<endl;
    }
    return 0;
}

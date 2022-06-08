#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            arr[i][j]=num;
        }
    }
    vector<vector<int>> g;
    int edges=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                edges++;
                int u=i+1;
                int v=j+1;
                int w=arr[i][j];
                g.push_back({u,v,w});
            }
        }
    }
   int dist[n+1];
   for(int i=0;i<=n;i++)
   dist[i]=INT_MAX;
    int src;
    cin>>src;
    dist[src]=0;
    
    for(int i=0;i<n-1;i++)
    {
        for(auto k : g)
        {
            int u=k[0];
            int v=k[1];
            int w=k[2];
            if(dist[u]!=INT_MAX && (dist[v]>w+dist[u]))
            dist[v]=w+dist[u];
        }
    }
    for(int i=1;i<n+1;i++)
    {
        cout<<i<<" : "<<dist[i]<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool isbipartite(vector<vector<int>> &graph,int src,int n)
{
    vector<int> color(n,-1);
    queue<int> q;
    color[src]=1;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(graph[u][u]==1)
        return false;
        for(int i=0;i<(int)graph[u].size();i++)
        {
            if(graph[u][i] && color[i]==-1)
            {
                color[i]=1-color[u];
                q.push(i);
            }
            else if(graph[u][i] && color[u]==color[i])
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int arr[n][n]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            arr[i][j]=num;
        }
    }
    vector<vector<int>> graph;
    graph.resize(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
                graph[i].push_back(j+1);
        }
    }
    bool result=false;
    if(isbipartite(graph,0,n))
    result=true;
    if(result)
    cout<<"Bipartite";
    else
    cout<<"Not bipartite";
    return 0;
}
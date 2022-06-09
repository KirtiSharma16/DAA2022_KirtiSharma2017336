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
    vector<vector<pair<int,int>>> graph;
    graph.resize(n+1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            graph[i+1].push_back({j+1,arr[i][j]});
        }
    }
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++)
    {
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }
    key[1]=0;
    parent[1]=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //min heap priority queue
    pq.push({0,1});
    for(int i=1;i<n;i++)
    {
        int u;   
        while(!pq.empty())
        {
            u=pq.top().second;
            pq.pop();
            if(mst[u]==false)
            break;
        }

        mst[u]=true;
        for(auto k : graph[u])
        {
            int v=k.first;
            int w=k.second;
            if(mst[v]==false && w<key[v])
            {
                key[v]=w;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
    }
    
    int sum=0;
    for(int i=1;i<=n;i++)
    sum=sum+key[i];
    cout<<"Minimum spanning weight : "<<sum;
    return 0;
}

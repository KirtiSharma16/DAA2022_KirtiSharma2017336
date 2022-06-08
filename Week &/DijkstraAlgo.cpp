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
    vector<vector<pair<int,int>>> g;
    g.resize(n+1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                int wt=arr[i][j];
                g[i+1].push_back({j+1,wt}); //vertex,wt
            }
        }
    }
    vector<int> dist(n+1,INT_MAX);
    int src;
    cin>>src;
    dist[src]=0;
    set<pair<int,int>> s; //vertex,wt
    s.insert({src,0});
    while(!s.empty())
    {
        auto x= *(s.begin());
        s.erase(x);
        for(auto i : g[x.first])
        {
            if(dist[i.first]>dist[x.first]+i.second)
            {
                s.erase({i.first,dist[i.first]});
                dist[i.first]=dist[x.first]+i.second;
                s.insert({i.first,dist[i.first]});
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<i<<" : "<<dist[i]<<endl;
    return 0;
}

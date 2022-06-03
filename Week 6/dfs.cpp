#include<bits/stdc++.h>
using namespace std;

bool isPathDfs(vector<vector<int>>&graph,int nodes,int source,int end)
{
    bool visited[nodes]={false};
    stack<int> st;
    st.push(source);
    visited[source-1]=true;

    while(!st.empty())
    {
        source=st.top();
        st.pop();
        for(int i=0;i<(int)graph[source-1].size();i++)
        {
            if(graph[source-1][i]==end)
            return true;
            if(visited[graph[source-1][i]-1]==false)
            {
                st.push(graph[source-1][i]);
                visited[graph[source-1][i]-1]=true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int arr[n][n];
    vector<vector<int>>graph;
    graph.resize(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            arr[i][j]=num;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            graph[i].push_back(j+1);
        }
    }
    int source,end;
    cin>>source>>end;
    int result=isPathDfs(graph,n,source,end);
    if(result)
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}

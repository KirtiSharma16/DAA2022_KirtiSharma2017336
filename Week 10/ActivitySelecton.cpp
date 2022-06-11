#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b)
{
    return a[1]<b[1];
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i].second;
    }
    vector<vector<int>> act;
    for(int i=0;i<n;i++)
    act.push_back({a[i].first,a[i].second,i+1});
    sort(act.begin(),act.end(),cmp);
    int result=1;
    int end=act[0][1];
    vector<int> selected;
    selected.push_back(1);
    for(int i=1;i<n;i++)
    {
        if(act[i][0] >= end)
        {
            result++;
            selected.push_back(act[i][2]);
            end=act[i][1];
        }
    }
    cout<<"No. of non-conflicting activities : "<<result<<endl;
    cout<<"List of selected activities : ";
    for(auto i : selected)
    cout<<i<<" ";
    return 0;
}

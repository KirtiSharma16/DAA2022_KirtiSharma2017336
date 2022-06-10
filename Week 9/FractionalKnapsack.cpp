#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    double x =(double)a.second/a.first;
    double y =(double)b.second/b.first;

    return x>y;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> item;
    item.resize(n);
    for(int i=0;i<n;i++)
    {
        int w;
        cin>>w;
        item[i].first=w;
    }
    for(int i=0;i<n;i++)
    {
        int v;
        cin>>v;
        item[i].second=v;
    }
    int W;
    cin>>W;
    sort(item.begin(),item.end(),cmp);
    double ans=0;
    for(int i=0;i<n;i++)
    {
        if(W>item[i].first)
        {
            ans+=(double)item[i].second;
            W-=item[i].first;
            continue;
        }
        double vw=(double)item[i].second/item[i].first;
        ans+=(vw*W);
        W=0;
        break;
    }
    cout<<"Maximum value : "<<ans<<endl;
    return 0;
}
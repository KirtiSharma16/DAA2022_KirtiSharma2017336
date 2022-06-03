#include<bits/stdc++.h>
using namespace std;

int paircount(int a[],int n,int x)
{
    unordered_map<int,int> m;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int b=x+a[i];
        if(m[b])
        {
            ans+=m[b];
        }
        m[a[i]]++;
    }
    m.clear();
    for(int i=0;i<n;i++)
    {
        int b=(-x+a[i]);
        if(m[b])
        ans+=m[b];
        m[a[i]]++;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int k;
        cin>>k;
        int res=paircount(a,n,k);
        cout<<res<<endl;
    }
    return 0;
}

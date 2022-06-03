#include<bits/stdc++.h>
using namespace std;

int kth_smallest(int a[],int n,int k)
{
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    pq.push(-a[i]);
    for(int i=0;i<k-1;i++)
    pq.pop();
    int small=-(pq.top());
    return small;
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
        cout<<kth_smallest(a,n,k)<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

long ways(int index,int t,int a[],vector<vector<long>> &dp)
{
    if(index==0)               //memoization
    return (t%a[0]==0);
    if(dp[index][t]!=-1)
    return dp[index][t];
    long notake=ways(index-1,t,a,dp);
    long take=0;
    if(a[index]<=t)
    take=ways(index,t-a[index],a,dp);
    return dp[index][t]=take+notake;
}

long coinways(int a[],int n,int target)
{
    vector<vector<long>> dp(n,vector<long>(target+1,-1));
    return ways(n-1,target,a,dp);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int target;
    cin>>target;

    long result=coinways(arr,n,target);
    cout<<result<<" ways"<<endl;
    return 0;
}
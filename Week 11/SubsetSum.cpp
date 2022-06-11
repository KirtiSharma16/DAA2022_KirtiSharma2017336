#include<bits/stdc++.h>
using namespace std;

bool subset(int n,int k,vector<int> &a)
{
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++)        //tabulation
    dp[i][0]=true;
    dp[0][a[0]]=true;
    for(int index=1;index<n;index++)
    {
        for(int target=1;target<=k;target++)
        {
            bool notake=dp[index-1][target];
            bool take=false;
            if(a[index]<=target)
            take=dp[index-1][target-a[index]];
            dp[index][target]=take | notake;
        }
    }
    return dp[n-1][k];
}

bool SubsetSum(vector<int> &a,int n)
{
    int totsum=0;
    for(int i=0;i<n;i++)
    totsum+=a[i];
    if(totsum%2)
    return false;
    int sum=totsum/2;
    return subset(n,sum,a);
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int result=SubsetSum(a,n);
    if(result)
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}
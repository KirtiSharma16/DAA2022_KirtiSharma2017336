#include<bits/stdc++.h>
using namespace std;

int multiply(int i,int j,vector<int> &a,vector<vector<int>> &dp)
{
    if(i==j) 
    return 0;
    if(dp[i][j]=!-1)              //memoization
    return dp[i][j];
    int mini=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int steps=a[i-1]*a[k]*a[j] + multiply(i,k,a,dp)+multiply(k+1,j,a,dp);
        if(steps<mini)
        mini=steps;
    }
    return dp[i][j]=mini;
}

int matrixMultiply(vector<int> &a,int n)
{
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return multiply(1,n-1,a,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<=n;i++)
    cin>>a[i];
    int result=matrixMultiply(a,n+1);
    cout<<result<<endl;
    return 0;
}

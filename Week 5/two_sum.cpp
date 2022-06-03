#include<bits/stdc++.h>
using namespace std;

void two_sum(int a[],int n,int k)
{
    sort(a,a+n);
    int low=0,high=n-1;
    int flag=0;
    while(low<=high)
    {
        if(a[low]+a[high]==k)
        {
            cout<<a[low]<<" "<<a[high]<<endl;
            flag=1;
            low++;
            high--;
        }
        else if(a[low]+a[high]>k)
        high--;
        else if(a[low]+a[high]<k)
        low++;
    }
    if(flag==0)
    cout<<"No such pair exist"<<endl;
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
        two_sum(a,n,k);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool duplicate(int a[],int n)
{
    sort(a,a+n);
    int count=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
        {
            count++;
            return true;
        }
    }
    return false;
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
        int res=duplicate(a,n);
        if(res)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    return 0;
}

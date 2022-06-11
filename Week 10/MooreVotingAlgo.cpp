#include<bits/stdc++.h>
using namespace std;

bool findMajority(int a[],int n)
{
    int num=-1,c=0;
    for(int i=0;i<n;i++)
    {
        if(c==0)
        {
            num=a[i];
            c++;
        }
        else if(num==a[i])
        c++;
        else 
        c--;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(num==a[i])
        count++;
    }
    if(count>=n/2)
    return 1;
    else
    return 0;
}

float median(vector<int> &arr,int n)
{
    if(n%2==0)
    {
        nth_element(arr.begin(),arr.begin()+n/2,arr.end());
        nth_element(arr.begin(),arr.begin()+(n-1)/2,arr.end());
        return (float)(arr[n/2]+arr[(n-1)/2])/2.0;
    }
    else
    nth_element(arr.begin(),arr.begin()+n/2,arr.end());
    return (float)arr[n/2];
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int result=findMajority(a,n);
    if(result)
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    arr[i]=a[i];
    float m=median(arr,n);
    cout<<m<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

int k_smallest(int a[],int low,int high,int k)
{
    int pos=partition(a,low,high);
    if(pos-low+1==k)
    return a[pos];
    if(pos-low+1>k)
    return k_smallest(a,low,pos-1,k);
    if(pos-low+1<k)
    return k_smallest(a,pos+1,high,k-pos+low-1);
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
        int smallest=k_smallest(a,0,n-1,k);
        cout<<smallest<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int merge(int a[],int low,int mid,int high)
{
    int comp=0;
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
    left[i]=a[low+i];
    for(int i=0;i<n2;i++)
    right[i]=a[mid+1+i];
    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        comp++;
        if(left[i]>right[j])
        {
            a[k]=right[j];
            j++;
            k++;
        }
        else
        {
            a[k]=left[i];
            i++;
            k++;
        }
        comp++;
    }
    comp++;
    while(i<n1)
    {
        a[k]=left[i];
        i++;
        k++;
        comp++;
    }
    comp++;
    while(j<n2)
    {
        a[k]=right[j];
        j++;
        k++;
        comp++;
    }
    comp++;
    return comp;
}
int mergesort(int a[],int low,int high)
{
    int count=0;
    if(low<high)
    {
        int mid=low+(high-low)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        count=merge(a,low,mid,high);
    }
    return count;
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
        int comp=mergesort(a,0,n-1);
        cout<<comp<<endl;
    }
    return 0;
}
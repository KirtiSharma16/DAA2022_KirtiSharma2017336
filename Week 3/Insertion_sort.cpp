#include<bits/stdc++.h>
using namespace std;


void insertion(int a[],int n)
{
    int key,j,count=0,comp=0;
    for(int i=0;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
            comp++;
            count++;
        }
        a[j+1]=key;
        if(key>a[j])
        count++;
    }
    cout<<"Comparisions = "<<comp<<endl;
    cout<<"Shifts = "<<count<<endl;
    return ;
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
        insertion(a,n);
    }
    return 0;
}
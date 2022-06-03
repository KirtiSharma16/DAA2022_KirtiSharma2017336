#include<bits/stdc++.h>
using namespace std;

void selection(int a[],int n)
{
    int min,comp=0,swaps=0;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            min=j;
            comp++;
        }
        if(min!=i)
        {
            swaps++;
            swap(a[i],a[min]);
        }
    }
    cout<<"Comparisions = "<<comp<<endl;
    cout<<"Swaps = "<<swaps<<endl;
    return;
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
        selection(a,n);
    }
    return 0;
}
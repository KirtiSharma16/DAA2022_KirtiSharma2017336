#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int count=0;
int swaps=0;

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
            ::count++;
            ::swaps++;
        }
        ::count++;
    }
    swap(a[i+1],a[high]);
    ::swaps++;
    return i+1;
}

int partition_r(int a[],int low,int high)
{
    srand(time(NULL));
    int random=low+rand()%(high-low);
    swap(a[random],a[high]);
    ::swaps++;
    return partition(a,low,high);
}

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int pi=partition_r(a,low,high);
        quicksort(a,low,pi);
        quicksort(a,pi+1,high);
    }
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
        quicksort(a,0,n-1);
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
        cout<<"Comparisions = "<<::count<<endl;
        cout<<"Swaps = "<<::swaps<<endl;
    }
    return 0;
}
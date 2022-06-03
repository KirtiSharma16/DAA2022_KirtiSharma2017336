#include<iostream>
#include<math.h>
using namespace std;

int jumpsearch(int a[],int n,int key,int *count)
{
    int jump=sqrt(n);
    int steps=jump;
    int prev=0;

    while(a[min(steps,n)-1]<key)
    {
        (*count)++;
        prev=steps;
        steps+=jump;
        if(prev>n)
        return -1;
    }
    while(a[prev]<key)
    {
        prev++;
        //(*count)++;
        if(prev==min(steps,n))
        return -1;
    }
    if(a[prev]==key)
    return prev;
    
    return -1;
}

int main()
{
    int T;
    cout<<"Enter number of test cases ";
    cin>>T;
    while(T--)
    {
        int n,count=1;
        cout<<"Enter size ";
        cin>>n;
        int arr[n];
        cout<<"Enter elements ";
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int k;
        cout<<"Enter key ";
        cin>>k;
        int res=jumpsearch(arr,n,k,&count);
        if(res==-1)
        cout<<"Not present "<<count<<endl;
        else
        cout<<"Present "<<count<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;

int search(int a[],int n,int key,int searchfirst)
{
    int low=0,high=n-1,result=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(a[mid]==key)
        {
            result=mid;
            if(searchfirst)
            high=mid-1;
            else
            low=mid+1;
        }
        else if(a[mid]>key)
        high=mid-1;
        else
        low=mid+1;
    }
    return result;
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
        int first=search(a,n,k,1);
        int last=search(a,n,k,0);
        if(first==-1 && last==-1)
        {
            cout<<"Not present"<<endl;
        }
        else{
        int count=last-first+1;
        cout<<k<<" - "<<count<<endl;
        }
    }
    return 0;
}
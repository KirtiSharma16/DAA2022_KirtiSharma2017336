#include<iostream>
using namespace std;

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
        int flag=0;
        for(int k=0;k<n;k++)
        {
            int sum=a[k];
            int low=0,high=k-1;
            while(low<=high)
            {
                if(a[low]+a[high]==sum)
                {
                    cout<<low<<" "<<high<<" "<<k<<endl;
                    flag=1;
                    break;
                }
                else if(a[low]+a[high]>sum)
                    high--;
                else
                low++;
            }

        }
        if(flag==0)
        cout<<"No sequence found"<<endl;
    }
    return 0;
}
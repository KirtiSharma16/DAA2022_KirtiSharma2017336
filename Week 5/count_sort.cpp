#include<bits/stdc++.h>
using namespace std;

void maxOccurence(char a[],int n)
{
    int count[26]={0};
    for(int i=0;i<n;i++)
    {
        int c=int(a[i]);
        count[c-97]++;
    }
    int max=count[0];
    int j=0;
    for(int i=1;i<26;i++)
    {
        if(max<count[i])
        {
            max=count[i];
            j=i;
        }
    }
    if(max==1)
    {
        cout<<"No duplicate character"<<endl;
        return;
    }
    cout<<char(j+97)<<" - "<<max<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        maxOccurence(a,n);
    }
    return 0;
}
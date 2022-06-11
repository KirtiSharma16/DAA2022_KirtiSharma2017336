#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b)
{
    return a[1]<b[1];
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> task;
    int t[n],f[n];
    for(int i=0;i<n;i++)
    cin>>t[i];
    for(int i=0;i<n;i++)
    cin>>f[i];
    for(int i=0;i<n;i++)
    task.push_back({t[i],f[i],i+1});
    vector<int> selected;
    sort(task.begin(),task.end(),cmp);
    int c=1;
    int end=task[0][1];
    selected.push_back(1);
    for(int i=1;i<n;i++)
    {
        if(task[i][1]-task[i][0]>=end)
        {
            c++;
            end=task[i][1];
            selected.push_back(task[i][2]);
        }
    }
    sort(selected.begin(),selected.end());
    cout<<"Maximum number of tasks : "<<c<<endl;
    cout<<"List of selected tasks : ";
    for(auto i:selected)
    cout<<i<<" ";
    return 0;
}

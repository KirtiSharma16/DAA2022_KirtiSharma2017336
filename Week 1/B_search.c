#include<stdio.h>
void compare(int A[],int lb,int ub,int key,int *count)
{
    int mid=(lb+ub)/2;
    (*count)++;
    if(key==mid)
         return;
    else if(key>mid)
        compare(A,mid+1,ub,key,count);
    else if(key<mid)
        compare(A,lb,mid-1,key,count);
}


int main()
{
    int n,key,count=0,flag=0;
    printf("Enter size of the array ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of sorted array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the key ");
    scanf("%d",&key);
    compare(a,a[0],a[n-1],key,&count);
    if(count>n)
        printf("Key not found");
    else
        printf("key found after %d comparisions",count);
    return 0;
}

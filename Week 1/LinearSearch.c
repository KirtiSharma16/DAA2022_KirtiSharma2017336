#include<stdio.h>
int main()
{
    int n,key,count=0,flag=0;
    printf("Enter size of the array ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the non negative integers in the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the key ");
    scanf("%d",&key);
    for(int i=0;i<n;i++)
    {
        count++;
        if(key==a[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("Key found after %d comparisions",count);
    else
    printf("Key not found");
    return 0;
}

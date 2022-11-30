#include <bits/stdc++.h>

using namespace std;
int t,n,c;

int check(long long arr[],int size_arr, int key, long long distance)
{
    long long nho=arr[0];
    int dem=1;
    int i=1;
    while(i<size_arr)
    {
        if(arr[i]-nho>=distance)
        {
            dem++;
            nho=arr[i];
        }
        i++;
        if(dem>=key) return true;
    }
    return false;
}
int main()
{
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d%d",&n,&c);
        long long arr[100000];
        for(int j=0; j<n; j++)
            scanf("%lld",&arr[j]);
        sort(arr,arr+n);
        for(long long distance=(arr[n-1]-arr[0])/(c-1); distance>=0; distance--)
            if(check(arr,n,c,distance))
            {
                printf("%lld ",distance);
                break;
            }
    }
}
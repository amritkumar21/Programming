#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int i)
{
    int l =0;
    int r = size-1;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(arr[mid]==i)
        {
            if(mid-1<0) return 0;
            else if(arr[mid-1]<i) return mid;
            else r = mid-1;
        }
        else if (arr[mid]>i) r = mid-1;
        else l = mid+1;
    }
    return -1;
}
int main()
{
    int n,x;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    scanf("%d",&x);

    cout<< binarySearch(arr,n,x);
    return 0;

}
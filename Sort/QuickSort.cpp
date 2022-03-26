#include<iostream>
using namespace std;
#define MAX 100
void swap(int arr[], int x , int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y]  = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    int j=low;
    int temp;
    while(j!=high)
    {
        if(arr[j]<=pivot)
        swap(arr,++i,j);
        j++;
    }
    swap(arr,++i,high);
    return i;

}
void quickSort(int arr[], int low , int high)
{
    if(low<high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr,p+1, high);
    }
}
int main()
{
    int n;
    int arr[MAX];
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);

    return 0;

}
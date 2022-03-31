 #include<iostream>
 using namespace std;
 typedef  long long ll;
 long long ans=0;
 void copy(long long arr[], long long temp[], int low , int high)
    {
        for(int i=low;i<=high;i++)
        {
            arr[i]= temp[i];
        }
    }
    void merge(ll arr[], ll temp[], int low1,int high1, int low2, int high2)
    {
        int k = low1;
        while((low1<=high1)&&(low2<=high2))
        {
            if(arr[low1]<=arr[low2])
              temp[k++] = arr[low1++];
            else
            {
                ans+=(high1-low1);
                temp[k++] = arr[low2++];
            }
              
        }
        while(low1<=high1)
          temp[k++] = arr[low1++];
        while(low2<=high2)
          temp[k++] = arr[low2++];
    }
    void mergeSort(long long arr[], int low, int high)
    {
        long long temp[100];
        if(low<high)
        {
            int mid = low+(high-low)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,temp, low, mid,mid+1, high);
            copy(arr,temp,low,high);
        }
    }

int main()
{
    int n ;
    cin>>n;
    long long arr[100];
    for(int i=0;i<n;i++)
    scanf("%ld",&arr[i]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    cout<<" "<<arr[i];
    return 0;
}
    
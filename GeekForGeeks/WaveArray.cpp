void convertToWave(vector<int>& arr, int n)
    {
        
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i+=2)
        {
            arr[i-1] = arr[i-1]^arr[i];
            arr[i] = arr[i-1]^arr[i];
            arr[i-1] = arr[i-1]^arr[i];
        }
        
        
    }
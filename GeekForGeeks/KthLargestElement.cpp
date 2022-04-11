    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    void heapify(int arr[], int i, int n)
    {
        int l = 2*i+1;
        int r = 2*i+2;
        int largest = i;
        if(l<n&&arr[largest]<arr[l])
        largest = l;
        if(r<n&&arr[largest]<arr[r])
        largest = r;
        if(largest!=i)
        {
            swap(arr[largest],arr[i]);
            heapify(arr,largest,n);
        }
    }
    void buildHeap(int heap[], int n)
    {
        for(int i = (n/2)-1;i>=0;i--)
            heapify(heap,i,n);
    }
    
	vector<int> kLargest(int arr[], int n, int k) 
	{
	    vector<int> res;
	    int heap[n];
	    for(int i=0;i<n;i++)
	        heap[i] = arr[i];
	    buildHeap(heap,n);
	    
	    for(int i=0,j=n-1;i<k;i++,j--)
	    {
	        res.push_back(heap[0]);
	        heap[0] = heap[j];
	        heapify(heap,0,j);
	    }
	    return res;
	}
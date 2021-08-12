void minheapify(int arr[], int i, int n){
    int largest = i;
    if(2*i+1<n){
        if(arr[largest]>arr[2*i+1])
            largest = 2*i+1;
    }
    if(2*i<n){
        if(arr[largest]>arr[2*i])
            largest = 2*i;
    }

    if(largest!=i){
        swap(arr[i], arr[largest]);
        minheapify(arr, largest, n);

    }
    
}

void makeminheap(int arr[], int n){
    int i;

    for(i=n/2;i>=1;i--){
        minheapify(arr,i,n);
    }


}

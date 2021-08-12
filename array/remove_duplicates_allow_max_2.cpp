// C++ program to sort an array 
// duplicates max 2 can be there
#include <bits/stdc++.h> 
using namespace std; 

// Function to sort the input array, 
// the array is assumed 
// to have values in {0, 1, 2} 
int sort012(int a[], int arr_size) 
{ 
	int flag=0,j=0;

    for(int i=0;i<arr_size;i++){
        if((a[i]==a[i+1])){
            if(!flag){
            a[j++]=a[i];
            flag=1;
            }
            
        }
        else{
            a[j++]=a[i];
            flag=0;
        }


    }
 return j;
} 

void printArray(int arr[], int arr_size) 
{ 
	// Iterate and print every element 
	for (int i = 0; i < arr_size; i++) 
		cout << arr[i] << " "; 
} 
// Driver Code 
int main() 
{ 
	int arr[] = { 1,1,1,1,2,3,4,4,5,7,9,9,9,9}; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	int new_n=sort012(arr, n); 

	cout << "array after segregation "; 

	printArray(arr, new_n); 

	return 0; 
} 

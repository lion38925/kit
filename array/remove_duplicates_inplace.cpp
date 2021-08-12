
#include <bits/stdc++.h> 
using namespace std; 
// to remove duplicates elemets in place of an array
int removeDuplicates(arr, n)
{ 
	if(n==0||n==1)
        return n;
    int i ,j;
    j=0
    for (i=0;i<n-1;i++)
        if(arr[i]!=arr[i+1])
             arr[j++]=arr[i];
    arr[j++]=arr[n-1];              // for last element eg [2,3,5] then it will put 5 in right place

    return j;
} 

// Driver program to test above function 
int main() 
{ 
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // removeDuplicates() returns new size of 
    // array. 
    n = removeDuplicates(arr, n); 
  
    // Print updated array 
    for (int i=0; i<n; i++) 
       cout << arr[i] << " "; 
  
    return 0; 
} 
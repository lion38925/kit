// remove an element which occurs many times in an array
#include <bits/stdc++.h> 
using namespace std; 

int removeDuplicate(arr, n,value)
{ 
	if(n==0||n==1)
        return n;
    int i ,j;
    j=0
    for (i=0;i<n;i++)
        if(arr[i]! = value)
             arr[j++]=arr[i];
              

    return j;
} 

// Driver program to test above function 
int main() 
{ 
    int arr[] = {3,2,2,3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int value = 3;
  
    // removeDuplicate() returns new size of 
    // array. 
    n = removeDuplicate(arr, n, value); 
  
    // Print updated array 
    for (int i=0; i<n; i++) 
       cout << arr[i] << " "; 
  
    return 0; 
} 
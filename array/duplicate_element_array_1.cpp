// C++ program to find duplicate in an array

#include <bits/stdc++.h> 
using namespace std; 


int containsDuplicate(int arr[]) 
{ 
    unordered_set<int> dups;
	for (int i = 0; i < size; i++){ 
        if(dups.find(arr[i])!=dups.end())
            return 1;
        dups.insert(arr[i]);
    }
    return 0;
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6, 2 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// Function calling 
	int val = containsDuplicate(arr); 
    cout<<val?"YES":"NO";


	return 0; 
} 

// another way to find duplicate element if 
// all elements are +ve and within range

/*

// C++ code to find 
// duplicates in O(n) time 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print duplicates 
void printRepeating(int arr[], int size) 
{ 
int i; 
cout << "The repeating elements are:" << endl; 
for (i = 0; i < size; i++) 
{ 
	if (arr[abs(arr[i])] >= 0) 
	arr[abs(arr[i])] = -arr[abs(arr[i])]; 
	else
	cout << abs(arr[i]) << " "; 
} 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {1, 2, 3, 1, 3, 6, 6}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 
	printRepeating(arr, arr_size); 
	return 0; 
} 


*/

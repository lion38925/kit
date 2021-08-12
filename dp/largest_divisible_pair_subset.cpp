// CPP program to find the largest subset which 
// where each pair is divisible. 
// this code is only to tell the length, below this there
// is another code to give the array
#include <bits/stdc++.h> 
using namespace std; 

// function to find the longest Subsequence 
int largestSubset(int a[], int n) 
{ 
	// Sort array in increasing order 
	sort(a, a + n); 

	// dp[i] is going to store size of largest 
	// divisible subset beginning with a[i]. 
	int dp[n]; 

	// Since last element is largest, d[n-1] is 1 
	dp[n - 1] = 1; 

	// Fill values for smaller elements. 
	for (int i = n - 2; i >= 0; i--) { 

		// Find all multiples of a[i] and consider 
		// the multiple that has largest subset 
		// beginning with it. 
		int mxm = 0; 
		for (int j = i + 1; j < n; j++) 
			if (a[j] % a[i] == 0) 
				mxm = max(mxm, dp[j]); 

		dp[i] = 1 + mxm; 
	} 

	// Return maximum value from dp[] 
	return *max_element(dp, dp + n); 
} 

// driver code to check the above function 
int main() 
{ 
	int a[] = { 1, 3, 6, 13, 17, 18 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	cout << largestSubset(a, n) << endl; 
	return 0; 
} 



////


// C++ program to find largest divisible 
// subset in a given array 
#include<bits/stdc++.h> 
using namespace std; 

// Prints largest divisible subset 
void findLargest(int arr[], int n) 
{ 
	// We first sort the array so that all divisors 
	// of a number are before it. 
	sort(arr, arr+n); 

	// To store count of divisors of all elements 
	vector <int> divCount(n, 1); 

	// To store previous divisor in result 
	vector <int> prev(n, -1); 

	// To store index of largest element in maximum 
	// size subset 
	int max_ind = 0; 

	// In i'th iteration, we find length of chain 
	// ending with arr[i] 
	for (int i=1; i<n; i++) 
	{ 
		// Consider every smaller element as previous 
		// element. 
		for (int j=0; j<i; j++) 
		{ 
			if (arr[i]%arr[j] == 0) 
			{ 
				if (divCount[i] < divCount[j] + 1) 
				{ 
					divCount[i] = divCount[j]+1; 
					prev[i] = j; 
				} 
			} 
		} 

		// Update last index of largest subset if size 
		// of current subset is more. 
		if (divCount[max_ind] < divCount[i]) 
			max_ind = i; 
	} 

	// Print result 
	int k = max_ind; 
	while (k >= 0) 
	{ 
		cout << arr[k] << " "; 
		k = prev[k]; 
	} 
} 

// Driven code 
int main() 
{ 
	int arr[] = {1, 2, 17, 4}; 
	int n = sizeof(arr)/sizeof(int); 
	findLargest(arr, n); 
	return 0; 
} 


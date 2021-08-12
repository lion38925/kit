#include <iostream>
#include <string>
#include <climits>
using namespace std;

// Function to find best way to cut a rod of length n
// where rod of length i has a cost price[i-1]
int rodCut(int price[], int n)
{
	// base case
	if (n == 0)
		return 0;

	int maxValue = INT_MIN;

	// one by one partition the given rod of length n into two parts
	// of length (1, n-1), (2, n-2), (3, n-3), .... (n-1 , 1), (n, 0)
	// and take maximum
	for (int i = 1; i <= n; i++)
	{
		// rod of length i has a cost price[i-1]
		int cost = price[i - 1] + rodCut(price, n - i);

		if (cost > maxValue)
			maxValue = cost;
	}

	return maxValue;
}

// main function
int main()
{
	int length[] = { 1, 2, 3, 4, 5, 6, 7, 8 };	// dummy
	int price [] = { 1, 5, 8, 9, 10, 17, 17, 20 };

	// rod length
	int n = 4;

	cout << "Profit is " << rodCut(price, n);

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
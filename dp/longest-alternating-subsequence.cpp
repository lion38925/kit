// C++ program to find longest alternating 
// subsequence in an array
#include<iostream>
using namespace std;

// Function to return max of two numbers
// there is better solution see below another code
int max(int a, int b)
{ 
	return (a > b) ? a : b;
}

// Function to return longest alternating 
// subsequence length
int zzis(int arr[], int n)
{
	
	/*las[i][0] = Length of the longest 
		alternating subsequence ending at
		index i and last element is greater
		than its previous element
	las[i][1] = Length of the longest 
		alternating subsequence ending 
		at index i and last element is
		smaller than its previous element */
	int las[n][2];

	// Initialize all values from 1 
	for(int i = 0; i < n; i++)
		las[i][0] = las[i][1] = 1;
	
	// Initialize result
	int res = 1; 

	// Compute values in bottom up manner 
	for(int i = 1; i < n; i++)
	{
		
		// Consider all elements as 
		// previous of arr[i]
		for(int j = 0; j < i; j++)
		{
			
			// If arr[i] is greater, then 
			// check with las[j][1]
			if (arr[j] < arr[i] && 
				las[i][0] < las[j][1] + 1)
				las[i][0] = las[j][1] + 1;

			// If arr[i] is smaller, then 
			// check with las[j][0]
			if(arr[j] > arr[i] && 
			las[i][1] < las[j][0] + 1)
				las[i][1] = las[j][0] + 1;
		}

		// Pick maximum of both values at index i 
		if (res < max(las[i][0], las[i][1]))
			res = max(las[i][0], las[i][1]);
	}
	return res;
}

// Driver code
int main()
{
	int arr[] = { 10, 22, 9, 33, 
				49, 50, 31, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	cout << "Length of Longest alternating "
		<< "subsequence is " << zzis(arr, n);
		
	return 0;
}

// efficient solution O(n)

// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

// Function for finding
// longest alternating
// subsequence
int LAS(int arr[], int n)
{

	// "inc" and "dec" intialized as 1
	// as single element is still LAS
	int inc = 1;
	int dec = 1;

	// Iterate from second element
	for (int i = 1; i < n; i++) 
	{

		if (arr[i] > arr[i - 1]) 
		{

			// "inc" changes iff "dec" 
			// changes
			inc = dec + 1;
		}

		else if (arr[i] < arr[i - 1]) 
		{

			// "dec" changes iff "inc" 
			// changes
			dec = inc + 1;
		}
	}

	// Return the maximum length
	return max(inc, dec);
}

// Driver Code
int main()
{
	int arr[] = { 10, 22, 9, 33, 49, 
						50, 31, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	cout << LAS(arr, n) << endl;
	return 0;
}


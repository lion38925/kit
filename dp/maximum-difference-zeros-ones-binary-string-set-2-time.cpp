// CPP Program to find the length of 
// substring with maximum difference of 
// zeros and ones in binary string. 
#include <iostream> 
using namespace std; 

//In the post we seen an efficient method that work in O(n) time and in O(1) extra space.
//Idea behind that if we convert all zeros into 1 and all ones into -1.now our problem reduces
//to find out the maximum sum sub_array Using Kadane’s Algorithm.


// Returns the length of substring with 
// maximum difference of zeroes and ones 
// in binary string 
int findLength(string str, int n) 
{ 
	int current_sum = 0; 
	int max_sum = 0; 

	// traverse a binary string from left 
	// to right 
	for (int i = 0; i < n; i++) { 

		// add current value to the current_sum 
		// according to the Character 
		// if it's '0' add 1 else -1 
		current_sum += (str[i] == '0' ? 1 : -1); 

		if (current_sum < 0) 
			current_sum = 0; 

		// update maximum sum 
		max_sum = max(current_sum, max_sum); 
	} 

	// return -1 if string does not contain 
	// any zero that means all ones 
	// otherwise max_sum 
	return max_sum == 0 ? -1 : max_sum; 
} 

// Driven Program 
int main() 
{ 
	string s = "11000010001"; 
	int n = 11; 
	cout << findLength(s, n) << endl; 
	return 0; 
} 

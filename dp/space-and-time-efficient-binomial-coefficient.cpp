// Program to calculate C(n, k) 
#include <bits/stdc++.h> 
using namespace std; 

// Returns value of Binomial Coefficient C(n, k) 
// time comlexity O(r)
int binomialCoeff(int n, int k) 
{ 
	int res = 1; 

	// Since C(n, k) = C(n, n-k) 
	if (k > n - k) 
		k = n - k; 

	// Calculate value of 
	// [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
	for (int i = 0; i < k; ++i) { 
		res *= (n - i); 
		res /= (i + 1); 
	} 

	return res; 
} 

// Driver Code 
int main() 
{ 
	int n = 8, k = 2; 
	cout << "Value of C(" << n << ", "
		<< k << ") is " << binomialCoeff(n, k); 
	return 0; 
} 

// dp code down here


// A Dynamic Programming based solution that uses
// table C[][] to calculate the Binomial Coefficient
#include <bits/stdc++.h>
using namespace std;

// Prototype of a utility function that
// returns minimum of two integers
int min(int a, int b);

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
	int C[n + 1][k + 1];
	int i, j;

	// Caculate value of Binomial Coefficient
	// in bottom up manner
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= min(i, k); j++) {  // if k >n then it would be illogical 
			// Base Cases
			if (j == 0 || j == i)
				C[i][j] = 1;

			// Calculate value using previously
			// stored values
			else
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	return C[n][k];
}

// A utility function to return
// minimum of two integers
int min(int a, int b) { return (a < b) ? a : b; }

// Driver Code
int main()
{
	int n = 5, k = 2;
	cout << "Value of C[" << n << "][" << k << "] is "
		<< binomialCoeff(n, k);
}




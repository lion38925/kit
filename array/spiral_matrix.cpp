#include <bits/stdc++.h> 
using namespace std; 
#define R 3 
#define C 6 

void spiralPrint(int m, int n, int a[R][C]) 
{ 
	int i, k = 0, l = 0; 

	/* k - starting row index 
		m - ending row index 
		l - starting column index 
		n - ending column index 
		i - iterator 
	*/

	while (k < m && l < n) { 							 // we are checking this as we cannot go beyound the m and n
		/* Print the first row from 
			the remaining rows */
		for (i = l; i < n; ++i) { 
			cout << a[k][i] << " "; 
		} 	
		k++; 											  // k incremented

		/* Print the last column 
		from the remaining columns */
		for (i = k; i < m; ++i) { 
			cout << a[i][n - 1] << " "; 
		} 
		n--; 

		/* Print the last row from 
				the remaining rows */						// these two conditions are very important and must
		if (k < m) { 										// we are checking this condition as above we incremented k 
															// so we need to check it
			for (i = n - 1; i >= l; --i) { 	
				cout << a[m - 1][i] << " "; 
			} 
			m--; 
		} 

		/* Print the first column from 
				the remaining columns */
		if (l < n) { 										// similarly we decremented n we need to check l
			for (i = m - 1; i >= k; --i) { 
				cout << a[i][l] << " "; 
			} 
			l++; 
		} 
	} 
} 

/* Driver program to test above functions */
int main() 
{ 
	int a[R][C] = { { 1, 2, 3, 4, 5, 6 }, 
					{ 7, 8, 9, 10, 11, 12 }, 
					{ 13, 14, 15, 16, 17, 18 } }; 

	spiralPrint(R, C, a); 
	return 0; 
} 

// This is code is contributed by rathbhupendra 

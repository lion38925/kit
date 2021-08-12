// See the Cormen book for details of the 
// following algorithm 
#include <bits/stdc++.h> 
using namespace std; 

// Matrix Ai has dimension p[i-1] x p[i] 
// for i = 1..n 

// ---  https://www.youtube.com/watch?v=pEYwLmGJcvs&ab_channel=Pepcoding


int MatrixChainOrder(int p[], int n) 
{ 

	/* For simplicity of the program, one 
	extra row and one extra column are 
	allocated in m[][]. 0th row and 0th 
	column of m[][] are not used */
	int m[n][n]; 

	int i, j, k, L, q; 

	/* m[i, j] = Minimum number of scalar 
	multiplications needed to compute the 
	matrix A[i]A[i+1]...A[j] = A[i..j] where 
	dimension of A[i] is p[i-1] x p[i] */


	for (int g = 0; g < n; g++) 
	{ 
		for (i = 0,j=g; j < n; i++,j++) 
		{ 
			if(g==0){
                m[i][j]=0;

            }else if(g==1){
                m[i][j] = p[i]*p[j]*p[j+1];

            }else{
                m[i][j] = INT_MAX;
                for (k = i; k <j; k++)
                {
                    // q = cost/scalar multiplications
                    q = m[i][k] + m[k + 1][j] + p[i] * p[k+1] * p[j+1];
                    if (q < m[i][j])
                        m[i][j] = q;
                }
            }
		} 
	} 

	return m[1][n - 1]; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 1, 2, 3, 4 }; 
	int size = sizeof(arr) / sizeof(arr[0]); 

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, size); 

	getchar(); 
	return 0; 
} 

// This code is contributed 
// by Akanksha Rai

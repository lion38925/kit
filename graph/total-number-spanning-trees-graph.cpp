/*

total-number-spanning-trees-graph

- to find this 

-- if graph is complete graph means

Complete Graph: A simple graph with n vertices is called a complete graph if the degree of each vertex is n-1,
that is, one vertex is attach with n-1 edges. A complete graph is also called Full Graph.

then answere is n^n-2

else follow these steps

Create Adjacency Matrix for the given graph.
STEP 2: Replace all the diagonal elements with the degree of nodes.
For eg. element at (1,1) position of adjacency matrix will be replaced by the degree of node 1,
element at (2,2) position of adjacency matrix will be replaced by the degree of node 2, and so on.
STEP 3: Replace all non-diagonal 1’s with -1.

STEP 4: remove one row and one column

STEP 5: now find out the determinant of the matrix

*/

///  code to find out the determinant of the matrix of any size

/// not so important code but above steps are important

// C++ program to find Deteminant of a matrix
#include <bits/stdc++.h>
using namespace std;

// Dimension of input square matrix
#define N 4

// Function to get cofactor of mat[p][q] in temp[][]. n is
// current dimension of mat[][]
void getCofactor(int mat[N][N], int temp[N][N], int p,
				int q, int n)
{
	int i = 0, j = 0;

	// Looping for each element of the matrix
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++) 
		{
			// Copying into temporary matrix only those
			// element which are not in given row and
			// column
			if (row != p && col != q) 
			{
				temp[i][j++] = mat[row][col];

				// Row is filled, so increase row index and
				// reset col index
				if (j == n - 1) 
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

/* Recursive function for finding determinant of matrix.
n is current dimension of mat[][]. */
int determinantOfMatrix(int mat[N][N], int n)
{
	int D = 0; // Initialize result

	// Base case : if matrix contains single element
	if (n == 1)
		return mat[0][0];

	int temp[N][N]; // To store cofactors

	int sign = 1; // To store sign multiplier

	// Iterate for each element of first row
	for (int f = 0; f < n; f++) 
	{
		// Getting Cofactor of mat[0][f]
		getCofactor(mat, temp, 0, f, n);
		D += sign * mat[0][f]
			* determinantOfMatrix(temp, n - 1);

		// terms are to be added with alternate sign
		sign = -sign;
	}

	return D;
}

/* function for displaying the matrix */
void display(int mat[N][N], int row, int col)
{
	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++)
			printf(" %d", mat[i][j]);
		printf("n");
	}
}

// Driver program to test above functions
int main()
{
	/* int mat[N][N] = {{6, 1, 1},
					{4, -2, 5},
					{2, 8, 7}}; */

	int mat[N][N] = { { 1, 0, 2, -1 },
					{ 3, 0, 0, 5 },
					{ 2, 1, 4, -3 },
					{ 1, 0, 5, 0 } };

	// Function call
	printf("Determinant of the matrix is : %d",
		determinantOfMatrix(mat, N));
	return 0;
}

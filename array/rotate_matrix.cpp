

// C++ program to rotate a matrix by 90 degrees 


// C++ program for left rotation of matrix by 90 
// degree without using extra space 

// anticlockwise
#include <bits/stdc++.h> 
using namespace std; 
#define R 4 
#define C 4 

// After transpose we swap elements of column 
// one by one for finding left rotation of matrix 
// by 90 degree 

// this code is for anticlockwise for clockwise follow:
// The approach would be similar. 
// Find the transpose of the matrix and then reverse the rows of the transposed matrix.
void reverseColumns(int arr[R][C]) 
{ 
	for (int i = 0; i < C; i++) 
		for (int j = 0, k = C - 1; j < k; j++, k--) 
			swap(arr[j][i], arr[k][i]); 
} 

// Function for do transpose of matrix 
void transpose(int arr[R][C]) 
{ 
	for (int i = 0; i < R; i++) 
		for (int j = i; j < C; j++) 
			swap(arr[i][j], arr[j][i]); 
} 

// Function for print matrix 
void printMatrix(int arr[R][C]) 
{ 
	for (int i = 0; i < R; i++) { 
		for (int j = 0; j < C; j++) 
			cout << arr[i][j] << " "; 
		cout << '\n'; 
	} 
} 

// Function to anticlockwise rotate matrix 
// by 90 degree 
void rotate90(int arr[R][C]) 
{ 
	transpose(arr); 
	reverseColumns(arr); 
} 

// Driven code 
int main() 
{ 
	int arr[R][C] = { { 1, 2, 3, 4 }, 
					{ 5, 6, 7, 8 }, 
					{ 9, 10, 11, 12 }, 
					{ 13, 14, 15, 16 } }; 
	rotate90(arr); 
	printMatrix(arr); 
	return 0; 
} 

/* another code using extra space */
// Anticlockwise

#include <bits/stdc++.h> 
#define N 4 
using namespace std; 

void displayMatrix(int mat[N][N]); 

// An Inplace function to rotate a N x N matrix 
// by 90 degrees in anti-clockwise direction 
void rotateMatrix(int mat[][N]) 
{ 
	// Consider all squares one by one 
	for (int x = 0; x < N / 2; x++) 
	{ 
		// Consider elements in group of 4 in 
		// current square 
		for (int y = x; y < N-x-1; y++) 
		{ 
			// store current cell in temp variable 
			int temp = mat[x][y]; 

			// move values from right to top 
			mat[x][y] = mat[y][N-1-x]; 

			// move values from bottom to right 
			mat[y][N-1-x] = mat[N-1-x][N-1-y]; 

			// move values from left to bottom 
			mat[N-1-x][N-1-y] = mat[N-1-y][x]; 

			// assign temp to left 
			mat[N-1-y][x] = temp; 
		} 
	} 
} 

// Function to print the matrix 
void displayMatrix(int mat[N][N]) 
{ 
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++) 
			printf("%2d ", mat[i][j]); 

		printf("\n"); 
	} 
	printf("\n"); 
} 


/* Driver program to test above functions */
int main() 
{ 
	// Test Case 1 
	int mat[N][N] = 
	{ 
		{1, 2, 3, 4}, 
		{5, 6, 7, 8}, 
		{9, 10, 11, 12}, 
		{13, 14, 15, 16} 
	}; 


	// Tese Case 2 
	/* int mat[N][N] = { 
						{1, 2, 3}, 
						{4, 5, 6}, 
						{7, 8, 9} 
					}; 
	*/

	// Tese Case 3 
	/*int mat[N][N] = { 
					{1, 2}, 
					{4, 5} 
				};*/

	//displayMatrix(mat); 

	rotateMatrix(mat); 

	// Print rotated matrix 
	displayMatrix(mat); 

	return 0; 
} 

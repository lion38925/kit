#include <bits/stdc++.h> 
using namespace std; 
// Function to find the index of first index  
// of 1 in a boolean array arr[]  
int first(bool arr[], int low, int high)  	// this function is just binary search
{  
    if(high >= low)  
    {  
        // Get the middle index  
        int mid = low + (high - low)/2;  
      
        // Check if the element at middle index is first 1  
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)  
            return mid;  
      
        // If the element is 0, recur for right side  
        else if (arr[mid] == 0)  
            return first(arr, (mid + 1), high);  
          
        // If element is not first 1, recur for left side  
        else
            return first(arr, low, (mid -1));  
    }  
    return -1;  
}  
  
// The main function that returns index 
// of row with maximum number of 1s. 
int rowWithMax1s(bool mat[R][C]) 
{ 
	int i, index; 

	// Initialize max using values from first row. 
	int max_row_index = 0; 
	int max = first(mat[0], 0, C - 1); 

	// Traverse for each row and count number of 1s 
	// by finding the index of first 1 
	for (i = 1; i < R; i++) 
	{ 
		// Count 1s in this row only if this row 
		// has more 1s than max so far 

		// Count 1s in this row only if this row 
		// has more 1s than max so far 
		if (max != -1 && mat[i][C - max - 1] == 1) 
		{ 
			// Note the optimization here also 
			index = first (mat[i], 0, C - max); 

			if (index != -1 && C - index > max) 
			{ 
				max = C - index; 
				max_row_index = i; 
			} 
		} 
		else
		{ 
			max = first(mat[i], 0, C - 1); 
		} 
	} 
	return max_row_index; 
} 

// This code is contributed by rathbhupendra 

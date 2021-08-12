// in this solution we are considering the size of nums1 is equal to sum of both arrays
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {        
        int p1 = m - 1;
        int p2 = n - 1;
        for (int i = m + n - 1; i >= 0; --i) {
            if (p2 < 0 || (p1 >= 0 && nums1[p1] > nums2[p2])) {
                nums1[i] = nums1[p1--];
            }
            else {
                nums1[i] = nums2[p2--];
            }
        }
    }
};

// when we need to merge arrays and we dont have any extra size array

// C++ program to merge two sorted arrays with O(1) extra space. 
#include <bits/stdc++.h> 
using namespace std; 

// Merge ar1[] and ar2[] with O(1) extra space 
void merge(int ar1[], int ar2[], int m, int n) 
{ 
	// Iterate through all elements of ar2[] starting from 
	// the last element 
	for (int i=n-1; i>=0; i--) 
	{ 
		/* Find the smallest element greater than ar2[i]. Move all 
		elements one position ahead till the smallest greater 
		element is not found */
		int j, last = ar1[m-1]; 
		for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--) 
			ar1[j+1] = ar1[j]; 

		// If there was a greater element 
		if (j != m-2 || last > ar2[i]) 
		{ 
			ar1[j+1] = ar2[i]; 
			ar2[i] = last; 
		} 
	} 
} 

// Driver program 
int main(void) 
{ 
	int ar1[] = {1, 5, 9, 10, 15, 20}; 
	int ar2[] = {2, 3, 8, 13}; 
	int m = sizeof(ar1)/sizeof(ar1[0]); 
	int n = sizeof(ar2)/sizeof(ar2[0]); 
	merge(ar1, ar2, m, n); 

	cout << "After Merging nFirst Array: "; 
	for (int i=0; i<m; i++) 
		cout << ar1[i] << " "; 
	cout << "nSecond Array: "; 
	for (int i=0; i<n; i++) 
		cout << ar2[i] << " "; 
return 0; 
} 

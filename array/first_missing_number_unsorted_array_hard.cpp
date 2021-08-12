/* C++ program to find the smallest positive missing number */
#include <bits/stdc++.h> 
using namespace std; 

/* Utility to swap to integers */
void swap(int* a, int* b) 
{ 
	int temp; 
	temp = *a; 
	*a = *b; 
	*b = temp; 
} 

/* Utility function that puts all 
non-positive (0 and negative) numbers on left 
side of arr[] and return count of such numbers */
int segregate(int arr[], int size) 
{ 							
	int j = 0, i; 
	for (i = 0; i < size; i++) { 
		if (arr[i] <= 0) { 
			swap(&arr[i], &arr[j]); 
			j++; // increment count of non-positive integers 
		} 
	} 

	return j; 
} 

/* Find the smallest positive missing number 
in an array that contains all positive integers */
int findMissingPositive(int arr[], int size) 
{ 
	int i; 												// this one solution if for array, down below solution is for vector

	// Mark arr[i] as visited by making arr[arr[i] - 1] negative. 
	// Note that 1 is subtracted because index start 
	// from 0 and positive numbers start from 1 
	for (i = 0; i < size; i++) { 
		if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0) 
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; 
	} 

	// Return the first index value at which is positive 
	for (i = 0; i < size; i++) 
		if (arr[i] > 0) 
			// 1 is added because indexes start from 0 
			return i + 1; 

	return size + 1; 
} 

/* Find the smallest positive missing 
number in an array that contains 
both positive and negative integers */
int findMissing(int arr[], int size) 
{ 
	// First separate positive and negative numbers 
	int shift = segregate(arr, size); 

	// Shift the array and call findMissingPositive for 
	// positive part 
	return findMissingPositive(arr + shift, size - shift); 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 0, 10, 2, -10, -20 }; 
	int arr_size = sizeof(arr) / sizeof(arr[0]); 
	int missing = findMissing(arr, arr_size); 
	cout << "The smallest positive missing number is " << missing; 
	return 0; 
} 

// vector solution

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        long long i,j,k,l,m=0,n,f=0,flag=0;
        
        n=nums.size();
        
        f = seg(nums);

        for(i=f;i<n;i++){
            if((abs(nums[i])-1+f<n)&&nums[abs(nums[i])-1+f]>0){
                nums[abs(nums[i])-1+f]*=-1;
            }
                
        }
        
        for(i=f;i<n;i++){
            if(nums[i]>0){
                m = i-f+1;
                flag=1;
                break;
            }
        }
        
        if(flag)
            return m;
        else
            return nums.size()+1-f;
        
    }
    int seg(vector<int>& nums){
        
        int i,j,k;
        j=0;
        
        for(i=0;i<nums.size();i++){
            if(nums[i]<=0){
                int temp = nums[j];
                nums[j] =nums[i];
                nums[i]=temp;
                j++;
            }
        }
        return j;
    }
};


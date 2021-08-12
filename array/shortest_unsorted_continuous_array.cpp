// C++ program to find the Minimum length Unsorted Subarray, 
// sorting which makes the complete array sorted 
#include<bits/stdc++.h> 
using namespace std; 

void printUnsorted(int arr[], int n) 
{ 
int s = 0, e = n-1, i, max, min; 

// step 1(a) of above algo 
for (s = 0; s < n-1; s++) 
{ 
	if (arr[s] > arr[s+1]) 
	break; 
} 
if (s == n-1) 
{ 
	cout << "The complete array is sorted"; 
	return; 
} 

// step 1(b) of above algo 
for(e = n - 1; e > 0; e--) 
{ 
	if(arr[e] < arr[e-1]) 
	break; 
} 

// step 2(a) of above algo 
max = arr[s]; min = arr[s]; 
for(i = s + 1; i <= e; i++) 
{ 
	if(arr[i] > max) 
	max = arr[i]; 
	if(arr[i] < min) 
	min = arr[i]; 
} 

// step 2(b) of above algo 
for( i = 0; i < s; i++) 
{ 
	if(arr[i] > min) 
	{ 
	s = i; 
	break; 
	}	 
} 

// step 2(c) of above algo 
for( i = n -1; i >= e+1; i--) 
{ 
	if(arr[i] < max) 
	{ 
	e = i; 
	break; 
	} 
} 
	
// step 3 of above algo 
cout << "The unsorted subarray which"
	<< " makes the given array" << endl 
	<< "sorted lies between the indees "
	<< s << " and " << e; 
return; 
} 

int main() 
{ 
	int arr[] = {10, 12, 20, 30, 25, 
				40, 32, 31, 35, 50, 60}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 
	printUnsorted(arr, arr_size); 
	getchar(); 
	return 0; 
} 

// This code is contributed 
// by Akanksha Rai 



/// second code


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left=-1;
        int right;
        //finding the leftmost boundary that violates the condition
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                left = i;
                break;
            }
        }
        //if the array is sorted then return 0
        if(left==-1) return 0;
        //finding the rightmost boundary that violates the condition
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i]<nums[i-1]){
                right = i;
                break;
            }
        }
        //finding the minimum and maximum in the range [left,right]
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=left; i<=right; i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        //updating the left boundary if any number before left is greater than the min
        for(int i=0; i<=left; i++){
            if(nums[i]>mini){
                left = i;
                break;
            }
        }
        //updating the righ boundary if any number after right is lesser than the max
        for(int i=nums.size()-1; i>=right; i--){
            if(nums[i]<maxi){
                right = i;
                break;
            }
        }
        //return length
        return right-left+1;   
    }
};

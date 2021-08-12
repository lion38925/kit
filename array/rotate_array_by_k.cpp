// C++ program to rotate an array by 
// d elements 
#include <bits/stdc++.h> 
using namespace std; 

/*Fuction to get gcd of a and b*/
int gcd(int a, int b) 
{ 
	if (b == 0) 
		return a; 

	else
		return gcd(b, a % b); 
} 

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n) 
{ 
	int g_c_d = gcd(d, n); 
	for (int i = 0; i < g_c_d; i++) { 
		/* move i-th values of blocks */
		int temp = arr[i]; 						///  to shift right add some more conditions
												if(d>n)
													d=d%n;
												d=n-d;
												// these conditions are mandatory for right shift and left shift
		int j = i; 

		while (1) { 
			int k = j + d; 
			if (k >= n) 
				k = k - n; 

			if (k == i) 
				break; 

			arr[j] = arr[k]; 
			j = k; 
		} 
		arr[j] = temp; 
	} 
} 

// Function to print an array 
void printArray(int arr[], int size) 
{ 
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " "; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// Function calling 
	leftRotate(arr, 2, n); 
	printArray(arr, n); 

	return 0; 
} 



//// code for right shift of array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int i,j,l,m,n,g,temp,d,temp2;
        n = nums.size();
        g = gcd(n,k);
        if(nums.size()==0||nums.size()==1)
            return;
        if(k>n)
            k=k%n;
        k=n-k;
        for(i=0;i<g;i++){
            j=i;
            temp = nums[i];
            while(1){
                //cout<<j<<"\n";
                d = j+k;
                if(d>=n)
                    d=d-n;
                if(d==i)
                    break;
                nums[j] = nums[d];
                j= d;
                
            }
            nums[j]=temp;
        }
        
    }
    
    int gcd(int a, int b) 
    { 
        if (a == 0) 
            return b; 
        return gcd(b % a, a); 
    } 
  
};
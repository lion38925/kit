// C++ program for product array puzzle 
// with O(n) time and O(1) space. 
#include <bits/stdc++.h> 
using namespace std; 

// epsilon value to maintain precision 
#define EPS 1e-9 

void productPuzzle(int a[], int n) 						// this will not work if there is scenario with zero as log(0) is undefined
														// and log of negative numbers is also not available so it is also a problem
{ 
	// to hold sum of all values 
	long double sum = 0; 
	for (int i = 0; i < n; i++) 
		sum += (long double)log10(a[i]); 

	// output product for each index 
	// antilog to find original product value 
	for (int i = 0; i < n; i++) 
		cout << (int)(EPS + pow((long double)10.00, 
						sum - log10(a[i]))) << " "; 
} 

// Driver code 
int main() 
{ 
	int a[] = { 10, 3, 5, 6, 2 }; 
	int n = sizeof(a)/sizeof(a[0]); 
	cout << "The product array is: \n"; 
	productPuzzle(a, n); 
	return 0; 
} 

/// solution without log which will give correct result 
// this solution is made using two array of left and right product

#define eps 1e-9
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
    int i,j,k,flag = 0,n;
    long double sum=0;
    vector<int> v,l,r;
    n= nums.size();
    l.push_back(1);
    l.push_back(nums[0]);
        
    for(i=2;i<n;i++){
        l.push_back(nums[i-1]*l[i-1]);
        //cout<<l[i];
    }
       
    r.push_back(1);
    r.insert(r.begin(),nums[n-1]);
    //cout<<r[0];
    for(i=n-3;i>=0;i--){
        //cout<<r.size();
        r.insert(r.begin(),nums[i+1]*r[0]);
        
    }
    //for(i=0)
    
    for(i=0;i<n;i++){
        v.push_back(l[i]*r[i]);
    }
    return v;
    }
};
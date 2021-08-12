// A hashing based CPP program to find if there are 
// four elements with given sum. 
#include <bits/stdc++.h> 
using namespace std; 
//this code only finds one pair to find all pair do not return in the code

// The function finds four elements with given sum X 
void findFourElements (int arr[], int n, int X) 
{ 
	// Store sums of all pairs in a hash table 
	unordered_map<int, pair<int, int>> mp; 
	for (int i = 0; i < n-1; i++) 
		for (int j = i+1; j < n; j++) 
			mp[arr[i] + arr[j]] = {i, j}; 

	// Traverse through all pairs and search 
	// for X - (current pair sum).	 
	for (int i = 0; i < n-1; i++) 
	{ 
		for (int j = i+1; j < n; j++) 
		{ 
			int sum = arr[i] + arr[j]; 

			// If X - sum is present in hash table,			 
			if (mp.find(X - sum) != mp.end()) 				// in this solution we are not considering what if two same sum comes
															// and map will only hold one of them for that solution is down below
			{ 

				// Making sure that all elements are 
				// distinct array elements and an element 
				// is not considered more than once. 
				pair<int, int> p = mp[X - sum]; 
				if (p.first != i && p.first != j && 
						p.second != i && p.second != j) 
				{ 
					cout << arr[i] << ", " << arr[j] << ", "
						<< arr[p.first] << ", "
						<< arr[p.second]; 
					return; 
				} 
			} 
		} 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = {10, 20, 30, 40, 1, 2}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int X = 91; 
	findFourElements(arr, n, X); 
	return 0; 
} 


/// solution of what if two same sum comes and in map only one of them is pushed then we use vector inside map

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>si;
        int i,j,l,m,n;
        n = nums.size();
    
        
       unordered_map<int, vector<pair<int, int>>> mp; 
	    for (i = 0; i < n-1; i++) 
		    for (j = i+1; j < n; j++) 
			    mp[nums[i] + nums[j]].push_back({i,j}); 

	// Traverse through all pairs and search 
	// for X - (current pair sum).	 
	    for (i = 0; i < n-1; i++) 
	    { 
		    for (j = i+1; j < n; j++) 
		    { 
			    int sum = nums[i] + nums[j]; 

			// If X - sum is present in hash table,			 
			    if (mp.find(target - sum) != mp.end()) 
			    { 

				// Making sure that all elements are 
				// distinct array elements and an element 
				// is not considered more than once. 
                    for(auto it:mp[target-sum]){
                        //pair<int, int> p = mp[target - sum]; 
				    if (it.first != i && it.first != j && 
						    it.second != i && it.second != j) 
				    { 
					    vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[it.first]);
                        temp.push_back(nums[it.second]);
                        sort(temp.begin(),temp.end());
                        si.insert(temp);
				    } 
                        
                    }
				    
			     }
                                    
		    } 
	    } 
        vector<vector<int>> fi;
        
        for(auto k:si){
             fi.push_back(k);
        }
        return fi;
        
    }
};
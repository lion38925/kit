// C++ program to find all combinations that 
// sum to a given value 
#include <bits/stdc++.h> 
using namespace std; 

// Print all members of ar[] that have given 
void findNumbers(vector<int>& ar, int sum, 
				vector<vector<int> >& res, 
				vector<int>& r, int i) 
{ 
	// If current sum becomes negative 
	if (sum < 0) 
		return; 								// important this is bactrack solution and it can also be solved using
												// recursion but some solution can only be solved either using backtrack or recursion
												// and specidally for dp problems we use recursion + memo not backtracking

	// if we get exact answer 
	if (sum == 0) 
	{ 
		res.push_back(r); 
		return; 
	} 

	// Recur for all remaining elements that 
	// have value smaller than sum. 
	while (i < ar.size() && sum - ar[i] >= 0) 
	{ 

		// Till every element in the array starting 
		// from i which can contribute to the sum 
		r.push_back(ar[i]); // add them to list 

		// recur for next numbers 
		findNumbers(ar, sum - ar[i], res, r, i); 
		i++; 

		// remove number from list (backtracking) 
		r.pop_back(); 
	} 
} 

// Returns all combinations of ar[] that have given 
// sum. 
vector<vector<int> > combinationSum(vector<int>& ar, 
											int sum) 
{ 
	// sort input array 
	sort(ar.begin(), ar.end()); 

	// remove duplicates 
	ar.erase(unique(ar.begin(), ar.end()), ar.end()); 

	vector<int> r; 
	vector<vector<int> > res; 
	findNumbers(ar, sum, res, r, 0); 

	return res; 
} 

// Driver code 
int main() 
{ 
	vector<int> ar; 
	ar.push_back(2); 
	ar.push_back(4); 
	ar.push_back(6); 
	ar.push_back(8); 
	int n = ar.size(); 

	int sum = 8; // set value of sum 
	vector<vector<int> > res = combinationSum(ar, sum); 

	// If result is empty, then 
	if (res.size() == 0) 
	{ 
		cout << "Emptyn"; 
		return 0; 
	} 

	// Print all combinations stored in res. 
	for (int i = 0; i < res.size(); i++) 
	{ 
		if (res[i].size() > 0) 
		{ 
			cout << " ( "; 
			for (int j = 0; j < res[i].size(); j++) 
				cout << res[i][j] << " "; 
			cout << ")"; 
		} 
	} 
} 



/// another Way recursion
class Solution {
    private:
    vector<vector<int>> ans;
    int n;
    vector<int> v;
    void calc(vector<int> &candidates,int i,int sum,int target)
    {
        if(sum == target)    //If we get target sum then store the answer
        {
            ans.push_back(v);
            return;
        }
        
        if(i==n)          //We have crossed the index of last element
            return;
        
        if(sum > target)             //if our sum exceeds the target sum
            return;
        
        calc(candidates,i+1,sum,target);     //Do not include current element and move forward
        
        v.push_back(candidates[i]);      //Include the current element
        calc(candidates,i,sum+candidates[i],target);  //Recursion
        v.pop_back();         //Backtrack
    }
	
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        calc(candidates,0,0,target);
        
        return ans;
    }
};
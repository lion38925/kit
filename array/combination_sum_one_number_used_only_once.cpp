// C++ program to find all combinations that 
// sum to a given value 

// once number can be used only once
// use set to store as duplicate set can be there
#include <bits/stdc++.h> 
using namespace std; 

// Print all members of ar[] that have given 
void findNumbers(vector<int>& ar, int sum, 
				vector<vector<int> >& res, 
				vector<int>& r, int i) 
{ 
	// If current sum becomes negative 
	if (sum < 0) 
		return; 

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
	
		findNumbers(ar, sum - ar[i], res, r, i+1); 
	
		

		// remove number from list (backtracking) 
		r.pop_back(); 
		i++;
	} 
} 

// Returns all combinations of ar[] that have given 
// sum. 
vector<vector<int> > combinationSum(vector<int>& ar, 
											int sum) 
{ 
	// sort input array 
	sort(ar.begin(), ar.end()); 

	vector<int> r; 
	vector<vector<int> > res; 
	findNumbers(ar, sum, res, r, 0); 

	return res; 
} 

// Driver code 
int main() 
{ 
	vector<int> ar; 
	ar.push_back(10); 
	ar.push_back(1); 
	ar.push_back(2); 
	ar.push_back(7); 
	ar.push_back(6); 
	ar.push_back(1); 
	ar.push_back(5); 
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

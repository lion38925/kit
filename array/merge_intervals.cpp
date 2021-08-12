// C++ program to merge overlapping Intervals in 
// O(n Log n) time and O(1) extra space. 
#include<bits/stdc++.h> 
using namespace std; 

// An Interval 
struct Interval 
{ 
	int s, e; 
}; 

// Function used in sort 
bool mycomp(Interval a, Interval b) 
{ return a.s < b.s; } 

void mergeIntervals(Interval arr[], int n) 
{ 
	// Sort Intervals in increasing order of 
	// start time 
	sort(arr, arr+n, mycomp); 

	int index = 0; // Stores index of last element 
	// in output array (modified arr[]) 

	// Traverse all input Intervals 
	for (int i=1; i<n; i++) 
	{ 
		// If this is not first Interval and overlaps 
		// with the previous one 
		if (arr[index].e >= arr[i].s) 
		{ 
			// Merge previous and current Intervals 
			arr[index].e = max(arr[index].e, arr[i].e); 
			arr[index].s = min(arr[index].s, arr[i].s); 
		} 
		else { 
            index++;
			arr[index] = arr[i]; 
			
		}	 
	} 

	// Now arr[0..index-1] stores the merged Intervals 
	cout << "\n The Merged Intervals are: "; 
	for (int i = 0; i <= index; i++) 
		cout << "[" << arr[i].s << ", " << arr[i].e << "] "; 
} 

// Driver program 
int main() 
{ 
	Interval arr[] = { {6,8}, {1,9}, {2,4}, {4,7} }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	mergeIntervals(arr, n); 
	return 0; 
} 

// merge intervals using vector


bool mycom(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),mycom);
        
        vector<vector<int>> v;
        int a, b;
        if(intervals.size()>0){
            v.push_back(intervals[0]);
        }
        a = 0;
        for(int i=1;i<intervals.size();i++){
            if(v[a][1]>=intervals[i][0]){
                v[a][0]=min(v[a][0],intervals[i][0]);
                v[a][1]=max(v[a][1],intervals[i][1]);
            }
            else{
                v.push_back(intervals[i]);
                a++;
            }
        }
        
        return v;
        
    }
     
};
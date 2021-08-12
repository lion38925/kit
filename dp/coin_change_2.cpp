class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int i,j,k,l,n,count=0;
        
        vector<int>v(amount+1,0);
        n=coins.size();
        //sort(coins.begin(),coins.end());  


        // important this is recursive solution
		// and specidally for dp problems we use recursion + memo not backtracking
        
        if(n==0){
            
            if(amount!=0)
                return 0;
            else
                return 1;
        }
        if(amount==0)
            return 1;
        
        vector<vector<int>> vi(n+1,vector<int>(amount+1,-1));
        int pi = ch(coins,0,0,vi,amount);
        
       return pi;
        
        
    }
    

    int ch(vector<int> coins,int index,int sum,vector<vector<int>>& vi,int amount){
        if(index>=coins.size())
            return 0;
        if(sum==amount)
            return 1;
        if(sum>amount)
            return 0;
        if(vi[index][sum]!=-1)
            return vi[index][sum];

        vi[index][sum] = ch(coins,index,sum+coins[index],vi,amount)+ch(coins,index+1,sum,vi,amount);
        
        
        return vi[index][sum];
    }
    
    
};

// another solution

// C++ program for coin change problem. 
#include<bits/stdc++.h> 

using namespace std; 

int count( int S[], int m, int n ) 
{ 
	int i, j, x, y; 

	// We need n+1 rows as the table 
	// is constructed in bottom up 
	// manner using the base case 0 
	// value case (n = 0) 
	int table[n + 1][m]; 
	
	// Fill the enteries for 0 
	// value case (n = 0) 
	for (i = 0; i < m; i++) 
		table[0][i] = 1; 

	// Fill rest of the table entries 
	// in bottom up manner 
	for (i = 1; i < n + 1; i++) 
	{ 
		for (j = 0; j < m; j++) 
		{ 
			// Count of solutions including S[j] 
			x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 

			// Count of solutions excluding S[j] 
			y = (j >= 1) ? table[i][j - 1] : 0; 

			// total count 
			table[i][j] = x + y; 
		} 
	} 
	return table[n][m - 1]; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {1, 2, 3}; 
	int m = sizeof(arr)/sizeof(arr[0]); 
	int n = 4; 
	cout << count(arr, m, n); 
	return 0; 
} 



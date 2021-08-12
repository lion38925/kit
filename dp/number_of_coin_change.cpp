//Write CPP code here 
int count( int S[], int m, int n ) 
{ 
	//we need a two dimensional matrix to store the result 
	int table[m+1][n+1]; 
	
	// Initialize all table values as 0 
	memset(table, 0, sizeof(table)); 
	
	// Base case (If given value is 0) 
	for(int i=0;i<m;i++) 
{table[i][0] = 1; 
} 
	
	for(int i=1;i<=m;i++) 
	{ 
			
		for(int j=1;j<=n;j++) 
		{ 
			if(S[i-1]>j) 
			{ 
				table[i][j]=table[i-1][j]; 
					
			} 
				
			else
			{ 
				table[i][j]=table[i-1][j]+table[i][j-S[i-1]]; 
			} 
				
		} 
	} 
	return table[m][n]; 
} 


// my solution

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
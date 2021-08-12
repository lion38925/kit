class Solution {
public:

    // in this solution we need to find number of 1 bits in every number till num
    //__builtin_popcount(n) is the builtin function of c++ to find number of ones in any
    // number but instead of that we can use dp
    vector<int> countBits(int num) {
        
        int i,j,k,l,n;
        
        vector<int>dp(num+1,0);

        
        if(num>=1)
            dp[1]=1;
        
        for(i=2;i<=num;i++){
            j = log2(i);        // this finds the highest set bit in any number
            // lets say number is 5 so this will return 2 as 2nd bit is set which is 4 

            
            dp[i] = 1+dp[i-pow(2,j)];  // now we need to return 1 which is the set bit as we got from j and now
            // we need to check how many bits are set for 5-pow(2,2); which is 5-4 = 1 
        }
        
        return dp;
        
        
    }
};
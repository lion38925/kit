class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        
        int i,j,k,l,m,n;
        
        n = cost.size();
        vector<int> dp(n+2,0);
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        dp[2]=cost[2]+cost[0];

        // this logic is based on that we can only come to step from either one less position
        // or two less position so we need to take minimum of both of them and add the cost of the
        // position where we want to reach as well
        
        for(i=2;i<n+2;i++){
            if(i<n)
                dp[i]=cost[i];
            else
                dp[i]=0;

            dp[i]+=min(dp[i-2],dp[i-1]);
        }
        
        return dp[n];
    }
};
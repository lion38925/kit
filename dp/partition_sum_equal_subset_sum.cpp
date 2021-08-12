class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int i,j,k,l,sum=0,index=0,n,ans=0;
        n = nums.size();
                
        for(i=0;i<n;i++)
            sum+=nums[i];
        
        if(sum%2!=0)
            return false;
        sum=sum/2;
        
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        
        for(i=0;i<=n;i++){
            
            for(j=0;j<=sum;j++){
                
                if(i==0&&j==0)
                    dp[i][j]=true;
                else
                    if(i==0)
                        dp[i][j]=false;
                else
                    if(j==0)
                        dp[i][j]=true;
                else
                    if(nums[i-1]>j)             // this condition means that sum can be formed without including the element
                        dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];      // this condition tells that if we consider this element can we form the sum
                
                
            }
        }
        
        // for(i=0;i<=n;i++){
        //     for(j=0;j<=sum;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[n][sum];
            
    }
    
};
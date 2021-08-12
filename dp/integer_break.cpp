typedef long long ll;
class Solution {
    // this solution is for interger break, in which we need to break one integer into numbers whose sum is equal to number
    // and product of the number is max
    // this solution is using dp, but we have another solution which is more fast and uses math

public:
    int integerBreak(int n) {
        
        
        int i,j,k,l,m;
        vector<ll> dp(60,1);
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        
        for(i=4;i<=n;i++){
            dp[i]=1;
            
            for(j=1;j<i;j++){
                dp[i]=max(dp[i],j*dp[i-j]);
            }
            
        }
        
        
        dp[2]=1;
        dp[3]=2;
        
        return dp[n];
        
        
    }
};

// solution using math // important

class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int ans;
        if(n%3==0){
            ans = pow(3,n/3);
        }
        else if(n%3==1){
            ans = 4 * pow(3,(n/3)-1);
        }
        else{
            ans = 2* pow(3,n/3);
        }
        return ans;
    }
};
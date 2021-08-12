class Solution {
public:
    int numSquares(int n) {
        
        int i,j,k,l,m,index=1,count=0;


        // what are we doing in this 
        // we can go from 1 to sqrt(n) and one by one deduct the square and check for the rest
        vector<int>dp(n+1,-1);
        dp[0]=0;
        if(n>=1)
            dp[1]=1;
        if(n>=2)
            dp[2]=2;
        if(n>=3)
            dp[3]=3;
        
        for(i=4;i<=n;i++){
            
            dp[i]=i;                // INITIAL  we take dp[i]=i as if i is 12 it can be made from all 1 squares that's why 12
            for(k=1;k<=sqrt(i);k++){
                int temp = k*k;
                if(temp>i)
                    break;
                dp[i]=min(dp[i],1+dp[i-temp]);
                
            }
        }
        
        return dp[n];
    }
    

};


// recursive soltion which will give tle

class Solution {
public:
    int numSquares(int n) {
        
        int i,j,k,l,m,index=1,count=0,ans=INT_MAX;
        
        m = sqrt(n);
        
        ns(n,m,index,count,ans);
        
        cout<<ans;
        return ans;
        
    }
    
    void ns(int n, int m,int index, int count,int& ans){
        
        if(n==0){
            if(ans>count)
                ans = count;
            return;
        }
        if(index>m||n<0)
            return ;
        
        ns((n-(index*index)),m,index,count+1,ans);
        ns(n,m,index+1,count,ans);
        return ;
        
            
    }
};
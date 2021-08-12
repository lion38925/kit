class Solution {
public:


// in this question there are two string s and t we need to check whether 
// string s is completely subsequence of t or not
// this solution is a dp solution below this 
// there is 2 pointer solution
    bool isSubsequence(string s, string t) {
        int i,j,m,n;
        m = s.length();
        n= t.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        if(m==0)
            return true;
        
        for(i=0;i<m+1;i++){
            
            for(j=0;j<n+1;j++){
                
                if(i==0||j==0)
                    dp[i][j]=0;
                else
                    if(s[i-1]==t[j-1])
                        dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        if(dp[m][n]==m)
            return true;
        else
            return false;
    }
};



/// two pointer solution 

let isSubsequence = function(s, t) {
    if (s.length === 0) {
        return true;
    }
    
    let pointer1 = 0;
    let pointer2 = 0;
    
    while (pointer1 < s.length && pointer2 < t.length) {
        if (t.charAt(pointer2) === s.charAt(pointer1)) {
            pointer1++;
        }
        pointer2++;
    }
  
    return pointer1 === s.length;
};
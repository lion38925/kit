class Solution {
public:
/// to find number of unique digits number we use permutations
// and add them together to get the result
    int countNumbersWithUniqueDigits(int n) {
        int dp[9];
        dp[0]=1; dp[1]=10;
        int pro = 9, end=9;
        for(int i=2; i<=n; i++){
            dp[i] = (9*pro)+dp[i-1];
            end--;
            pro*=end;
        }
        return dp[n];
    }
};
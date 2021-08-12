class Solution {
public:
    bool divisorGame(int N) {

        return (N % 2 == 0);
    }
};

// this can also be done using dp


class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N+1];
        memset(dp,false,sizeof(dp));
        for(int i=2;i<=N;i++)
        {
            bool temp = false;
            for(int j=1;j<=i/2;j++)
            {
                if(i%j==0)
                {
                    dp[i] = dp[i] || dp[i-j];
                }
            }
            dp[i] = temp;
        }
        return dp[N];
    }
};

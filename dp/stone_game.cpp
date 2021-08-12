class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int i,j,k,l,m,n;
        
        n = piles.size();
        
        vector<vector<bool>>v(n+1,vector<bool>(n+1,false));
        
        
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                if(i==0||j==0)
                    v[i][j]=true;
                else
                    if(i>j)
                        continue;
                else
                    if(i==j||i+1==j)
                        v[i][j]=true;
                else
                    v[i][j] = v[i-1][j]||v[i][j-1];
                
            }
        }
        
        return v[n][n];
        
    }
};

// best solution be to return true for all cases

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
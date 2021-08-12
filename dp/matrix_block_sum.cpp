class Solution {
public:
    
    pair<int,int> getstart(int i, int j, int m, int n, int k){
        return {max(1,i-k),max(1,j-k)};
    }
    
    pair<int,int> getend(int i, int j, int m, int n, int k){
        return {min(m,i+k),min(n,j+k)};
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        
        int i,j,k,l,m,n;
        
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>>v(m+1,vector<int>(n+1,0)),res(m,vector<int>(n,0));
        
        // what are we doing here is that we are creating a prefix sum array
        // to understand this logic it is necessary to draw a matix then try
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                v[i][j] = v[i-1][j]+v[i][j-1]-v[i-1][j-1]+mat[i-1][j-1];    // we are subtracting i-1 and j-1 as we are taking it twice earlier
            }
        }
        
        // now we run a loop and get the start and the end coordinates for each case
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                auto [startx,starty] = getstart(i,j,m,n,K);
                auto [endx,endy] = getend(i,j,m,n,K);
                // now to find the sum till that point we use this logic 
                res[i-1][j-1] = v[endx][endy] - v[endx][starty-1] - v[startx-1][endy]+v[startx-1][starty-1];
            }
        }
       
        return res;
        
    }
};

	


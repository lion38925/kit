class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        
        int i,j,total=0,m,n;
        
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<int>>v(m,vector<int>(n,0));
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(i==0||j==0)
                    v[i][j]=matrix[i][j];
                else
                    if(matrix[i][j]==1){
                        v[i][j]=min(v[i-1][j],min(v[i][j-1],v[i-1][j-1]))+1;
                    }
                        
            }
        }
        
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){

                total+=v[i][j];
            }
        }
        
        return total;
    }
};
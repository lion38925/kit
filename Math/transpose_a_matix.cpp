class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int i,j,temp;
        vector<vector<int>> v(A[0].size(),vector<int>(A.size(),0));
        for(i=0;i<A.size();i++){
            for(j=0;j<A[0].size();j++){
                v[j][i]=A[i][j];
                
            }
        }
        return v;
    }
};
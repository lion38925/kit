class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        
        int i,j,k,n,ma=0;
        n = A.size();
        
        vector<vector<int>> v(n,vector<int>(1001,0));
        
        for(i=0;i<n;i++){
            
            for(j=i-1;j>=0;j--){
                k = A[i]-A[j];
                
                v[i][k+500] = max(v[i][k+500],v[j][k+500]+1);
                
                ma = max(ma,v[i][k+500]);
            }
        }
        
        return ma+1;
        
    }
};
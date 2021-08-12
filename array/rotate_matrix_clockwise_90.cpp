class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int i,j,k,l,m,n,temp;
        n = matrix.size();
        k=0;
        for(i=0;i<n;i++){
            
            for(j=i;j<n;j++){
                temp = matrix[i][j];
                matrix[i][j]= matrix[j][i];
                matrix[j][i]=temp;
            }
            
        }
        
        for(i=0;i<n;i++){
            
            k=n-1;
            j=0;
            while(j<k){
                temp = matrix[i][j];
                matrix[i][j]=matrix[i][k];
                matrix[i][k]=temp;
                j++;
                k--;
            }
        }
        
        
    }
};
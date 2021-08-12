class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int i,j,k,l,m,n;
        
        m = s1.length();
        n = s2.length();
        
        vector<vector<int>> v(m+1,vector<int>(n+1,0));

        // the 2-d table consists of formula where we take ascii value for first element and add it to subsequent value for 
        // for first row and first column which means for string s1 and s2
        
        for(i=1;i<=m;i++){
            k = s1[i-1];
            v[i][0]=v[i-1][0]+k;        
        }
        for(i=1;i<=n;i++){
            k = s2[i-1];
            v[0][i]=v[0][i-1]+k;
        }
        // if the current position elements are same then we copy from diagonaly
        // if not then we take minimum of the above and side element of 2-d array adding the ascii vlaues of the current values

        // try to make 2d array in table and ms try to formulate the formula
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    v[i][j]=v[i-1][j-1];
                }else{
                    v[i][j] = min(v[i-1][j]+(int)s1[i-1],v[i][j-1]+(int)s2[j-1]);
                }
            }
        }
        
        return v[m][n];
        
    }
};

//

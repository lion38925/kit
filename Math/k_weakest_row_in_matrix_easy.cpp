 // this is compare function made to check and return accordingly
 bool mycomp(vector<int>& a, vector<int>& b){
        if(a[1]!=b[1])
            return a[1]<b[1];
        else
            return a[0]<b[0];
        }

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<vector<int>> v;
        vector<int>l;
        
        int i,j,m,n,c;
        m = mat.size();
        n = mat[0].size();
        
        for(i=0;i<m;i++){
            c=0;
            for(j=0;j<n;j++){
                if(mat[i][j]==1)
                    c++;

            }
            v.push_back({i,c});
        }
        
        
        
        sort(v.begin(),v.end(),mycomp);     // this is compare function made
        
        
        for(i=0;i<k;i++)
            l.push_back(v[i][0]);
        
        return l;
    }
    
    
   
};
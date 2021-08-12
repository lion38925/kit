class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        
        int i,j,k,l,n,m;
        m=M.size();
        if(m==0){
            vector<vector<int>>vi;
            return vi;
        }
        
        n = M[0].size();
        if(m==1&&n==1){
            vector<vector<int>>vi;
            vi.push_back(M[0]);
            return vi;
            
        }
        vector<vector<int>> v(m,vector<int>(n,0));
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                gl(M,i,j,v,m,n);
            }
        }

        return v;
    }
     void gl(vector<vector<int>>& board,int i, int j, vector<vector<int>>& v,int m, int n){
        
        int a[] = {-1,-1,-1,0,1,1,1,0};
        int b[] = {-1,0,1,1,1,0,-1,-1};
        int l=0,ki=0;
         l+=board[i][j];
        
        for(int k = 0;k<8;k++){
            
            int dx = i+a[k];
            int dy = j+b[k];
            
            if(dx>=0&&dx<m&&dy>=0&&dy<n){
                l+=board[dx][dy];
                ki++;
                
            }
        }
         if(ki==0)
             v[i][j]=0;
         else
            v[i][j]=floor(l/(ki+1));
    }
};
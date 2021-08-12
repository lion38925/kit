class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int i,j,k,l,n,m;
        m=board.size();
        if(m==0)
            return;
        n = board[0].size();
        vector<vector<int>> v(m,vector<int>(n,0));
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                gl(board,i,j,v,m,n);
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                board[i][j]=v[i][j];
            }
        }
        
        
    }
    
    void gl(vector<vector<int>>& board,int i, int j, vector<vector<int>>& v,int m, int n){
        
        int a[] = {-1,-1,-1,0,1,1,1,0};
        int b[] = {-1,0,1,1,1,0,-1,-1};
        int l=0;
        
        for(int k = 0;k<8;k++){
            
            int dx = i+a[k];
            int dy = j+b[k];
            
            if(dx>=0&&dx<m&&dy>=0&&dy<n){
                if(board[dx][dy]==1)
                    l++;
            }
        }
        if(board[i][j]==1){

            if(l==2||l==3)
                v[i][j]=1;
 
        }
        else
            if(board[i][j]==0){
                if(l==3)
                    v[i][j]=1;
            }
    }
};
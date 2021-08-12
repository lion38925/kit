class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        
        int i,j,m,n;
        
        if(board.size()>0)
            m = board.size();
        else
            return;
        

        n = board[0].size();
        

        
        for(i=0;i<n;i++){
            
            if(board[0][i]=='O'){
                cb(board,0,i,m,n);
            }
        }
        
        for(i=0;i<m;i++){
            
            if(board[i][0]=='O'){
                cb(board,i,0,m,n);
            }
        }
        for(i=0;i<n;i++){
            
            if(board[m-1][i]=='O'){
                cb(board,m-1,i,m,n);
            }
        }
        for(i=0;i<m;i++){
            
            if(board[i][n-1]=='O'){
                cb(board,i,n-1,m,n);
            }
        }
        
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(board[i][j]=='i')
                    board[i][j]='O';
            }
        }
    }
    
    void cb(vector<vector<char>>& board,int i,int j,int m,int n){
                
        queue<pair<int,int>>q;
        
        // int dx[] = {1,0,1,-1,0,-1,-1,1};
        // int dy[] = {0,1,1,-1,-1,0,1,-1};
        
        int dx[] = {1,0,0,-1};
        int dy[] = {0,1,-1,0};
        
        int a,b,k,f,s;
        
        q.push({i,j});
        
        board[i][j] = 'i';
        while(!q.empty()){
            
            pair<int,int>p;
            p  = q.front();
            q.pop();
            f=p.first;
            s=p.second;
            
            for(k=0;k<4;k++){
                a = f+dx[k];
                b = s+dy[k];
                
                if(a>=0&&a<m&&b>=0&&b<n){
                    if(board[a][b]=='O'){
                        board[a][b]='i';
                        q.push({a,b});
                    }
                }
            }
            
            
        }
        
        
    }
};
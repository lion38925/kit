class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        int i,j,k,l,m,n,a,b,count,mine,res;
        
        m = board.size();
        n = board[0].size();
        
        i = click[0];           // getting  size of row and column
        j = click[1];
        
        if(board[i][j]=='M'){
            board[i][j]='X';
            return board;
        }

        queue<pair<int,int>>q;
        q.push({i,j});
        
        int dx[] = {1,0,0,-1,-1,1,-1,1};
        int dy[] = {0,1,-1,0,-1,1,1,-1};
        vector<pair<int,int>>vi;

        while(!q.empty()){
            
            pair<int,int>p;
            p = q.front();
            q.pop();
            
            a = p.first;
            b = p.second;
            count = 0;
            mine=0;
            res = 0;
            if(board[a][b]=='E'){       // only proceed if there is Empty cell and not visited till now
                
            for(k=0;k<8;k++){
                i = a +dx[k];
                j = b + dy[k];
                
                if(i>=0&&i<m&&j>=0&&j<n){
                    if(board[i][j]=='M')
                        mine++;
                    else
                        if(board[i][j]=='E'){
                            vi.push_back({i,j});        // if its is E pushing it into E
                            //q.push({i,j});
                            res++;
                        }
                    else
                        res++;
                }
            }
            
            if(mine>0){
                string z = to_string(mine);     // if there are mines then we donot need to add the neighbours in the the queue
                board[a][b]=z[0];           
                vi.clear();
            }
            else{
                board[a][b] = 'B';
                for(auto itr:vi){       // if there are no mines then we need to add all its neighbours into the queue and proceed further
                    q.push(itr);
                }
                vi.clear();
             }
            }
            
            
        }
        
        return board;
        
    }
};
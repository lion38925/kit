class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int i,j,k,l,m,n,c,flag=0,total=0,a,b;
        
        m = grid.size();
        n = grid[0].size();
        
        queue<pair<int,int>>q;
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    
                }
            }
        }
        
        int dx[] = {0,1,-1,0};
        int dy[] = {1,0,0,-1};
        
        while(!q.empty()){
            
            
            c = q.size();
            
            flag=0;
 
            while(c--){
                
                pair<int,int>p;
            
                p = q.front();
                q.pop();
            
                i= p.first;
                j = p.second;
            
                for(k=0;k<4;k++){
                        
                        a = i+dx[k];
                        b = j+dy[k];
                        
                        if(a>=0&&a<m&&b>=0&&b<n){
                            if(grid[a][b]==1){
                                flag=1;
                                q.push({a,b});
                                grid[a][b]=2;
                            }
                        }
                    }
                
            
            }
            
            if(flag==1)
                total++;
            
        }
        
         for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                    
                }
            }
        }
        
        return total;
        
    }
};
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
      
        int i,j,k,l,m,n,f,ma,a,b,c,d;
        
        m = grid.size();
        n = grid[0].size();
        
        if(m==1&&n==1)
            return true;
        
        queue<pair<int,int>>q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<int>v;
        q.push({0,0});
        
        vis[0][0]=1;
        
        while(!q.empty()){
            
            pair<int,int> p;
            p = q.front();
            q.pop();
            v = gv(grid,p,m,n); // get the next posible indexex according to the current block
            a = v[0];
            b = v[1];
            c = v[2];
            d = v[3];
            
            vis[p.first][p.second]=1;
                        
            if(a>=0&&a<m&&b>=0&&b<n){

                if(vis[a][b]==0){
                    
                bool kit = gnext(grid,p,a,b);   // this function is when we are going positive index or forward
                    
                    if(kit){
                        q.push({a,b});
                        if(a==m-1&&b==n-1)
                            return true;

                    }
                    
                }
            }
            if(c>=0&&c<m&&d>=0&&d<n){

                if(vis[c][d]==0){
                    
                    bool kit = gnextne(grid,p,c,d); // when going to negative or back
                    
                    if(kit){
                        q.push({c,d});
                        if(c==m-1&&d==n-1)
                            return true;
                    }
                }
            }
   

            
        }
        
    return false;
        
    }
    
    bool gnext(vector<vector<int>>& grid,pair<int,int>p, int a,int b){
        
        int k;
        k = grid[p.first][p.second];
        
        switch(k){
            case 1:
                if(grid[a][b]==3||grid[a][b]==5||grid[a][b]==1)
                    return true;
                else
                    return false;
            case 2:
                if(grid[a][b]==6||grid[a][b]==5||grid[a][b]==2)
                    return true;
                else
                    return false;
            case 3:
                if(grid[a][b]==5||grid[a][b]==6||grid[a][b]==2)
                    return true;
                else
                    return false;
            case 4:
                if(grid[a][b]==3||grid[a][b]==1||grid[a][b]==5)
                    return true;
                else
                    return false;
            case 5:
                if(grid[a][b]==3||grid[a][b]==2||grid[a][b]==4)
                    return true;
                else
                    return false;
            case 6:
                if(grid[a][b]==1||grid[a][b]==5||grid[a][b]==3)
                    return true;
                else
                    return false;
            default:
                return true;
        }
        
        
        return true;
        
    }
    bool gnextne(vector<vector<int>>& grid,pair<int,int>p, int a,int b){
        
        int k;
        k = grid[p.first][p.second];
        
        switch(k){
            case 1:
                if(grid[a][b]==4||grid[a][b]==6||grid[a][b]==1)
                    return true;
                else
                    return false;
            case 2:
                if(grid[a][b]==3||grid[a][b]==4||grid[a][b]==2)
                    return true;
                else
                    return false;
            case 3:
                if(grid[a][b]==4||grid[a][b]==6||grid[a][b]==1)
                    return true;
                else
                    return false;
            case 4:
                if(grid[a][b]==6||grid[a][b]==2||grid[a][b]==5)
                    return true;
                else
                    return false;
            case 5:
                if(grid[a][b]==1||grid[a][b]==6||grid[a][b]==4)
                    return true;
                else
                    return false;
            case 6:
                if(grid[a][b]==4||grid[a][b]==2||grid[a][b]==3)
                    return true;
                else
                    return false;
            default:
                return true;
        }
        
        
        return true;
        
    }
    vector<int> gv(vector<vector<int>>& grid,pair<int,int>p, int m,int n){
        
        int i,j,k;
        k = grid[p.first][p.second];
        vector<int>v;
        
        switch(k){
            case 1:
                v.push_back(p.first);
                v.push_back(p.second+1);
                v.push_back(p.first);
                v.push_back(p.second-1);
                return v;

            case 2:
                v.push_back(p.first+1);
                v.push_back(p.second);
                v.push_back(p.first-1);
                v.push_back(p.second);
                return v;
            case 3:
                v.push_back(p.first+1);
                v.push_back(p.second);
                v.push_back(p.first);
                v.push_back(p.second-1);
                return v;
            case 4:
                v.push_back(p.first);
                v.push_back(p.second+1);
                v.push_back(p.first+1);
                v.push_back(p.second);
                return v;
            case 5:
                v.push_back(p.first-1);
                v.push_back(p.second);
                v.push_back(p.first);
                v.push_back(p.second-1);
                return v;
            case 6:
                v.push_back(p.first);
                v.push_back(p.second+1);
                v.push_back(p.first-1);
                v.push_back(p.second);
                return v;
                
        }
        return v;
        
    }
};
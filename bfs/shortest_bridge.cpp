class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int i,j,k,l,m,n,a,b,c,flag=0;
        
        m = A.size();
        n= A[0].size();
        
        int dx[] = {1,0,0,-1};
        int dy[] = {0,1,-1,0};
        
        queue<pair<int,pair<int,int>>> q;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(A[i][j]==1){
                    q.push({i,{j,0}});
                    dfs(A,i,j,m,n,q);
                    A[i][j]=-1;
                    flag=1;
                    break;
                    
                }
            }
            if(flag)
                break;
        }
        
        while(!q.empty()){
            
            pair<int,pair<int,int>>p;
            p = q.front();
            q.pop();
            i= p.first;
            j = p.second.first;
            c = p.second.second;
            
            for(k=0;k<4;k++){
                a = i+dx[k];
                b = j + dy[k];
               if(a>=0&&a<m&&b>=0&&b<n){ 
                    if(A[a][b]==1){
                        return c;    
                    }
                    else
                        if(A[a][b]==0){
                            A[a][b]=-1;
                            q.push({a,{b,c+1}});
                        }
                
                    }
            
                }
            
            
        }
        
        
        return 1;
        
    }
    
    void dfs(vector<vector<int>>& A,int i, int j,int m,int n,queue<pair<int,pair<int,int>>>& q){
        
        int dx[] = {1,0,0,-1};
        int dy[] = {0,1,-1,0};
        
        int a,b,k,c;
        
        for(k=0;k<4;k++){
            a = i+dx[k];
            b = j + dy[k];
            
            if(a>=0&&a<m&&b>=0&&b<n){
                if(A[a][b]==1){
                    A[a][b]=-1;
                    q.push({a,{b,0}});
                    dfs(A,a,b,m,n,q);
                }
            }
        }
    }
};
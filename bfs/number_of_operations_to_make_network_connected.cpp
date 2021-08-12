class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        
        int i,j,k,l,m,count=0,res=0,grp=0;
        
        
        vector<int> v(n,0);
        
        vector<int> grap[n];
        
        queue<pair<int,int>>q;
        
        for(i=0;i<connections.size();i++){
            grap[connections[i][0]].push_back(connections[i][1]);
            grap[connections[i][1]].push_back(connections[i][0]);
        }
        
        
        for(l=0;l<n;l++){
            
            if(v[l]==1||grap[l].size()==0)
                continue;
            else{
                q.push({-1,l});
                grp++;
            }
        
        while(!q.empty()){
            
            pair<int,int>p;
            p = q.front();
            q.pop();
            
            i = p.first;
            j = p.second;
            if(v[j]==0){
                
                v[j]=1;
                
                for(k = 0;k<grap[j].size();k++){
                    if(grap[j][k]!=i&&v[grap[j][k]]==1)
                        count++;
                    else
                        if(grap[j][k]!=i)
                            q.push({j,grap[j][k]});
                }
                
                
            }
            
            
            
        }
        
        }
        
        for(auto itr:v){
            if(itr==0)
                res++;
        }
        
        if(count<res)
            return -1;
        if(res==0)
            return grp-1;
        else
            return res+grp-1;
  
        
    }
};
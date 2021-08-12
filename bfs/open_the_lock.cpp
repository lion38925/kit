class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        int i,j,k,l,m,n,flag=0,mi=INT_MAX,count;
        
        string initial = "0000";
        
        unordered_set<string> deade;
        
        unordered_set<string> vis;
        
        queue<pair<string,int>> q;
        
        for(auto itr:deadends)
            deade.insert(itr);
        
        
        q.push({initial,0});
        while(!q.empty()){
            
            pair<string,int>ki;
            ki = q.front();
            string temp = ki.first;
            string temp2 = temp;
            count = ki.second;
            q.pop();

            if(target==temp){
                cout<<temp<<"#"<<count<<"\n";
                mi = min(count,mi);
                return mi;
            }
            
            if(vis.find(temp)==vis.end()&&deade.find(temp)==deade.end()){
                vis.insert(temp);
                
                for(i=0;i<4;i++){
                    l = temp[i]-'0';
                    l++;
                    if(l>9)
                        l=0;
                    temp[i]=l+'0';
                    
                    if(vis.find(temp)==vis.end()){
                        q.push({temp,count+1});
                    }
                    temp = temp2;
                    
                    l = temp[i]-'0';
                    l--;
                    if(l<0)
                        l=9;
                    temp[i]=l+'0';
                    
                    if(vis.find(temp)==vis.end()){
                        q.push({temp,count+1});
                    }
                    
                    temp = temp2;
                
                }

            }
        }
        
        return mi==INT_MAX?-1:mi;
        
    }
};
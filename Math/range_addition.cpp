class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        
        int kit;
        kit=m*n;
        if(ops.size()==0)
            return kit;
  
        for(auto itr:ops){
            m= min(m,itr[0]);
            n = min(n,itr[1]);
            
        }
        
        return m*n;
        
        
        
        
        
       
        
    }
};
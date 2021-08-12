class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        vector<vector<int>>v;
        
        int i,j,k,l,m,n;
        
        vector<int> mp[501];
        
        for(i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }

        for(i=1;i<501;i++){
            
            vector<int>p;
            for(j=0;j<mp[i].size();j+=i){
                k=0;
                while(k<i){
                    p.push_back(mp[i][j+k]);
                    k++;
                }
                v.push_back(p);
                p.clear();
                
            }
        }
        return v;
        
        
    }
};
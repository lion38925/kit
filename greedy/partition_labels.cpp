class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        
        int i,j,k=0,l,m,n,t=0,start;
        
        unordered_map<char,int>mp;
        vector<int>v;
        
        for(i=0;i<S.length();i++){
            mp[S[i]] = i;
        }
        
        for(i=0;i<S.length();i++){
            
            k = max(0,mp[S[i]]);
            start = i;
            while(i<k){
                k = max(k,mp[S[i]]);
                i++;
            }
            v.push_back(k-start+1);
            
        }
        
        return v;
    }
};
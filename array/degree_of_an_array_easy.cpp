class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        int i,j,k,l,n,dif=INT_MAX;
        n = nums.size();
        
        unordered_map<int,pair<int,pair<int,int>>>mp;
        
        for(i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                pair<int,pair<int,int>> pi;
                pi = mp[nums[i]];                   // this code also tells how pair inside pair and inside map works
                k = pi.first;
                k++;
                l = pi.second.first;
                mp[nums[i]]={k,{l,i}};
                
            }
            else
                mp[nums[i]]={1,{i,i}};
        }
        j=0;
        for(auto itr:mp){
            if(itr.second.first>j)
                j=itr.second.first;
        }
        
        for(auto it:mp){
            if(it.second.first==j){
                int f,s;
                f = it.second.second.first;
                s = it.second.second.second;
                if(dif>s-f)
                    dif=s-f;
            }
        }
        return dif+1;
    }
};
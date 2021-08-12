class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>res;        
        mp(res,nums,0,nums.size()-1);
        vector<vector<int>> fi;
        
        for(auto itr: res)
            fi.push_back(itr);
        return fi;
        
    }
    
    void mp(set<vector<int>>& res,vector<int> nums,int l, int r){
        if(l>r)
            return;
        if(l==r){
            res.insert(nums);
        }
        else
            for(int i=l;i<=r;i++){
                 swap(nums[i],nums[l]);
                 mp(res,nums,l+1,r);
                 swap(nums[i],nums[l]);
                
            }
        return ;
    }
};
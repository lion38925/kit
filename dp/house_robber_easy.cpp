// this solution is made up of recurring + memo
// alone revursive solution will give tle so use this
// for this time complex is O(N) and space is O(N)

class Solution {
public:
    int rob(vector<int>& nums) {
        int index =0,i,j,k,ans= 0 ;
        vector<int> v(nums.size(),-1);
        
        i = rb(nums,index,ans,v);
        return ans;
        
    }
    
    int rb(vector<int> nums, int index,int& ans,vector<int>& v){
        if(index>=nums.size())
            return 0;
        
        int ki;
        if(v[index]!=-1)
            ki = v[index];
        else{
            ki = max(nums[index]+rb(nums,index+2,ans,v),rb(nums,index+1,ans,v));
            v[index]=ki;
        }
        
        
        
        ans = max(ans,ki);
        return ki;
    }
};


/// this solution is using bottom up tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp[nums.size()];
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i=2; i<nums.size(); i++)
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        return dp[nums.size()-1];
    }
};
class Solution {
public:
    bool dfs(int start, vector<int> &nums, vector<bool> &visit, int k, long long sum, long long target){
        if(k==1)
            return true;
        if(sum>target)
            return false;
        if(sum==target)
            return dfs(0,nums,visit,k-1,0,target);
        for(int i=start;i<nums.size();i++){
            if(visit[i]==false){
                visit[i]=true;
                if(dfs(i+1,nums,visit,k,sum+nums[i],target))
                    return true;
                visit[i]=false;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return false;
        long long sum = 0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%4!=0)
            return false;
        vector<bool> visit(n+1,false);
        return dfs(0,nums,visit,4,0,sum/4);
    }
};
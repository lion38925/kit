class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i,first=-1,second=-1,r;
        r=INT_MIN;
        
        for(i=0;i<nums.size();i++){
            if(nums[i]==0){
                r = max(r,i-second);
                second = first;
                first = i;
            }
        }
        r= max(r,nums.size()-second);
        return r-2;
        
    }
    int max(int a, int b){
        if(a>b)
            return a;
        return b;
    }
};
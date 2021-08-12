class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i,j,k,l,n;
        n=nums.size();
        if(n==0||n==1)
            return 0;

        
        for(i=0;i<n;i++){
            if(i==0){
                if(i+1<n&&nums[i+1]<nums[i])
                    return 0;
            }else
                if(i==n-1&&nums[i-1]<nums[i])
                    return i;
            else
                if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
                    return i;
        }
        return n;
    }
};
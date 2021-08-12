class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int i,j,k,l,ma,n,f=0;
        n = nums.size();
        
        ma = nums[0];
        for(i=1;i<n;i++){
            
            if(nums[i]>ma){
                ma= nums[i];
                f=i;
            }
        }
        for(i=0;i<n;i++){
            if(nums[i]!=ma&&ma<2*nums[i])
                return -1;
        }
        return f;
        
        
    }
};
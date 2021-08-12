class Solution {
public:

// similar to missing number abs property
    vector<int> findErrorNums(vector<int>& nums) {
        
        int i,d,m,j;
        
        for(i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1]*=-1;
            else{
                d = abs(nums[i]);
            }
        }
        
        for(i=0;i<nums.size();i++){
            if(nums[i]>0){
                m = i;
                break;
            }
        }
        
        return {d,m+1};
        
    }
};
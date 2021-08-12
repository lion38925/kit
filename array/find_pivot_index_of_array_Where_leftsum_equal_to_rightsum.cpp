class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i,j,k,l=0,s=0,n;
        n = nums.size();
        if(n==0)
            return -1;
        if(n==1)
            return -1;
  
        for(i=0;i<n;i++){
            s+=nums[i];
        }
        
        for(i=0;i<n;i++){
            if(l==s-l-nums[i])
                return i;
            l+=nums[i];
 
        }
        return -1;
        
    }
};
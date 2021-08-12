
int maxSubArray(vector<int>& nums) {
        
        int maxs, maxe = 0, i;
        maxs = nums[i];
        
        for(i =0;i<nums.size();i++){
            maxe+=nums[i];
            
            if(maxe>maxs)
                maxs = maxe;
            
            if(maxe<0)
                maxe = 0;
            
            
        }
        
        return maxs;
    }
}

/*Driver program to test maxSubArraySum*/

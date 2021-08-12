class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i,n,kit,x=0;
        n=nums.size();
        
        for(i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                kit = i;
                x++;
            }
                
        }// counting total number where i>i+1
        if(x>1)
            return false;
        else{
                if(kit == 0||kit==n-1)
                    return true;
                else
                    if(gt(nums,kit,0)||gt(nums,kit+1,1))        // checking for both scenario when we can replace ith element or i+1 element
                        return true;
                else
                    return false;

        }
        return true;
        
    }
    
    bool gt(vector<int> nums,int i,int flag){

        if(flag==0){
            nums[i] = nums[i+1];
        }
        
        if(flag==1){
            nums[i] = nums[i-1];
        }
        
        int j=0,t;
        
        t = nums.size()-1;
        if(i-1>=0)
            j= i-1;
        
        if(i+1<nums.size())
            t = i+1;
        
        for(;j<t;j++){
            if(nums[j]>nums[j+1]){
                return false;
            }
                
        }
        
        
        return true;
        
    }
};
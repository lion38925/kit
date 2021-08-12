class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int i,j,k=0,l,m,n;
        n= nums.size();
        sort(nums.begin(),nums.end());
        if(n<3)
            return 0;
            
        
        k = max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);
        return k;
        
    }
};
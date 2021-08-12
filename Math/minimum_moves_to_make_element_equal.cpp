class Solution {
public:
    
    int minMoves(vector& nums) {
    
    if(nums.size()==1)
        return 0;
    
    int res=0;
    int min= *min_element(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
    {
        res+=nums[i]-min;   
    }
    
    return res;
    }

};

// we are given with an array and need to make whole array element same, we can increment n-1 elements at once by 1


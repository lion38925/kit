class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i,l;
        l=-1;
        
        for(i=0;i<nums.size();i++){
            if(nums[i]==1){
                //cout<<i;
                if(l==-1){
                    l=i;
                }else{
                    if(i-l-1<k)
                        return false;
                    l=i;
                }
            }
        }
        return true;
    }
};
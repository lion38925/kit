class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int i,j,l;
        double av;
        
        for(i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        i=0;
        av=nums[k-1]*1.0/k;                 // multiplying with 1.0 because we need to convert int to double
        //cout<<av<<nums[k-1];
        l = k;
        while(l<nums.size()){
            if((nums[l]-nums[i])*1.0/k>av){
                av = (nums[l]-nums[i])*1.0/k;
            }
            l++;
            i++;
        }
        return av;
    }
};
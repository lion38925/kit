//Given an array of integers and an integer k,
// you need to find the total number of continuous
// subarrays whose sum equals to k.
#include<unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> m;
        int count=0;
        int sum=0;
        
        m[sum]=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(m.find(sum-k)!=m.end()){
                count=m[sum-k]+count;
            }
            
            if(m.find(sum)!=m.end()){
                m[sum]++;
            }else{
                m[sum]=1;
            }
            
        }
        
        return count;
    }
};
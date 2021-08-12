class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int i ,k,l,m,c= 0;
        
         int count1  = 0,index1= -1,count2=0,index2=-1;
        vector<int> v;
        
        for(int i =0;i<nums.size();i++){
            
            if(index1!=-1&&nums[i]==nums[index1]){
                    count1++;
                
            }else
                if(index2!=-1&&nums[i]==nums[index2]){
                    count2++;
                }
            else
                if(count1==0){
                    index1=i;
                    count1++;
                }
            else
                if(count2==0){
                    index2=i;
                    count2++;
                    
                }
            else{
                count1--;
                count2--;
            }

        }
        count1=0;
        count2=0;
        for(i =0;i<nums.size();i++){
            if(index1!=-1&&nums[i]==nums[index1])
                count1++;
            else
                if(index2!=-1&&nums[i]==nums[index2])
                    count2++;
        }
        //cout<<index1<<index2;
        if(count1>nums.size()/3)
            v.push_back(nums[index1]);
        if(count2>nums.size()/3)
            v.push_back(nums[index2]);
        return v;
        
    }

};
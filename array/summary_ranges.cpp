// C++ program to summaries the ranges of an array
#include <bits/stdc++.h> 
using namespace std; 
vector<string> v;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int i,j,k,l,flag = 0;
        string s,temp;
        vector<string>v;
        // check for empty
        if(nums.size()==0)
            return v;
                                        // better solution is below this code using two pointer
        // only one element
        if(nums.size()==1){
            v.push_back(to_string(nums[0]));
            return v;
        }

        // for all
        for(i=0;i<nums.size()-1;i++ ){
            if(nums[i]+1==nums[i+1]){
                if(flag==0){
                    temp+=to_string(nums[i]);
                    flag=1;
                }else{
                    continue;
                }
            }
            else{
                if(flag==1){
                    temp+='-';
                    temp+='>';
                    temp+=to_string(nums[i]);
                    v.push_back(temp); 
                    flag=0;
                    temp.clear();
                }else{
                        temp+=to_string(nums[i]);
                        v.push_back(temp);
                        flag=0;
                        temp.clear();
                }
                               
            }
            
        }
        if(flag){
            temp+='-';
            temp+='>';
            temp+=to_string(nums[i]);
            v.push_back(temp);
        }else{
              temp+=to_string(nums[i]);
              v.push_back(temp);
        }
        return v;
        
    }
};
///////
// code using two pointer

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        int beg = 0, end = 1;
        
        while (end < nums.size()) {
            string ans = "";
            ans += to_string(nums[beg]);
            
            int count = 0;
            while (end < nums.size() && nums[end] == nums[beg] + 1) {
                count++;
                
                beg++;
                end++;
            }
            
            if (count != 0) {
                ans += "->" + to_string(nums[beg]);                
            }
            
            beg = end;
            end++;
            
            res.push_back(ans);
        }
        
        if (beg == nums.size() - 1) res.push_back(to_string(nums[beg]));
        
        return res;
    }
};
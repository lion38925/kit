class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        
        int i,j;
        
        j=1;
        for(i=0;i<arr.size();i++){
            if(arr[i]==j){
                j++;
                continue;
            }
            else{
                while(arr[i]!=j){
                    k--;
                    j++;
                    if(k==0){
                    j--;
                    break;
                    }
                }
                
                if(k!=0&&arr[i]==j)
                    j++;
                if(k==0)
                    break;
            }
        }
        k--;
        while(k>0){
            j++;
            k--;
        }
        
        return j;
        
    }
};
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        int i,s=0,j,n;
        n = arr.size();
        for(i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        s+=arr[n-1];
        arr.insert(arr.begin(),0);
        for(i=3;i<n+1;i=i+2){
            j= i;
            
            while(j<n+1){
                s+=arr[j]-arr[j-i];
                
                
                j++;
            }
            
            
        }
        
        return s;
        
    }
};
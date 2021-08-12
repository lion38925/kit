class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        
        int i,j,k,low,m,n,flag=0,high;
        
        vector<int>v(arr.size()+1,0);
        
        n= arr.size();
        
        
        queue<int>q;
        
        q.push(start);
            
        
        while(!q.empty()){
            k = q.front();
            q.pop();
            
            if(v[k]==0){
                v[k]=1;
            low = k-arr[k];
            high = k+ arr[k];
            
            if(low>=0&&low<n){
                if(arr[low]==0){
                    flag=1;
                    break;
                }else{
                    
                    q.push(low);
                }
                    
            }
            
            if(high>=0&&high<n){
                if(arr[high]==0){
                    flag=1;
                    break;
                }else{
                    q.push(high);
                }
                    
            }
          }      
        }
        
        if(flag)
            return true;
        return false;
    }
};
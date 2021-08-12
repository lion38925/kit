class Solution {

    // this solution is using recursive + memo but this gives tle so in next solution we use dp table
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
     
        int  i,j,n,index=0,temp;
        
        n = arr.size();
        
        vector<int> vis(n+1,-1);

        temp = part(arr,k,index,n,vis);
        
        return temp;
    }
    
    
    int part(vector<int> arr, int k, int index, int n,vector<int>& vis){
        
       
       int l,ma,i,currmax = 0;
        ma = 0;
        
        if(index>n-1)
            return 0;
        
        if(vis[index]!=-1)
            return vis[index];
        
        for(l=index;l<min(n,index+k);l++){
            
                currmax = max(currmax,arr[l]);
                ma = max(ma,currmax*(l-index+1)+part(arr,k,1+l,n,vis));
                


        }
        return vis[index] = ma;
        
    }
};

// dp approach table  


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
     
        int  i,j,n,index=0,temp,currmax;
        
        n = arr.size();
        
        vector<int> v(n+1,0);
        v[1] = arr[0];

        
        for(i=0;i<n;i++){
            currmax = 0;
            for(j=0;j<k;j++){
                if(i-j>=0){
                    currmax = max(currmax,arr[i-j]);
                    v[i+1] = max(v[i+1],v[i-j]+currmax*(j+1));
                }
                
            }
        }
        
        return v[n];
    }
    

};
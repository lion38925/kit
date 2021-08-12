class Solution {
public:

    
    int repeatedNTimes(vector<int>& A) {
        
        int i,j;
        unordered_map<int,int>mp;
   
        
        for(j=1;j<=3;j++){
            i=0;
            while(i<A.size()-j){
                if(A[i]==A[i+j])
                    return A[i];
                i++;
            }
        }
        
            
        return 0;
    }

};
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i ,j,k,l,n;
        n = bits.size();
        if(n==0)
            return false;
        if(n==1){
            if(bits[0]==0)
                return true;
            return false;
        }
        
        for(i=0;i<n;i++){
            if(bits[i]==1){
                if(i==n-2)
                    return false;
                    
                i++;
            }            
        }
        return true;
    }
};
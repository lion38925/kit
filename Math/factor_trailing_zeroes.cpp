class Solution {
public:
    int trailingZeroes(int n) {
        
        int i,res=0;
        for(i=5;i<=n;i=i*5){
            res+= n/i;
            
        }
        
        return res;
        
    }
};
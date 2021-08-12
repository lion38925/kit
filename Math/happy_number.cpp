class Solution {
public:
    bool isHappy(int n) {
        
        int i,k,l,res,nf=100;
        while(nf--){
            
            k = n;
            res=0;
            while(k){
                i = k%10;
                res+=i*i;
                k=k/10;
            }
            
            if(n==1)
                break;
            n=res;
            

            
            
        }
        
        if(n==1)
            return true;
        else
            return false;
        
    }
};
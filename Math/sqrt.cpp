class Solution {
public:
    int mySqrt(int x) {
        
        long long i,j,l,r,m,prev=-1;
        l=0;
        r=x;
        if(x==1)
            return 1;
        while(l<r){
            
            m = (l+r)/2;
            if(m*m>x){
                r=m;
            }else{
                l=m;
            }
            
            if(prev==m)
                break;
            
            prev=m;
            
        }
        return l;
    }
};
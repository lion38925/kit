class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        
        int i,t=0,x;
        
        for(i=L;i<=R;i++){
            
            x = __builtin_popcount(i);
            if(x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19)
                t++;
        }
        return t;
        
    }
};
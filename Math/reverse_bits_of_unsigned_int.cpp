class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t i,j,k=0,N;
        
        N = n;
        i=0;
        while(i<sizeof(N)*8){
                
            if(N&1<<i){
                k=k|1;
            }
                
            
            i++;
            if(i==32)
                break;
            k=k<<1;
        }
        
        return k;
        
    }
};
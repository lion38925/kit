class Solution {
public:
    int countOdds(int low, int high) {
        
        int l;
        
        if(low==high+1)
            l=0;
        else
            l = (high-low)/2;
        
        if(low%2==1)        
            l++;
        
        if((high-low)%2==1&&high%2==1)
            l++;
        
        return l;
        
    }
};
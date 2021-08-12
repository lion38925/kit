class Solution {
public:
    bool validPalindrome(string s) {
        int i,flag,l,r;
        l=0;
        r= s.length()-1;
        
            
        while(l<r&&s[l]==s[r]){
                l++;
                r--;                
            }
        if(l>=r)
            return true;
        
        
        if(rg(s,l+1,r)||rg(s,l,r-1))
            return true;
            
        
        return false;

    }
    
    bool rg(string s, int l, int r){
        
        while(l<r&&s[l]==s[r]){
        
            l++;
            r--;
            
        }
        
        if(l>=r)
            return true;
        return false;
    }
};
class Solution {
public:
    // when string is given of alphabets like "ZY"  one need to tell the number
    int titleToNumber(string s) {
        long long i,j,k,res=0;
        
        for(i=0;i<s.length();i++){
            k = s[i]-64;
            res=res*26+k;
        }
        return res;
    }
};
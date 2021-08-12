
class Solution {
public:
    bool isPowerOfFour(int num) {
        int n;
        n=num;
    if(n == 0) 
        return false; 
    double ans = (double)(log10(n)/log10(4));
    return ceil(ans) ==floor(ans);
 
    }
};


// similarly for any power of any number we need to change 4 to that number and check for that 

/// example for power of 3



class Solution {
public:
    bool isPowerOfThree(int n) {
        
    if(n == 0) 
        return false; 
    double ans = (double)(log10(n)/log10(3));
    return ceil(ans) ==floor(ans);
        
    }
};
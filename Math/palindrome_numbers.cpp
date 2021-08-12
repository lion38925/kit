class Solution {
public:
    bool isPalindrome(int x) {
        
        long long i,flag=0,res=0,temp,ki;
        ki=x;
        if(x<0)
            return false;
        
        while(x>0){
            temp = x%10;
            res = res*10+temp;
            x=x/10;
        }
        
        if(res==ki)
            return true;
        return false;
    }
};
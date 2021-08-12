class Solution {
public:
    int divide(int dividend, int divisor) {
        
        long long count =0,a,b,ma=INT_MAX,mi=INT_MIN;
        a = dividend;
        b = divisor;
        a = abs(a);
        b =  abs(b);
        if(a==ma&&b==-1)
            return ma;
       
        
        
        if((dividend<0&&divisor<0)||(dividend>0&&divisor>0))
            count=exp(log(a)-log(b));
        else
            count = -exp(log(a)-log(b));
        
        if(count>ma||count<mi)
            return ma;
        
        return count;
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        
        double res=1;
        int k=n;
        n=abs(n);
        while(n>0){
            if(n%2!=0)
                res=x*res;
            x=x*x;
            n=n/2;
        }
        if(k>0)
            return res;
        else
            return 1/res;
        
    }
};
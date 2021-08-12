class Solution {
public:
    int reverse(int x) {
        
        
        long long i,j,k,l,m,n,ma=INT_MAX,mi=INT_MIN,flag=0,temp,res=0;
        
        if(x<0){
            flag=1;
            x=abs(x);
        }
    
        while(x>0){
            temp = x%10;
            res = res*10+temp;
            x=x/10;
        }
        if(flag)
            res = res*-1;
        
        if(res<mi||res>ma)
            return 0;
        
        return res;
        
        
    }
};
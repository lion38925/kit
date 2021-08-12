class Solution {
public:
    int minSteps(int n) {
        
        
        int i,k,p;
        
        
        vector<int>v(n+1,0);
        
        for(i=2;i<=n;i++){
            
            k = getmax(i);      // get the minimum divisor of the number
            p = i/k;            // get the maximum divisor of the number
            
            if(k==i)            // in case of prime number
                v[i] = k;
 
            else
                v[i] = min(v[k]+i/k ,v[p]+i/p);     // take the minimum from both of the divisors
        }
        
        return v[n];
    }
    
    int getmax(int n){
        
        for(int i=2;i<=n;i++){
            if(n%i==0)
                return i;
        }
        return n;
    }
};
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        
        
        
        long long i,n=0;
        vector<bool>v;
        
        for(i=0;i<A.size();i++){
            n<<=1;
            n|=A[i];
            
            if(n%5==0)
                v.push_back(true);
            else
                v.push_back(false);
               
            n=n%5;          // here if you will not take modulus then it will give error due to shifting to left
            // of negative numbers so left shift it
        }       
        
        return v;
    }
};
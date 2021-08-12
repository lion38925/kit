class Solution {
public:
    int minAddToMakeValid(string S) {
        
        
        int i,j,k=0,t=0;
        
        for(i=0;i<S.length();i++){
            if(S[i]=='(')
                k++;
            else
                if(S[i]==')'){
                    k--;
                }
            if(k<0){
                t+=abs(k);
                k=0;
            }
        }
        
        t+=abs(k);
        
        return t;
    }
};
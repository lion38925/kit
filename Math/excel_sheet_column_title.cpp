class Solution {
public:
    string convertToTitle(int n) {
        
        
        int i;
        string k;
        
        
        while(n){
            
            i=n%26;
            
            if(i==0){
                i=26;       // this condition is for Z;
            }
            
            //cout<<i<<"\n";
            char p;
            p = 'A'+i-1;
            
            k= p+k;

            if(i==26){          // this check is for only Z scenario
                n=n/26-1;   
            }else{
                n=n/26;
            }
        }
        
        return k;
        
    }
};
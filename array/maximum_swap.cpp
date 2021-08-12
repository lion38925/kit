class Solution {
public:
    int maximumSwap(int num) {
        int i,j,k,l,ma;
        string si;
        si = to_string(num);
        
        for(i=0;i<si.length();i++){
            if(si[i]<si[i+1]){
                break;
            }
                
        }
        ma = i;
        for(j=i+1;j<si.length();j++){
            if(si[ma]<=si[j]){
                ma=j;
            }
        }
        
        for(j=0;j<si.length();j++){
            if(si[j]<si[ma])
                break;
        }
        if(ma!=i){
            char t;
            t = si[ma];
            si[ma]=si[j];
            si[j]=t;
        }
        return stoi(si);
        
    }
};
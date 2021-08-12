bool comp(string a , string b){
    return a.length()<b.length();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp);
        
        int i,j,k,l,m,n,ma =0;
        
        n = words.size();
        
        vector<int> v(n+1,1);
        
        v[0]=0;
        
        
        for(i=0;i<n;i++){
            
            for(j=i-1;j>=0;j--){
                
                if(words[j].length()+1==words[i].length()){
                    if(getv(words[j],words[i])){
                        if(v[j+1]+1>v[i+1])
                            v[i+1]=v[j+1]+1;
                    }
                    
                }
                else
                    if(words[j].length()==words[i].length())
                        continue;
                else
                    break;
            }
            
        }
        
        ma = *max_element(v.begin(),v.end());
        
        return ma;
        
    }
    
    bool getv(string a, string b){
        
        int i,j,k=0;
        
        j=0;
        i=0;
        while(i<a.size()){
            if(a[i]!=b[j]){
                j++;
                k++;
            }else{
                i++;
                j++;
            }
            if(j>b.size())
                break;
                
        }
        
        if(k>1)
            return false;
            
        return true;
        
    }
};
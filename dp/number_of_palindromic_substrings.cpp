class Solution {
public:
    int countSubstrings(string s) {
         int i,start=0,end=0,ma=INT_MIN,j,k,l,h,n,t=0;
        
        set<pair<int,int>>si;
        n = s.length();
        if(n==0)
            return 0;
        
        for(i=0;i<n;i++){
            
            
            l=i;
            h=i+1;
            
            while(l>=0&&h<n&&s[l]==s[h]){
                if(si.find({l,h})==si.end()){
                    t++;
                    si.insert({l,h});
                }
                l--;
                h++;
            }

            l=i-1;
            h=i+1;
            while(l>=0&&h<n&&s[l]==s[h]){
                if(si.find({l,h})==si.end()){
                    t++;
                    si.insert({l,h});
                }
                l--;
                h++;
            }
            
            
        }
            
        return t+n;
    }
};
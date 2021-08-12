class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int t=0,f=0,i,n;
        n  = word.length();
        for(i=0;i<n;i++){
            if(word[i]==toupper(word[i]))
                t++;
            if(word[i]==toupper(word[i])&&i==0)
                f=1;
        }
        if(t==1&&f==1)
            return true;
        else
            if(t==n||t==0)
                return true;
        return false;
    }
};
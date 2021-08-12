class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> a(S.length(), INT_MAX);
        int pos, flag = 0;
        
        for(int i =0; i< S.length(); ++i)
        {
            if(S[i] == C)
             pos = 0;
            a[i] = pos;
            pos++;
            
        }
         for(int i =S.length() - 1; i>= 0; --i)
        {
            if(S[i] == C)
            {
             pos = 0;
            }
            a[i] = min(a[i], pos);
             pos++;
        }
        return a;
    }
};
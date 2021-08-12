class Solution {
public:
// this solution is very easy understand the logic 
    string sortString(string s) {
        
        vector<int> freq(26, 0);
        
        for(int i=0; i<s.length(); i++)
            freq[s[i]-'a']++;
        int i=0;
        while(i<s.length())
        {
            for(int j=0; j<26; j++)
            {
                if(freq[j]>0)
                {
                    s[i++]=static_cast<char>(97+j);
                    freq[j]--;
                }
            }
            
            for(int j=25; j>=0; j--)
            {
                if(freq[j]>0)
                {
                    s[i++]= static_cast<char>(97+j);
                    freq[j]--;
                }
            }
        }
        return s;
    }
};
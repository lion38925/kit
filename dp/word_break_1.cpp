class Solution {
public:
    
    unordered_map<int,bool> dp;

    // in this question we need to return whether we can break a word using words from 
    // dictionary or not
    
    bool compute(string& s,int start, unordered_set<string>& available){
        if(start == s.length()) return true;
        if(dp.count(start)) return dp[start];
        int end = start;
        while(end < s.length()){
            if(available.count(s.substr(start, end-start+1))){
                dp[start] = compute(s, end+1, available);
                if(dp[start]) return true;
            }
            end++;
        }
        dp[start] = false;
        return dp[start];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> available;
        for(string& word: wordDict){
            available.insert({word});
        }
        return compute(s, 0, available);
    }
};
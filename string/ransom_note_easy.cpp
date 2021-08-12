class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        
        for(int i =0;i<ransomNote.length();i++){
            mp[ransomNote[i]]++;
        }
        
        for(int i =0;i<magazine.length();i++){
            if(mp.find(magazine[i])!=mp.end()){
                mp[magazine[i]]--;
                if(mp[magazine[i]]==0)
                    mp.erase(magazine[i]);
            }
        }
        
        if(mp.size()>0)
            return false;
        return true;
    }
};
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> set;
        for(int i = 0; i < A.size(); i++){
            string s(52, '0');
            for(int j = 0; j < A[i].size(); j++){
                if(j % 2 == 0)
                    s[A[i][j] - 'a']++;
                else
                    s[A[i][j] - 'a' + 26]++;
            }
            
            set.insert(s);
                 
        }
        return set.size();
    }
};
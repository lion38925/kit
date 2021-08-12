class Solution {
public:
    bool isNoZero(int x)
    {
        while(x>0)
        {
            int rem = x%10;
            if(rem == 0)
                return false;
            x = x/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i=1;i<=n/2;i++)
        {
            if(isNoZero(i) && isNoZero(n-i))
            {
                ans.push_back(i);
                ans.push_back(n-i);
                return ans;
            }
        }
        return ans;
    }
};
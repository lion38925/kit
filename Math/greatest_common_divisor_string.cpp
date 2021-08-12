//After creating next array, we are able to find the minimum repeat unit for each string. If the two repeat units are equal, we need to transform two strings to base unit, then find gcd of these two transformed strings and finally convert back.
//For example, if str1 = "ABCABCABCABC" and str2 = "ABCABC", we can find out minimum repeat unit is "ABC". Then we can transform two original string to"ABC" * 4 and "ABC" * 2. It's easy to show the gcd of these two strings is "ABC" * gcd(4,2) which is "ABCABC".

class Solution {
public:
    int f(const string& str) {
        vector<int> dp(str.size(),0);
        int j = -1; 
        dp[0] = -1;
        for(int i = 1;i<str.size();i++) {
            while(j!=-1 && str[j+1]!=str[i]) {
                j = dp[j];
            }
            if(str[j+1] != str[i]) {
                dp[i] = -1;
            } else {
                dp[i] = j + 1; 
                j++;
            }
        }
        int ret = str.size() -1 - dp[str.size()-1];
        j = ret*2-1; 
        while(j<dp.size() && dp[j] == j - ret) {
            j += ret; 
        }
        if(j == dp.size() + ret - 1) {
            return ret; 
        }
        return str.size(); 
    }
    string gcdOfStrings(string str1, string str2) {
        auto a = f(str1);
        auto b = f(str2);
        if(a!=b || str1.substr(0,a) != str2.substr(0,a)) {
            return "";
        }
        int ret = __gcd(str1.size()/a,str2.size()/a);
        return str1.substr(0,a*ret);
    }
};
Super smart solution from @ganz
class Solution {
public:
    string gcdOfStrings(const string& s1, const string& s2)
    {
        return (s1 + s2 == s2 + s1)  
		    ? s1.substr(0, gcd(size(s1), size(s2)))
			: "";
    }
};


//---------------------------------------------------------
//We know that if str1 and str2 have the same minimum repeat unit, we can re-write str1 to unit * a an re-write str2 to unit * b where a and b are both positive integer. And the gcd of these two string will be unit * gcd(a,b).
//To check if str1 and str2 have the same minimum repeat unit, we only need to comparestr1 + str2 with str2 + str1. It's because unit*(a+b) == unit*(b+a).
//If we make sure str1 and str2 have the same minimum repeat unit, we know gcd(len(str1),len(str2)) == len(unit) * gcd(a,b). Then it's easy for us to find out the gcd of these two strings without compute the minimum repeat unit.

//By the way, I don't think it's a easy problem. It should at least be a medium problem.-
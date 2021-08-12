class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int r1, c1, r2, c2, r3, c3;
        int pos1 = a.find('+');
        int pos2 = b.find('+');
        r1 = stoi(a.substr(0, pos1));
        r2 = stoi(b.substr(0, pos2));
        c1 = stoi(a.substr(pos1+1, a.size()-1-pos1));
        c2 = stoi(b.substr(pos2+1, b.size()-1-pos2));
        
        r3 = (r1 * r2) - (c1 * c2);
        c3 = (r1 * c2) + (r2 * c1);
        
        return to_string(r3) + '+' + to_string(c3) + 'i';
    }
};
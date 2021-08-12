#include <iostream> 
#include <sstream> 
using namespace std; 

class Solution {
public:
    int numDecodings(string s) {
        int i,j,k,l,n;
        n = s.length();
        vector<int>v(n+1,0);
        v[0]=1;
        v[1]=1;
        
            int kit = stoi(to_string(s[0]));
            kit = kit -48;
            if(kit==0)
                return 0;
            
        
        for(i=1;i<n;i++){
            
            int second = stoi(to_string(s[i]));
            int first =  stoi(to_string(s[i-1]));
            second = second - 48;
            first = first - 48;
            if(second>=1&&second<=9){
                v[i+1]+=v[i];
            }
                
            
            if((first==1&&(second>=0&&second<=9))||(first==2&&(second>=0&&second<=6)) ){
                v[i+1]+=v[i-1];
            }
        }

        return v[n];
        
    }
};
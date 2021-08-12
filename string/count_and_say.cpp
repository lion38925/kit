// C++ program to find n'th term in look and say 
// sequence 
#include <bits/stdc++.h> 
using namespace std; 

// Returns n'th term in look-and-say sequence 
string countnndSay(int n) 
{ 
	// Base cases 
	if (n == 1)	 return "1"; 
	if (n == 2)	 return "11"; 

	// Find n'th term by generating all terms from 3 to 
	// n-1. Every term is generated using previous term 
	string str = "11"; // Initialize previous term 
	for (int i = 3; i<=n; i++) 
	{ 
		// In below for loop, previous character 
		// is processed in current iteration. That 
		// is why a dummy character is added to make 
		// sure that loop runs one extra iteration. 
		str += '$'; 
		int len = str.length(); 

		int cnt = 1; // Initialize count of matching chars 
		string tmp = ""; // Initialize i'th term in series 

		// Process previous term to find the next term 
		for (int j = 1; j < len; j++) 
		{ 
			// If current character does't match 
			if (str[j] != str[j-1]) 
			{ 
				// Append count of str[j-1] to temp 
				tmp += cnt + '0'; 

				// Append str[j-1] 
				tmp += str[j-1]; 

				// Reset count 
				cnt = 1; 
			} 

			// If matches, then increment count of matching 
			// characters 
			else cnt++; 
		} 

		// Update str 
		str = tmp; 
	} 

	return str; 
} 

// Driver program 
int main() 
{ 
	int N = 3; 
	cout << countnndSay(N) << endl; 
	return 0; 
} 

/// my code

class Solution {
public:
    string countAndSay(int n) {
        int i,j,k,l,temp;
        string s,ki;
        
        ki = '1';
        if(n==1)
            return ki;
        while(n>1){
            j=0;
            temp = 1;
            while(j<ki.length()-1){
                
                if(ki[j]!=ki[j+1]){
                    s=s+to_string(temp)+ki[j];
                    temp=1;
                }else{
                    temp++;
                }
                                
                j++;
            }
            s=s+to_string(temp)+ki[j];
            ki=s;
            s.clear();
            n--;
            
        }
        return ki;
    }
};
// A O(n^2) time and O(1) space program to 
// find the longest palindromic substring 
#include <bits/stdc++.h> 
using namespace std; 

// A utility function to print a substring str[low..high] 
void printSubStr(char* str, int low, int high) 
{ 
	for( int i = low; i <= high; ++i ) 
		cout << str[i]; 
} 

// This function prints the longest palindrome substring (LPS) 
// of str[]. It also returns the length of the longest palindrome 
int longestPalSubstr(char *str) 
{ 
	int maxLength = 1; // The result (length of LPS) 

	int start = 0; 
	int len = strlen(str); 

	int low, high; 

	// One by one consider every character as center point of 
	// even and length palindromes 
	for (int i = 1; i < len; ++i) 
	{ 
		// Find the longest even length palindrome 
		// with center points as i-1 and i. 
		low = i - 1; 
		high = i; 
		while (low >= 0 && high < len && str[low] == str[high]) 
		{ 
			if (high - low + 1 > maxLength) 
			{ 
				start = low; 
				maxLength = high - low + 1; 
			} 
			--low; 
			++high; 
		} 

		// Find the longest odd length palindrome with center 
		// point as i 
		low = i - 1; 
		high = i + 1; 
		while (low >= 0 && high < len && str[low] == str[high]) 
		{ 
			if (high - low + 1 > maxLength) 
			{ 
				start = low; 
				maxLength = high - low + 1; 
			} 
			--low; 
			++high; 
		} 
	} 

	cout<<"Longest palindrome substring is: "; 
	printSubStr(str, start, start + maxLength - 1); 

	return maxLength; 
} 

// Driver program to test above functions 
int main() 
{ 
	char str[] = "forgeeksskeegfor"; 
	cout<<"\nLength is: "<<longestPalSubstr(str)<<endl; 
	return 0; 
} 

// This is code is contributed by rathbhupendra 


/// my code

class Solution {
public:
    string longestPalindrome(string s) {
        
        int i,start=0,end=0,ma=INT_MIN,j,k,l,h,n;
        
        n = s.length();
        if(n==0)
            return s;
        
        for(i=0;i<n;i++){
            
            
            l=i;
            h=i+1;
            
            while(l>=0&&h<n&&s[l]==s[h]){
                if(h-l>ma){
                    start=l;
                    end = h;
                    ma = h-l;
                }
                l--;
                h++;
            }

            l=i-1;
            h=i+1;
            while(l>=0&&h<n&&s[l]==s[h]){
                if(h-l>ma){
                    start=l;
                    end = h;
                    ma = h-l;
                }
                l--;
                h++;
            }
            
            
        }
        string s1(s.begin()+start,s.end()-n+end+1);
        return s1;
    }
};
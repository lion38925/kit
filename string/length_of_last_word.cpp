// CPP program for implementation of efficient 
// approach to find length of last word 
#include <bits/stdc++.h> 
#include <iostream> 
using namespace std; 

int length(string str) 
{ 
	int count = 0; 
	bool flag = false; 
	for (int i = str.length() - 1; i >= 0; i--) { 
		// Once the first character from last 
		// is encountered, set char_flag to true. 
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) { 
			flag = true; 
			count++; 
		} 
		// When the first space after the 
		// characters (from the last) is 
		// encountered, return the length 
		// of the last word 
		else { 
			if (flag == true) 
				return count; 
		} 
	} 
	return count; 
} 

// Driver code 
int main() 
{ 
	string str = "Geeks for Geeks"; 
	cout << "The length of last word is " << length(str); 
	return 0; 
} 

// This code is contributed by rahulkumawat2107 

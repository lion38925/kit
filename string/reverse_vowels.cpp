// C++ program to reverse order of vowels 
#include<bits/stdc++.h> 
using namespace std; 

// utility function to check for vowel 
bool isVowel(char c) 
{ 
	return (c=='a' || c=='A' || c=='e' || 
			c=='E' || c=='i' || c=='I' || 
			c=='o' || c=='O' || c=='u' || 
			c=='U'); 
} 

// Function to reverse order of vowels 
string reverseVowel(string str) 
{ 
	// Start two indexes from two corners 
	// and move toward each other 
	int i = 0; 
	int j = str.length()-1; 
	while (i < j) 
	{ 
		if (!isVowel(str[i])) 
		{ 
			i++; 
			continue; 
		} 
		if (!isVowel(str[j])) 
		{ 
			j--; 
			continue; 
		} 

		// swapping 
		swap(str[i], str[j]); 

		i++; 
		j--; 
	} 

	return str; 
} 

// Driver function 
int main() 
{ 
	string str = "hello world"; 
	cout << reverseVowel(str); 
	return 0; 
} 

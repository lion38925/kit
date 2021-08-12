
//Time Complexity: O(n2^n)
// C++ Program of above approach 
#include <iostream> 
#include <math.h> 
using namespace std; 

class gfg 
{ 
	
public: 
void printPowerSet(char *set, int set_size) 
{ 
	/*set_size of power set of a set with set_size 
	n is (2**n -1)*/
	unsigned int pow_set_size = pow(2, set_size); 
	int counter, j; 

	/*Run from counter 000..0 to 111..1*/
	for(counter = 0; counter < pow_set_size; counter++) 
	{ 
	for(j = 0; j < set_size; j++) 
	{ 
		/* Check if jth bit in the counter is set 
			If set then print jth element from set */
		if(counter & (1 << j)) 
			cout << set[j]; 
	} 
	cout << endl; 
	} 
} 
}; 

/*Driver code*/
int main() 
{ 
	gfg g; 
	char set[] = {'a','b','c'}; 
	g.printPowerSet(set, 3); 
	return 0; 
} 

// This code is contributed by SoM15242 


//another solution 

/*
// CPP program to generate power set 
#include <bits/stdc++.h> 
using namespace std; 

// str : Stores input string 
// curr : Stores current subset 
// index : Index in current subset, curr 
void powerSet(string str, int index = 0, 
			string curr = "") 
{ 
	int n = str.length(); 

	// base case 
	if (index == n) { 
		cout << curr << endl; 
		return; 
	} 

	// Two cases for every character 
	// (i) We consider the character 
	// as part of current subset 
	// (ii) We do not consider current 
	// character as part of current 
	// subset 
	powerSet(str, index + 1, curr + str[index]); 
	powerSet(str, index + 1, curr); 
} 

// Driver code 
int main() 
{ 
	string str = "abc"; 
	powerSet(str); 
	return 0; 
} 

*/

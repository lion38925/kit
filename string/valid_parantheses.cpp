// CPP program to check for balanced parenthesis. 
#include<bits/stdc++.h> 
using namespace std; 

// function to check if paranthesis are balanced 
bool areParanthesisBalanced(string expr) 
{ 
	stack<char> s; 
	char x; 

	// Traversing the Expression 
	for (int i=0; i<expr.length(); i++) 
	{ 
		if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 	// if comparing this doest not work then make a string of string ki = '({[' use 
														// this to compare now
		{ 
			// Push the element in the stack 
			s.push(expr[i]); 
			continue; 
		} 

		// IF current current character is not opening 
		// bracket, then it must be closing. So stack 
		// cannot be empty at this point. 
		if (s.empty()) 
		return false; 

		switch (expr[i]) 
		{ 
		case ')': 

			// Store the top element in a 
			x = s.top(); 
			s.pop(); 
			if (x=='{' || x=='[') 
				return false; 
			break; 

		case '}': 

			// Store the top element in b 
			x = s.top(); 
			s.pop(); 
			if (x=='(' || x=='[') 
				return false; 
			break; 

		case ']': 

			// Store the top element in c 
			x = s.top(); 
			s.pop(); 
			if (x =='(' || x == '{') 
				return false; 
			break; 
		} 
	} 

	// Check Empty Stack 
	return (s.empty()); 
} 

// Driver program to test above function 
int main() 
{ 
	string expr = "{()}[]"; 

	if (areParanthesisBalanced(expr)) 
		cout << "Balanced"; 
	else
		cout << "Not Balanced"; 
	return 0; 
} 

// my code
class Solution {
public:
    bool isValid(string s) {
        
        int i=0,j,n;
        n = s.length();
        string ki = "({[";
        stack<char> st;
        char k;
        while(i<n){
            if(s[i]==ki[0]||s[i]==ki[1]||s[i]==ki[2]){
                st.push(s[i]);
            }
            else
                if(st.empty())
                    return false;
            else{
                switch(s[i]){
                        case ')':
                            if(st.top()=='['||st.top()=='{')
                                return false;
                            st.pop();
                            break;
                        case ']':
                            if(st.top()=='('||st.top()=='{')
                                return false;
                            st.pop();
                            break;
                        case '}':
                            if(st.top()=='['||st.top()=='(')
                                return false;
                            st.pop();
                            break;
                            
                }
            }
            i++;
        }
        if(st.empty())
            return true;
        return false;
    }
};

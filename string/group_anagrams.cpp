// A C++ program to print all anagarms together 
#include <bits/stdc++.h> 
#include <string.h> 
using namespace std; 

void printAnagramsTogether(char* wordArr[], int size)       // one need to have char * to convert it to string
{ 
	// Step 1: Create a copy of all words present in given wordArr. 
	// The copy will also have original indexes of words 
	int i;
	unordered_map<string, list<string>>mp;
	for(i=0;i<size;i++){
	    string temp=wordArr[i];
	    string temp2=wordArr[i];
	    sort(temp.begin(),temp.end());
        mp[temp].push_back(temp2);          // we push_back for list 
	  
	}
	
 for (auto itr : mp){                               // use auto 
        cout << itr.first << ":\t" << endl;
        for (auto innerItr : itr.second)
            cout << innerItr << " ";
        cout << endl;
    }

} 

// Driver program to test above functions 
int main() 
{ 
	char* wordArr[] = { "cat", "dog", "tac", "god", "act" }; 
	int size = sizeof(wordArr) / sizeof(wordArr[0]); 
	printAnagramsTogether(wordArr, size); 
	return 0; 
} 

// This is code is contributed by rathbhupendra 

/// my code

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mp;
        vector<vector<string>> vi;
        int i,j,k,l,m,n;
        
        for(i=0;i<strs.size();i++){
            string ki;
            ki = strs[i];
            sort(ki.begin(),ki.end());
            
              mp[ki].push_back(strs[i]);

        }
        
        for(auto itr:mp){
            vi.push_back(itr.second);
        }
        
        return vi;
        
    }
};

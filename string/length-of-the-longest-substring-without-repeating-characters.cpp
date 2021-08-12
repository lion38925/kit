#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int main() {
	// your code goes here
	int i,m=0,c=0,start=0;
	string s;
	cin>>s;
	unordered_map<char, int> mp;
	
	for(i=0;i<s.length();i++)
	{
	    if(mp.find(s[i])!=mp.end())
	        {
	            c=i-start;
	            if(start<(mp[s[i]]+1))
	                start=mp[s[i]]+1;
	            
	            if(c>m)
	                m=c;
	           
	        }
	    
	    mp[s[i]]=i;
	    
	    
	}
	c=i-start;
	if(c>m)
	  m=c;
	
	cout<<m;
	return 0;
}

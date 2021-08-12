#include <iostream>

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int c=0;
	    int n;
	    n=s.size();
	    int op=0;
	    for(int i=0;i<n;i++)
	    {
	        
	        if(s[i]=='{')
	        {
	            op++;
	        }
	        else
	        {
	            if(op==0)
	            c++;
	            else
	            op--;
	        }
	        
	    }
	    int res=(op+c)/2+(op%2);
	    if(n%2)
	    cout<<"-1"<<endl;
	    else
	    cout<<res<<endl;
	}
	return 0;
}
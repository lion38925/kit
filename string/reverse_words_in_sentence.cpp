// CPP program to reverse a string
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// Function to reverse any sequence
// starting with pointer begin and
// ending with pointer end
void reverse(string &a, int start, int end)
{
    int j = start;

    while (j <= end)
    {
        char temp;              // char is used to get the values form string to char
        temp = a[j];
        a[j] = a[end];
        a[end] = temp;
        j++;
        end--;
    }
}

// Function to reverse words*/
void reverseWords(string &s)
{

    // Reversing individual words as
    // explained in the first step
    int i = 0;
    int start = 0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            reverse(s, start, i - 1);
            start = i + 1;
        }
        i++;
    }

    if (start < i - 1)
        reverse(s, start, i - 1);

    // Reverse the entire string
    reverse(s, 0, s.length() - 1);
}

// Driver Code
int main()
{
    string s = "i like this program very much";
    reverseWords(s);
    cout << s;
    return 0;
}


//another solution
class Solution {
public:
    string reverseWords(string s) {
        int i , j, k, l;
        
        l = s.length();
        j = 0;
        for(i=0;i<l;i++){
            if(s[i]==' '){
                reverse(s.begin()+j,s.begin()+i);
                j = i+1;
                
            }
        }
        if(i!=j||i!=j+1){
            reverse(s.begin()+j,s.begin()+i);
        }
        reverse(s.begin(),s.end());
        s = std::regex_replace(s, std::regex("^ +| +$|( ) +"), "$1");
        //s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s;
    }
};
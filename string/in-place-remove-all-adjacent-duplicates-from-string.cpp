#include <iostream>
using namespace std;
 
// Efficient function to in-place remove all adjacent duplicates
// from the given string
void removeAdjDup(string& str)
{
    // stores previous valid character
    char prev = str[0];
 
    // k maintains the index of last filled location in the result
    int k = 0;
 
    // start from second character
    int i = 1;
 
    // do till end of the string is reached
    while (i < str.length())
    {
        // if the current character is not same as the previous character
        if (prev != str[i])
        {
            str[++k] = str[i++];    // update result
            prev = str[k];          // update prev
        }
        else
        {
            // remove adjacent duplicates
            while (prev == str[i])
                i++;
 
            prev = str[--k];        // update prev
        }
    }
 
    // delete str[k+1, n) as result lies in str[0..k]
    str.erase(k + 1);
}
 
int main()
{
    string str = "ABDAADBDAABB";
 
    removeAdjDup(str);
    cout << "The string left after removal of all adjacent duplicates is "
         << str;
 
    return 0;
}
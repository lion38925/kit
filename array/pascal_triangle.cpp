// C++ program for Pascal’s Triangle
// A O(n^2) time and O(n^2) extra space
// method for Pascal's Triangle
#include <bits/stdc++.h>
using namespace std;

void printPascal(int n)
{

    // An auxiliary array to store
    // generated pscal triangle values
    int arr[n][n];

    // Iterate through every line and
    // print integer(s) in it
    for (int line = 0; line < n; line++)
    {
        // Every line has number of integers
        // equal to line number
        for (int i = 0; i <= line; i++)
        {
            // First and last values in every row are 1
            if (line == i || i == 0)
                arr[line][i] = 1;
            // Other values are sum of values just
            // above and left of above
            else
                arr[line][i] = arr[line - 1][i - 1] +
                               arr[line - 1][i];
            cout << arr[line][i] << " ";
        }
        cout << "\n";
    }
}

// Driver code
int main()
{
    int n = 5;
    printPascal(n);
    return 0;
}

// This code is Contributed by Code_Mech.
//
// best optimised code
// O(n2) and O(1) space

// C++ program for Pascal’s Triangle
// A O(n^2) time and O(1) extra space
// function for Pascal's Triangle

/*
Method 3 ( O(n^2) time and O(1) extra space )
This method is based on method 1. We know that ith entry in a 
line number line is Binomial Coefficient C(line, i) and all 
lines start with value 1. The idea is to calculate C(line, i) 
using C(line, i-1). It can be calculated in O(1) time using the following.

C(line, i)   = line! / ( (line-i)! * i! )
C(line, i-1) = line! / ( (line - i + 1)! * (i-1)! )
We can derive following expression from above two expressions.
C(line, i) = C(line, i-1) * (line - i + 1) / i

So C(line, i) can be calculated from C(line, i-1) in O(1) time
*/
#include <bits/stdc++.h>

using namespace std;
void printPascal(int n)
{

    for (int line = 1; line <= n; line++)
    {
        int C = 1; // used to represent C(line, i)
        for (int i = 1; i <= line; i++)
        {

            // The first value in a line is always 1
            cout << C << " ";
            C = C * (line - i) / i;
        }
        cout << "\n";
    }
}

// Driver code
int main()
{
    int n = 5;
    printPascal(n);
    return 0;
}

// This code is contributed by Code_Mech
//How did in method 3 (line - i + 1) / i in explanation became (line-i) / i in code any Reason?
//That's because the second loop starts from 1 instead of 0. So i is already 1 ahead of what we are printing currently.
//The reason we start from i=1 is its coming in the denominator and we can't divide by 0.

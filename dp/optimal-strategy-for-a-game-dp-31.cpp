// C++ program to find out
// maximum value from a given
// sequence of coins
#include <bits/stdc++.h>
using namespace std;

//-- to understand more https://www.youtube.com/watch?v=ww4V7vRIzSk&ab_channel=Pepcoding

// Returns optimal value possible
// that a player can collect from
// an array of coins of size n.
// Note than n must be even
int optimalStrategyOfGame(
    int *arr, int n)
{
    // Create a table to store
    // solutions of subproblems
    int table[n][n];

    // Fill table using above
    // recursive formula. Note
    // that the table is filled
    // in diagonal fashion (similar
    // to http:// goo.gl/PQqoS),
    // from diagonal elements to
    // table[0][n-1] which is the result.
    for (int gap = 0; gap < n; ++gap)
    {
        for (int i = 0, j = gap; j < n; ++i, ++j)
        {

            if (g == 0) {
                table[i][j] = arr[i];
            } else if (g == 1) {
                table[i][j] = max(arr[i], arr[j]);
            } else {
                int val1 = arr[i] + min(table[i + 2][j], table[i + 1][j - 1]);
                int val2 = arr[j] + min(table[i + 1][j - 1], table[i][j - 2]);
                table[i][j] = max(val1, val2);
            }
        }
    }

    return table[0][n - 1];
}

// Driver program to test above function
int main()
{
    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n",
           optimalStrategyOfGame(arr1, n));

    int arr2[] = {2, 2, 2, 2};
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n",
           optimalStrategyOfGame(arr2, n));

    int arr3[] = {20, 30, 2, 2, 2, 10};
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n",
           optimalStrategyOfGame(arr3, n));

    return 0;
}

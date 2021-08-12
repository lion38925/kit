// Dynamic Programming Solution for Palindrome Partitioning Problem
#include <limits.h>
#include <stdio.h>
#include <string.h>

// A utility function to get minimum of two integers
int min(int a, int b) { return (a < b) ? a : b; }

// Returns the minimum number of cuts needed to partition a string
// such that every part is a palindrome
int minPalPartion(char* str)
{
	// Get the length of the string
	int n = strlen(str);

	/* Create two arrays to build the solution in bottom-up manner
	C[i] = Minimum number of cuts needed for a palindrome partitioning
				of substring str[0..i]
	P[i][j] = true if substring str[i..j] is palindrome, else false
	Note that C[i] is 0 if P[0][i] is true */
	int C[n];
	bool p[n][n];

	int i, j, k, L; // different looping variables



	/* search for gap strategy. ------------------------*/
	for (int g = 0; g <= n; g++) {

		for (i = 0,j = g; j < n; i++,j++) {
			if(g==0){
                p[i][j]=true;
            }else if(g==1){
                p[i][j] = str[i]==str[j];
            }else{
                if(str[i]==str[j]&&p[i+1][j-1]){
                    p[i][j]=true;
                } else{
                    p[i][j] =false;
                }

            }
		}
	}

    c[0]=0;
    for(j=1;j<n;j++){
        if(p[0][j]){
            c[j] = 0;
        }
        else{
            c[j] = INT_MAX;
            for(i=j;i>=1;i--){
                if(p[i][j]){
                    c[j] = min(c[j],c[i-1]+1);
                }
            }
        }
    }

	// Return the min cut value for complete string. i.e., str[0..n-1]
	return C[n - 1];
}

// Driver program to test above function
int main()
{
	char str[] = "ababbbabbababa";
	printf("Min cuts needed for Palindrome Partitioning is %d",
		minPalPartion(str));
	return 0;
}

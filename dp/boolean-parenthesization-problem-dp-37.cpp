#include <cstring>
#include <iostream>
using namespace std;

// Returns count of all possible
// parenthesizations that lead
// to result true for a boolean 
// expression with symbols like
// true and false and operators 
// like &, | and ^ filled
// between symbols
int countParenth(char symb[], char oper[], int n)
{
	int F[n][n], T[n][n];

	// Fill diaginal entries first
	// All diagonal entries in 
	// T[i][i] are 1 if symbol[i]
	// is T (true). Similarly, 
	// all F[i][i] entries are 1 if
	// symbol[i] is F (False)
	for (int i = 0; i < n; i++) {
		F[i][i] = (symb[i] == 'F') ? 1 : 0;
		T[i][i] = (symb[i] == 'T') ? 1 : 0;
	}

	// Now fill T[i][i+1], 
	// T[i][i+2], T[i][i+3]... in order
	// And F[i][i+1], F[i][i+2], 
	// F[i][i+3]... in order
	for (int gap = 1; gap < n; ++gap) 
	{
		for (int i = 0, j = gap; 
			j < n; ++i, ++j)
		{
			T[i][j] = F[i][j] = 0;
			for (int k = i;k<j; k++)
			{
				int ltc = T[i][k];
				int rtc = T[k+1][j];
				int lfc = T[i][k];
				int rfc = T[k+1][j];

				if (oper[k] == '&') {
					T[i][j] += ltc * rtc;
					F[i][j] += lfc*rtc + lfc*rfc+ ltc*rfc;
				}
				if (oper[k] == '|')
				{
					F[i][j] += rfc*lfc;
					T[i][j] += ltc*rtc + ltc*rfc + lfc*rtc;
				}
				if (oper[k] == '^')
				{
					T[i][j] += rtc*lfc + rfc*ltc;
					F[i][j] += rfc*lfc + rtc*ltc;
				}
			}
		}
	}
	return T[0][n - 1];
}

// Driver code
int main()
{
	char symbols[] = "TTFT";
	char operators[] = "|&^";
	int n = strlen(symbols);

	// There are 4 ways
	// ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
	// (T|((T&F)^T))
	cout << countParenth(symbols, operators, n);
	return 0;
}

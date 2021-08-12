class Solution {
public:

// we need to find a way in which we can go till nth row with minimum sum and we from cell we can only go to
// either 1 left down or 1 right down
    int minFallingPathSum(vector<vector<int>>& A) 
{
	int n = A.size();
	int res = INT_MAX;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int left = j == 0 ? INT_MAX : A[i - 1][j - 1];
			int right = j == n - 1 ? INT_MAX : A[i - 1][j + 1];

			A[i][j] +=  min({left, right, A[i - 1][j]});
		}
	}

	for (int i = 0; i < n; i++)
		res = min(res, A[n - 1][i]);

	return res;
}
};
#include<bits/stdc++.h>
using namespace std;

#define N3 3
#define N10 10


bool longest_possible_route_matrix_with_hurdles_util( int matrix[N3][N10], bool visited[N3][N10], int s_x, int s_y, int d_x, int d_y, int partial_path, int &max_path)
{
	if( s_x == d_x && s_y == d_y )
	{
		if( partial_path > max_path )
		{
			max_path = partial_path;
		}
		return true;
	}

	if( s_x < 0 || s_x >= N3 || s_y < 0 || s_y >= N10 || matrix[s_x][s_y] == 0 || visited[s_x][s_y] == true )
	{
		return false;
	}

	visited[s_x][s_y] = true;

	bool p1= longest_possible_route_matrix_with_hurdles_util(matrix, visited, s_x+1, s_y, d_x, d_y, partial_path+1, max_path);

	bool p2 = longest_possible_route_matrix_with_hurdles_util(matrix, visited, s_x, s_y+1, d_x, d_y, partial_path+1 , max_path);

	bool p3 = longest_possible_route_matrix_with_hurdles_util(matrix, visited, s_x-1, s_y, d_x, d_y, partial_path+1, max_path);

	bool p4 =longest_possible_route_matrix_with_hurdles_util(matrix, visited, s_x, s_y-1, d_x, d_y, partial_path+1, max_path);

	visited[s_x][s_y] = false;


	if( p1 || p2 || p3 || p4 )
	{
		return true;
	}



	return false;
}

bool longest_possible_route_matrix_with_hurdles(int matrix[N3][N10], int s_x, int s_y, int d_x, int d_y)
{
	bool visited[N3][N10];
	int partial_path = 0;
	int max_path = 0;

	memset(visited, false, sizeof(visited));

	bool result = longest_possible_route_matrix_with_hurdles_util(matrix, visited, s_x, s_y, d_x, d_y, partial_path, max_path);

	if( result )
	{
		std::cout<<"Max path : " <<max_path<< std::endl;
		return true;
	}

	std::cout<<"No possible path found"<<std::endl;
	return false;
}




int main()
{
   
	int mat[N3][N10] =
	{
					{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
					{ 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
					{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	std::cout<<"Result: "<<std::endl;
	longest_possible_route_matrix_with_hurdles(mat, 0,0,1,7);
}
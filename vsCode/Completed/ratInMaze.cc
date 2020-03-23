

void print(int maze[][20], int n)
{
	for(int r = 0; r < n; r++)
	{
		for(int c = 0; c < n; c++)
		{
			if(maze[r][c] == 3)
				cout<<"1 ";
			else
				cout<<"0 ";
		}
	}
}

bool isvalid(int maze[][20], int n, int row, int col)
{
    if(row < 0 || row >= n || col < 0 || col >= n)
        return false;
    if(maze[row][col] == 0 || maze[row][col] == 3)
    	return false;
    return true;
}

void solve(int maze[][20], int n, int row, int col)
{
	if(row == n -1 && col == n - 1)
	{
		print(maze, n);
		return;
	}
	else
	{
		if(isvalid(maze, n, row + 1, col))
		{
			maze[row + 1][col] = 3;
			solve(maze, n, row + 1, col);
			maze[row + 1][col] = 1;
		}
		if(isvalid(maze, n, row, col + 1))
		{
			maze[row][col + 1] = 3;
			solve(maze, n, row, col + 1);
			maze[row][col + 1] = 1;
		}
		if(isvalid(maze, n, row - 1, col))
		{
			maze[row - 1][col] = 3;
			solve(maze, n, row - 1, col);
			maze[row - 1][col] = 1;
		}
		if(isvalid(maze, n, row, col - 1))
		{
			maze[row][col - 1] = 3;
			solve(maze, n, row, col - 1);
			maze[row][col -1] = 1;
		}
	}
}

void ratInAMaze(int maze[][20], int n){

	solve(maze, n, 0, 0);
}

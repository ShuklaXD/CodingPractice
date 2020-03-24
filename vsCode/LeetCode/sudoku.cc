class Solution {
public:

bool isValid(vector<vector<char>>& board, int row, int col, int val)
{
    for(int r = 0; r < 9 ; r++)
    {
        if(board[r][col] == val)
            return false;
    }
    for(int r = 0; r < 9 ; r++)
    {
        if(board[row][r] == val)
            return false;
    }
    int lr = (row / 3) * 3;
    int lc = (col / 3) * 3;
    
    for(int r = lr; r < lr + 3; r++)
    {
        for(int c = lc; c < lc + 3; c++)
        {
            if(board[r][c] == val)
                return false;
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<char>>& board){
    bool complete = false;
    
    for(int r = 0; r < 9; r++)
    {
        for(int c = 0; c < 9; c++)
        {
            if(board[r][c] == '.')
            {
                for(int i = 49; i <= 57; i++)
                {
                    if(isValid(board, r, c, i))
                    {
                        board[r][c] = i;
                        if(sudokuSolver(board))
                            return true;
                        board[r][c] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board);
    }
};
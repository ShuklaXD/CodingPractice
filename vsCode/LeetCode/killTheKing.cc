#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

/*
input size required time complexity 
n≤10 		O(n!) 
n≤20 		O(2^n) 
n≤500 		O(n^3) 
n≤5000 		O(n^2) 
n≤10^6		O(nlogn) or O(n) 
n is large	O(1) or O(logn)
*/

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/
vector<vector<int>> board;

bool canKill(vector<int> queen, vector<int> king)
{
    if(queen[0] == king[0])
    {
        for(int i = min(queen[1], king[1]) +1 ; i < max(queen[1], king[1]); i++)
        {
            if(board[queen[0]][i] == 1)
                return false;
        }
        return true;
    }
    if(queen[1] == king[1])
    {
        for(int i = min(queen[0], king[0]) +1 ; i < max(queen[0], king[0]); i++)
        {
            if(board[i][queen[1]] == 1)
                return false;
        }
        return true;
    }
    if(abs(queen[0] - king[0]) == abs(queen[1] - king[1]))
    {
        if(queen[0] > king[0])
        {
            if(queen[1] > king[1])
            {
                for(int i = king[0] + 1, j = king[1] +1; i < queen[0] && j < queen[1]; i++,j++)
                {
                    if(board[i][j] == 1)
                    {
                        return false;
                    }
                }
                    return true;
            }
            else
            {
                for(int i = king[0] + 1, j = king[1] - 1; i < queen[0] && j > queen[1]; i++,j--)
                {
                    if(board[i][j] == 1)
                    {
                        return false;
                    }
                }
                    return true;
            }
        }
        else
        {
                if(queen[1] > king[1])
                {
                for(int i = king[0] - 1, j = king[1] +1; i > queen[0] && j < queen[1]; i--,j++)
                {
                    if(board[i][j] == 1)
                    {
                        return false;
                    }
                }
                    return true;
                    
                }
            else
            {
                for(int i = king[0] - 1, j = king[1] -1; i > queen[0] && j > queen[1]; i--,j--)
                {
                    if(board[i][j] == 1)
                    {
                        return false;
                    }
                }
                    return true;
            }
        }
    }
    return false;
}

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    vector<vector<int>> res;
    board.resize(8, vector<int>(8, 0));
    for(auto pos : queens)
    {
        board[pos[0]][pos[1]] = 1;
    }
    board[king[0]][king[1]] = 2;
    
    for(auto p : queens)
    {
        if(canKill(p, king))
        {
            res.push_back(p);
        }
    }
    return res;
}


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;

    vector<vector<int>> queens = {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}};

    vector<int> king = {3,4};

    vector<vector<int>> res = queensAttacktheKing(queens, king);

    for(auto sd : res)
    {
        cout<<sd[0]<<" "<<sd[1]<<endl;
    }

    return 0;
}

//Backtracking
#include<bits/stdc++.h>
using namespace std;

bool isValidVertical(vector<vector<char>>& board, string s, int r, int c)
{
    for(int i = r; i < r + s.size(); i++)
    {
        if( (i > 9) || (i < 0))
            return false;
        else
        {
            if((board[i][c] == '-') || (board[i][c] == s[i - r]))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

bool isValidHorizontal(vector<vector<char>>& board, string s, int r, int c)
{
    for(int i = c; i < c + s.size(); i++)
    {
        if( (i > 9) || (i < 0))
            return false;
        else
        {
            if((board[r][i] == '-') || (board[r][i] == s[i - c]))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

bool setVertical(vector<vector<char>>& board, string s, int r, int c, bool* marker)
{
    for(int i = r; i < r + s.size(); i++)
    {
        if(board[i][c] == '-')
        {
            marker[i - r] = true;
            board[i][c] = s[i - r];
        }
        else if(board[i][c] == s[i - r])
        {
            marker[i - r] = false;
        }
    }
    return true;
}

bool resetVertical(vector<vector<char>>& board, string s, int r, int c, bool* marker)
{
    for(int i = r; i < r + s.size(); i++)
    {
        if(marker[i - r])
        {
            board[i][c] = '-';
        }
    }
    return true;
}

bool setHorizontal(vector<vector<char>>& board, string s, int r, int c, bool* marker)
{
    for(int i = c; i < c + s.size(); i++)
    {
        if(board[r][i] == '-')
        {
            marker[i - c] = true;
            board[r][i] = s[i - c];
        }
        else if(board[r][i] == s[i - c])
        {
            marker[i - c] = false;
        }
    }
    return true;
}

bool resetHorizontal(vector<vector<char>>& board, string s, int r, int c, bool* marker)
{
    for(int i = c; i < c + s.size(); i++)
    {
        if(marker[i - c])
        {
            board[r][i] = '-';
        }
    }
    return true;
}

bool crossword(vector<vector<char>>& board, vector<string>& words, int index)
{
    if(index == words.size())
        return true;
    for(int r = 0; r < 10; r++)
    {
        for(int c = 0; c < 10; c++)
        {
            if(isValidHorizontal(board, words[index], r, c))
            {
                bool* marker = new bool(words[index].size());
                setHorizontal(board, words[index], r, c, marker);
                if (crossword(board, words, index + 1))
                {
                    return true;
                }
                else
                {
                    resetHorizontal(board, words[index], r, c, marker);
                }
            }
            if(isValidVertical(board, words[index], r, c))
            {
                bool* marker = new bool(words[index].size());
                setVertical(board, words[index], r, c, marker);
                if (crossword(board, words, index + 1))
                {
                    return true;
                }
                else
                {
                    resetVertical(board, words[index], r, c, marker);
                }
            }
        }
    }
    return false;
}

int main() {

    vector<vector<char>> board(10, vector<char>(10, '.'));
    for(int r = 0; r < 10; r++)
        for(int c = 0; c < 10; c++)
            cin>>board[r][c];
    string line,word;
    vector<string> words;
    cin>>line;
    
    for(auto s: line)
    {
        if(s == ';')
        {
            words.push_back(word);
            word = "";
        }
        else
            word += s;
    }
    words.push_back(word);
    crossword(board, words, 0);
    for(int r = 0; r < 10; r++)
    {
        for(int c = 0; c < 10; c++)
            cout<<board[r][c];
        cout<<endl;
    }
}
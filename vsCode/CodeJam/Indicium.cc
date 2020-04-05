#include "bits/stdc++.h"

//ques 4
using namespace std;

bool valid(vector<vector<int>>& arr, int i, int  j, int n, int val)
{
    unordered_set<int> row, col;
    // for(int r = 0; r < n; r++)
    // {
    //     cout<<arr[i][r]<<" ";
    // }
    // cout<<endl;
    // for(int r = 0; r < n; r++)
    // {
    //     cout<<arr[r][j]<<" ";
    // }
    // cout<<endl;
    

    for(int r = 0; r < n; r++)
    {
        if(row.count(val) == 1 || col.count(val) == 1)
        {
            return false;
        }
        else
        {
            row.insert(arr[i][r]);
            col.insert(arr[r][j]);
        }
    }
    if(row.count(val) == 1 || col.count(val) == 1)
        return false;
    return true;
}

// use dp
bool backtrack(vector<vector<int>>& arr, int i, int  j, int k, vector<vector<vector<bool>>> dp)
{
    int n = arr.size();
    bool empty = false;
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            if(arr[r][c] == 0)
            {
                empty = true;
                for(int val = 1; val <= n; val++)
                {
                    if( valid(arr, r, c, n, val) )
                    {
                        arr[r][c] = val;
                        // cout<<"arr "<<r<<" "<<c<<" : "<<val<<endl;
                        if(!dp[r][c][val])
                        {
                            if(backtrack(arr, r, c, k, dp))
                                return true;
                            else
                            {
                                dp[r][c][val] = true;
                            }
                        }
                        arr[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    if(!empty)
    {
        int sum = 0;
        for(int r = 0; r < n; r++)
        {
            sum += arr[r][r];
        }
        if(sum != k)
            return false;
        cout<<" POSSIBLE "<<endl;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < n; c++)
            {
                cout<<arr[r][c]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    else
    {
        return false;
    }
}


void sums(vector<vector<int>>& res, int sum, int n, vector<int>& currSol, int index)
{
    if(index == n)
    {
        if(sum == 0)
        {
            res.push_back(currSol);
            return;
        }
        else
            return; 
    }
    
    for(int i = 1; i <= n; i++)
    {
        currSol[index] = i;
        sums(res, sum - i, n, currSol, index + 1);
        currSol[index] = 0;
    }
}

void ans(int n, int k)
{
    vector<vector<int>> grid(n, vector<int> (n,0));

    vector<vector<int>> sumTble;
    vector<int> tmp(n, 0);
    sums(sumTble, k, n, tmp, 0);
    vector<vector<vector<bool>>> dp(n , vector<vector<bool>>(n, vector<bool>(n + 1, false)));

    for(int  i = 0; i < sumTble.size(); i++)
    {
        for(int j = 0; j < n; j++)
        {
            grid[j][j] = sumTble[i][j];
        }
        if(backtrack(grid , 0 , 0, k, dp/*, 0*/))
            return;
    }

    // if(!backtrack(grid , 0 , 0, k/*, 0*/))B
    // {
    cout<<"IMPOSSIBLE"<<endl;
    // }
}

void solve(int i)
{
    int n,k;
    cin>>n>>k;
    
    cout<<"Case #"<<i<<": ";
    ans(n,k);
}

int main()
{
    int cases;
    cin>>cases;
    int i = 1;
    while(cases-->0)
    {
        solve(i++);
    }
    return 0;
}
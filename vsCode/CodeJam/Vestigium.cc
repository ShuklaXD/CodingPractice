#include "bits/stdc++.h"

using namespace std;

void ans(vector<vector<int>>& arr)
{
    int n = arr.size();
    unordered_set<int> cc;
    vector<unordered_set<int>> rc(n);
    vector<int> rows(n, 0);
    int c_count = 0, r_count = 0, sum = 0;
    for(int r = 0; r < n; r++)
    {
        bool done = false;
        for(int c = 0; c < n; c++)
        {
            if(r == c)
                sum+=arr[r][c];
            
            if(rc[c].count(arr[r][c]) == 1)
            {
                rows[c] = 1;
            }
            else
            {
                rc[c].insert(arr[r][c]);
            }
            if(cc.count(arr[r][c]) == 1  && !done)
            {
                done = true;
                c_count++;
                cc.clear();
            }
            else
            {
                cc.insert(arr[r][c]);
            }
        }
        cc.clear();
    }

    for(int i = 0; i < n; i++)
        r_count += rows[i];

    cout<<sum<<" "<<c_count<<" "<<r_count<<endl;
}

void solve(int i)
{
    int n;
    cin>>n;
    vector<vector<int>> grid(n, vector<int> (n,0));

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<"Case #"<<i<<": ";
    ans(grid);
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
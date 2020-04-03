/*

Alyona and Spreadsheet

During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
Now she has a table filled with integers. The table consists of n rows and m columns. By ai, j we will denote the integer located at the i-th row and the j-th column. We say that the table is sorted in non-decreasing order in the column j if ai, j ≤ ai + 1, j for all i from 1 to n - 1.
Teacher gave Alyona k tasks. For each of the tasks two integers l and r are given and Alyona has to answer the following question: if one keeps the rows from l to r inclusive and deletes all others, will the table be sorted in non-decreasing order in at least one column? Formally, does there exist such j that ai, j ≤ ai + 1, j for all i from l to r - 1 inclusive.
Alyona is too small to deal with this task and asks you to help!
Input
The first line of the input contains two positive integers n and m (1 ≤ n·m ≤ 100 000) — the number of rows and the number of columns in the table respectively. Note that your are given a constraint that bound the product of these two integers, i.e. the number of elements in the table.

Each of the following n lines contains m integers. The j-th integers in the i of these lines stands for ai, j (1 ≤ ai, j ≤ 109).

The next line of the input contains an integer k (1 ≤ k ≤ 100 000) — the number of task that teacher gave to Alyona.

The i-th of the next k lines contains two integers li and ri (1 ≤ li ≤ ri ≤ n).
Output
Print "Yes" to the i-th line of the output if the table consisting of rows from li to ri inclusive is sorted in non-decreasing order in at least one column. Otherwise, print "No".
Sample Input
5 4
1 2 3 5
3 1 3 2
4 5 2 3
5 5 3 2
4 4 3 4
6
1 1
2 5
4 5
3 5
1 3
1 5
Sample Output
Yes
No
Yes
Yes
Yes
No

*/

#include "bits/stdc++.h"

using namespace std;

int BruteForce()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n , vector<int>(m, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>grid[i][j];

    vector<vector<bool>> dp(n , vector<bool>(m, false));

    for(int i = 0; i < m; i++)
        dp[n-1][i] = true;
    
    for(int i = n - 2; i >= 0 ; i--)
    {
        for(int j = 0; j < m ; j++)
        {
            if( grid[i][j] <= grid[i+1][j] )
                dp[i][j] = true;
            else
                dp[i][j] = false;
        }
    }
    int q;
    cin>>q;
    while(q-->0)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;

        bool res = false;

        if(l == r)
        {
            cout<<"Yes"<<endl;
            continue;
        }

        vector<bool> ans(m , true);
        for(int i = l; i < r; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans[j] = ans[j] & dp[i][j];
            }
        }
        for(int j = 0; j < m; j++)
        {
            res = res | ans[j];
        }
        if(res)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;        
    }

    return 0;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> first(m, 0), second(m, 0);

    vector<int> dp1(m, 0), dp2(m, 0), row(n, 0);

    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>second[j];
            if( second[j] >= first[j])
                dp2[j] = dp1[j];
            else
                dp2[j] = i;
        }
        first = second;
        dp1 = dp2;
        int min = INT_MAX;
        for(int i = 0; i < m; i++)
            if(min > dp1[i])    min = dp1[i];
        row[i] = min;
    }

    int q;
    cin>>q;
    while(q-->0)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        if( row[r] <= l)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
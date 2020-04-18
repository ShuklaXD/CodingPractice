/* Shortest Subsequence
Send Feedback
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Sample Input :
babab
babba
Sample Output :
3

 */

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

#define sorted(a) sort(a.begin(), a.end())
#define atob(i,a,b) for (int i = a; i <= b; i++)
#define upton(i,n) for(int i = 0; i < n; i++)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/

int solver(string a, string b, vector<vector<int>>& dp)
{
    if(b.size() == 0)
        return 1;
    if(a.size() == 0)
        return INF;
    
    if(dp[a.size()][b.size()] != INF)
        return dp[a.size()][b.size()];

    int i = 0;
    bool found = false;
    for(; i < b.size() && !found; i++)
    {
        if(b[i] == a[0])
            found = true;
    }
    if(!found)
    {
        dp[a.size()][b.size()] = 1;
    }
    else
    {
        int without = solver(a.substr(1), b, dp);
        int with = solver(a.substr(1), b.substr(i), dp) + 1;
        dp[a.size()][b.size()] = min(with, without);    
    }
    return dp[a.size()][b.size()];
}

int solve(string a, string b)
{
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, INF));
    return solver(a,b,dp);
}

void solve()
{
    string a,b;
    cin>>a>>b;
    cout<<solve(a,b);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;

    // cin>>cases;

    while(cases-->0)
        solve();

    return 0;
}

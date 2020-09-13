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
bool solve(int i, string s, vector<vector<pair<bool,bool>>>& dp, int currState)
{
    int t = currState;
    int j = i;
    
    if(i == s.size())
    {
        if(currState == 0)
            return true;
        else
            return false;
    }
    
    if(dp[i][t].first)
        return dp[i][t].second;
    
    dp[i][t].first = true;
    
    for(; j<s.size(); j++)
    {
        if(s[j] == '*')
            break;
        if(s[j] == '(')
        {
            t++;
        }
        else
        {
            t--;
            if(t < 0)
            {
                dp[i][currState].second = false;
                return dp[i][currState].second;
            }
        }
    }
    if(j == s.size())
    {
        if(t == 0)
            dp[i][currState].second = true;   
        else
            dp[i][currState].second = false;
    }
    else
    {
        bool a = solve(j+1, s, dp, t+1);
        bool c = solve(j+1, s, dp, t);
        bool b = false;
        if(t-1>=0)
            b = solve(j+1, s, dp, t-1);
        dp[i][currState].second = (a | b) | c;
    }
    return dp[i][currState].second;
}

bool checkValidString(string s) {
    int sz = s.size();
    vector<vector<pair<bool,bool>>> dp(sz+1, vector<pair<bool,bool>>(sz+1, {false, false}));
    return solve(0, s, dp, 0);
}

void solve()
{
    string s;
    cin>>s;
    cout<<checkValidString(s)<<endl;
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

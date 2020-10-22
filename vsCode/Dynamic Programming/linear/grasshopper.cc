/*
Grasshopper lives in the teacher's room. It likes to jump on one dimensional checkerboard. The length of the board is n cells. To its regret, it can jump only on 1, 2, ..., k cells forward.

Once teachers wondered in how many ways a grasshopper can reach the last cell from the first one. Help them to answer this question.

Input
Two integers n and k (1 ≤ n ≤ 30, 1 ≤ k ≤ 10).

Output
Print the number of ways for grasshopper to leap from the first cell to the last.

Input example #1 content_copy
8 2
Output example #1 content_copy
21

*/#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define sortn(a) sort(a.begin(), a.end())
#define rep(n) for (int i = 0; i < n; i++)
#define forn(i,a,b) for (int i = a; i < b; i++)
#define deb(x) cout << #x << " : " << x << endl;
#define isBitSet(S, i) ((S >> i) & 1)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;
// int 2 * 1e9
// long long 9 * 1e18

void solve(int case_num)
{
    int n, k;
    cin>>n>>k;
    if(k > n)   k = n;
    vi dp(n+1 , 0);
    dp[0] = 1;
    for(int j = 1; j <= n; j++)
    {
        for(int i = 1; i <= k && j-i >= 0; i++)
        {
            dp[j] += dp[j-i];
        }
    }
    cout << dp[n-1] << endl;
}

int main() 
{
    #ifdef LOCAL_PROJECT
    freopen("/home/shubham/CodingPractice/vsCode/input.txt", "r", stdin);
    freopen("/home/shubham/CodingPractice/vsCode/output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    // cin>>cases;
    forn(i,0,cases)
    {
        solve(i);
    }
    return 0;
}

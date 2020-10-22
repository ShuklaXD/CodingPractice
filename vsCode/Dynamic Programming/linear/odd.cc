#include <bits/stdc++.h>

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
    int n;  cin>>n;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    int numodd = 0;
    if(arr[0].first&1)  numodd++;
    if(arr[0].second&1) numodd++;
    dp[0][0] = numodd;
    dp[0][1] = 2-numodd;
    for(int i = 1; i < n; i++)
    {
        int numodd = 0;
        if(arr[i].first&1)  numodd++;
        if(arr[i].second&1) numodd++;
        dp[i][0] = numodd*dp[i-1][1] + (2-numodd)*dp[i-1][0];
        dp[i][1] = numodd*dp[i-1][0] + (2-numodd)*dp[i-1][1];
    }
    cout<<dp[n-1][0]<<endl;
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

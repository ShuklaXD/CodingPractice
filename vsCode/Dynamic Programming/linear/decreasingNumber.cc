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

int solve(int n)
{
    if(n == 1)  return 0;
    if(n == 2)  return 1;
    if(n == 3)  return 1;

    vi dp(n+1, INT_MAX);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i = 4; i <= n; i++)
    {
        int one, two, three;
        one = two = three = INT_MAX;
        if(i % 3 == 0)  three = dp[i/3];
        if(i % 2 == 0)  two = dp[i/2];
        one = dp[i-1];
        dp[i] = 1 + min(one, min(two, three));
    }
    return dp[n];
}

int main() 
{
    #ifdef LOCAL_PROJECT
    freopen("/home/shubham/CodingPractice/vsCode/input.txt", "r", stdin);
    freopen("/home/shubham/CodingPractice/vsCode/output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int line;
    while(cin>>line)
    {
        // cout<<line<<endl;
        cout<<solve(line)<<endl;
    }
    return 0;
}

/*
Nails
Some nails are hammered on a straight plank. Any two nails can be joined by a thread. Connect some pairs of nails with a thread, so that to each nail will be tied with at least one thread, and the total length of all threads will be minimal.

Input
The first line contains the number of nails n (1 ≤ n ≤ 100). The next line contains n numbers - the coordinates of all the nails (non-negative integers not exceeding 10000).

Output
Print the minimum total length of all threads.

Input example #1 content_copy
5
4 10 0 12 2
Output example #1 content_copy
6
*/
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

vi dp;
int join(int i, vi &arr, int &n)
{
    if(i >= n)  return 0;
    if(dp[i] != INT_MAX)    return dp[i];
    int f = INT_MAX;
    if(i < n-1)
        f = arr[i+1]-arr[i] + join(i+2, arr, n);
    dp[i] = min(f, arr[i] - arr[i-1] + join(i+1, arr, n));
    return dp[i];
}
void solve(int case_num)
{
    int n;  cin>>n;
    vi arr(n);   
    for(int &a : arr)   cin>>a;
    if(n == 1){
        cout<<0<<endl;
        return;
    }
    sortn(arr);
    // vector<pair<int, int>> dp(n+1, {0,INT_MAX});
    dp.resize(n+1, INT_MAX);
    dp[0] = arr[1] - arr[0];
    cout << dp[0] + join(2, arr, n) << endl;
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

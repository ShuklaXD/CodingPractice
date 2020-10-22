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

void fill(int i, vi &re, int n, int &ans)
{
    if(i == n)
    {
        ans++;
        return;
    }
    if(i < 2)
    {
        re[i] = 0;
        fill(i+1, re, n, ans);
        re[i] = 1;
        fill(i+1, re, n, ans);
    }
    else
    {
        if(re[i-1] == re[i-2])
        {
            re[i] = re[i-1]^1;
            fill(i+1, re, n, ans);
        }else
        {
            re[i] = 0;
            fill(i+1, re, n, ans);
            re[i] = 1;
            fill(i+1, re, n, ans);
        }
    }
}

void solve(int case_num)
{
    int n;  cin>>n;
    vector<int> re(n, 0);
    int ans = 0;
    fill(0,re,n,ans);
    cout<<ans<<endl;
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

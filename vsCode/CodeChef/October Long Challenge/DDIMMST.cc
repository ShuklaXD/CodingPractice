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
    int n,d;
    cin>>n>>d;
    int points[n][d];
    rep(n)
        forn(j,0,d) cin>>points[i][j];
    
    vector<vector<int>> weights(n, vector<int>(n, 0));
    
    vector<bool> vis(n, false);
    int cnt = 0, nn = 0;
    ll ret = 0;
    while(cnt < n-1)
    {
        vis[nn] = true;
        int ms = 0, nxt = -1;
        forn(j, 0, n)
        {
            if(vis[j])  continue;
            int sum = weights[nn][j];
            if(sum==0)
            {
                forn(k, 0, d)
                    sum += abs(points[nn][k] - points[j][k]);

                weights[nn][j] = weights[j][nn] = sum;
            }
            if(ms < sum)
            {
                ms = sum;
                nxt = j;
            }
        }
        ret+=ms;
        nn = nxt;
        cnt++;
    }
    cout << ret << endl;
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

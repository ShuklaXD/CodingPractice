#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define vsort(a) sort(a.begin(), a.end())
#define sizeOf(a) a.size()

#define For(i,a,b) for (int i = a; i < b; i++)
#define deb(x) cout << #x << " : " << x << endl;
#define isBitSet(S, i) ((S >> i) & 1)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;


void solve()
{
    int a,b,c,d,n,m,k;
    cin>>n>>k;
    m = INT_MAX;
    vector<int> arr(n, 0);
    For(i,0,n)  
    {
        cin>>arr[i];
        if(arr[i] < m)
        {
            m = arr[i];
            c = i;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == c)
        {
            continue;
        }
        ans += (k - arr[i]) / m;
        int t = (k - arr[i]) % m;
    }
    cout<<ans << endl;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    cin>>cases;

    For(i,0,cases)
    {
        // cout << "Case #"<<i<<": ";
        solve();
        // cout <<"\n"[i==cases-1];
    }
    return 0;
}

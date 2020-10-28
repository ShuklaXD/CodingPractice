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

#define forn(i,a,b) for (int i = a; i < b; i++)
#define deb(x) cout << #x << " : " << x << endl;
#define isBitSet(S, i) ((S >> i) & 1)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;


void solve()
{
    int a,b,c,d,n,m,k;
    cin>>n>>m;
    bool sym = false;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b>>c>>d;
        if(b == c)
            sym = true;
    }
    if(m&1 || !sym)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    cin>>cases;

    forn(i,0,cases)
    {
        solve();
    }
    return 0;
}

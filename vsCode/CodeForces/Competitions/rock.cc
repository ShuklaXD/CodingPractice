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
    int n;
    cin>>n;
    int ra,sa,pa,rb,sb,pb;
    cin>>ra>>sa>>pa>>rb>>sb>>pb;
    int max = 0, mmin = 0;

    int t1 = ra - (rb+pb);
    if(t1 > 0)
        mmin+=t1;
    int t2 = sa - (sb+rb);
    if(t2 > 0)
        mmin+=t2;
    int t3 = pa - (pb+sb);
    if(t3 > 0)
        mmin+=t3;
    
    // if(ra > sb)
        max += min(sb,ra);
    // if(sa > pb)
        max += min(pb,sa);
    // if(pa > rb)
        max += min(rb,pa);

    cout<<mmin<<" "<<max<<endl;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    // cin>>cases;

    forn(i,0,cases)
    {
        solve();
    }
    return 0;
}

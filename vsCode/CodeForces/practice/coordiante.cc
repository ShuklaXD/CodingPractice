#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long double ld;
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
    ll x, y;
    cin>>x>>y;
    ll c1,c2,c3,c4,c5,c6;
    cin>>c1>>c2>>c3>>c4>>c5>>c6;
    ll cost = 0;    
    int vp = min(c2, c1+c3);
    int vn = min(c5, c6+c4);
    int hp = min(c6, c1+c5);
    int hn = min(c3, c2+c4);
    if(x < 0 && y < 0 && c4 <= c3 + c5)
    {
        int step = min(-x, -y);
        x+= step;
        y+= step;
        cost += c4*step;
    }
    if(x > 0 && y > 0 && c1 <= c2 + c6)
    {
        int step = min(x, y);
        x-= step;
        y-= step;
        cost += c1*step;
    }
    if(x > 0)
    {
        cost += hp*x;
        x = 0;
    }
    if(x < 0)
    {
        cost -= hn*x;
        x = 0;
    }
    if(y > 0)
    {
        cost += vp*y;
        y = 0;
    }
    if(y < 0)
    {
        cost -= vn*y;
        y = 0;
    }
    cout<<cost<<endl;
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
    cin>>cases;
    forn(i,0,cases)
    {
        solve(i);
    }
    return 0;
}

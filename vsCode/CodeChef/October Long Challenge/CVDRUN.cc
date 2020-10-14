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
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    vector<bool> infected(n, false);
    infected[x] = true;
    int next = x;
    if(x == y)
    {
        cout<<"YES"<<endl;
        return;
    }
    while(true)
    {
        // cout<<next << " ";
        next = (next + k) % n;
        if(next == y)
        {
            cout<<"YES"<<endl;
            return;
        }
        else if(infected[next])
        {
            cout<<"NO"<<endl;
            return;
        }
        else
        {
            infected[next] = true;
        }
    }
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

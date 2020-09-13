#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vp;

#define sv(a) sort(a.begin(), a.end())
#define sz(a) a.size()

#define foreach(i,a,b) for (int i = a; i <= b; i++)
#define fo(i,n) for (int i = 0; i < n; i++)
#define deb(x) cout << #x << x << endl;

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/
int dijkstra(vector<vector<pair<int, int>>> &r, vector<unordered_set<int>> &stop){
    
}

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> routes(n+1);
    //  routes[src] = {dest, cost}
    vector<unordered_set<int>> stop(n+1);

    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        routes[a].push_back(make_pair(b,c));
    }

    for(int i = 1; i <= n; ++i){
        int k;
        cin>>k;
        for(int j = 0; j < k; ++j){
            int tmp;
            cin>>tmp;
            stop[i].insert(tmp);
        }
    }

}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;

    // cin>>cases;

    while(cases-->0)
        solve();

    return 0;
}

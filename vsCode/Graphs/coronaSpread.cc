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

int floydWarshall(vector<vi> &minPath, vi &hots, int x){

    int vx = minPath.size();

    for(int i = 0; i < vx; ++i){
        minPath[i][i] = 0;
    }
    
    for(int vertex = 1; vertex < vx; vertex++){
        for(int i = 1; i < vx; ++i){
            for(int j = 1; j < vx; ++j){
                minPath[i][j] = min(minPath[i][j], minPath[i][vertex] + minPath[vertex][j]);
            }
        }
    }
    
    // cout<<"MinPaths "<<endl;
    // for(int i = 1; i < vx; i++){
    //     for(int j = 1; j < vx; j++){
    //         cout<<minPath[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int cnt = 0;
    for(int i = 1; i < vx; ++i){
        bool isEp = true;
        for(int h : hots){
            if(minPath[i][h] > x){
                isEp = false;
                break;
            }
        }
        if(isEp){
            cnt++;
            // cout<<"Epicenter : "<<i<<endl;
        }
    }
    return cnt;
}

void solve()
{
    int n,h,x;
    cin>>n>>h>>x;

    vector<int> hotspot(h);
    vector<vector<int>> route(n+1, vi(n+1, INF));
    for(int i = 0; i < h; ++i)
        cin>>hotspot[i];
    
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin>>a>>b;
        route[a][b] = 1;
        route[b][a] = 1;    //bi-directional route
    }
    cout<<floydWarshall(route, hotspot, x)<<endl;
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

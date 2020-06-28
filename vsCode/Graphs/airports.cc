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
int cc(int st, int acost, vector<vi> &route, vector<bool> &vi, int &aps){
    vi[st] = true;
    queue<int> que;
    que.push(st);
    while(!que.empty()){
        int curr = que.front();
        que.pop();
        if(!vi[curr]){
            for(int i = 0; i < route[curr].size(); i++){
                if(!vi[route[curr][i]]){
                    que.push(route[curr][i]);
                }
            }
        }
    }
}

void solve()
{
    int n,m,a;
    cin>>n>>m>>a;
    vector<vi> route(n+1, vi(n+1, INT_MAX));
    int s,d,c;
    for(int i = 0; i < m; i++){
        cin>>s>>d>>c;
        route[s][d] = min(route[s][d], c);
        route[d][s] = route[s][d];
    }
    int cost = 0, aps = 0;
    vector<bool> vis(n+1, false);
    for(int i = 1; i <=n; i++){
        if(!vis[i]){
            int ap = 0;
            int cthis = cc();
            cost+=cthis;
            aps += (ap < 2)?1:ap-1;
        }
    }
    cout<<cost<<" "<<aps;
}

int costmetric(){

    int cases;
    cin>>cases;
    
    for(int i = 0; i < cases; ++i){
    
        int v,e,a;
        cin>>v>>e>>a;
        
        vector<map<int,int>> route(v+1);
        
        for(int i = 0; i < e; ++i){
            int v1,v2,c;
            cin>>v1>>v2>>c;
            
            if(route[v1].find(v2) == route[v1].end())
            {
                route[v1][v2] = c;
                route[v2][v1] = c;
            }
            else{
                route[v1][v2] = min(route[v1][v2], c);
                route[v2][v1] = min(route[v2][v1], c);
            }
        }
        
        vector<bool> visited(v+1, false);

        for(int i= 0; i <=v; ++i){
            
        }
    }
    
	return 0;
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<endl;
    }
}

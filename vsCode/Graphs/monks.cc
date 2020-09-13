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

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    
    for(int i = 0; i < t; i++){
        int n,m;
        cin>>n>>m;
        int a,b;
        
        vector<vi> ed(n+1);
        for(int j = 0; j < m; ++j){
            cin>>a>>b;
            ed[a].push_back(b);
            ed[b].push_back(a);
        }
        vi cost(n+1, INT_MAX);
        cost[1] = 0;
        queue<int> que;
        que.push(1);
        bool found = false;
        vector<bool> visited(n+1, false);
        while(!que.empty() && !found){
            int cur = que.front();
            que.pop();
            if(cur == n){
                found = true;
                break;
            }
            for(int j = 0; j < ed[cur].size(); ++j){
                if(!visited[ed[cur][j]]){
                    visited[ed[cur][j]] = true;
                    cost[ed[cur][j]] = min(cost[cur]+1, cost[ed[cur][j]]);
                    que.push(ed[cur][j]);
                }
            }
        }
        cout<<cost[n]<<endl;
    }
	return 0;
}

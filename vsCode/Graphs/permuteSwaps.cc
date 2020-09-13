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
#define deb(x) cout << #x << " " << x << endl;

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/
void dfs(vector<int>* edges, int n, int start, vector<bool>& visited, unordered_set<int>& comps)
{
    comps.insert(start);
    visited[start] = true;
    for(int i = 0; i < edges[start].size(); i++)
    {
        if(visited[edges[start][i]])
            continue;
        dfs(edges, n, edges[start][i], visited, comps);
    }
}

void getConnectedComponentsDFS(vector<int>* edges, int n,vector< unordered_set<int> > &connectedComponents)
{
    vector<bool> visited(n, false);
    unordered_set<int> comps;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(edges, n, i, visited, comps);
            connectedComponents.push_back(comps);
            comps.clear();
        }
    }
}

bool solve()
{
    int n,m;
    cin>>n>>m;
    int p[n], q[n];
    fo(i,n)
        cin>>p[i];
    fo(i,n)
        cin>>q[i];
    
    vector<int> edges[n];
    fo(i,m)
    {
        int s,e;
        cin>>s>>e;
        edges[s-1].push_back(e-1);
        edges[e-1].push_back(s-1);
    }
    vector< unordered_set<int> > connectedComponents;

    getConnectedComponentsDFS(edges, n,connectedComponents);

    for(auto pset : connectedComponents)
    {
        unordered_set<int> valueP;
        for(int a : pset)
        {
            valueP.insert(p[a]);
        }
        for(int a : pset)
        {
            if(valueP.find(q[a])==valueP.end())
            {
                return false;
            }
        }
    }
    return true;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;

    cin>>cases;

    while(cases-->0)
    {
        cout<<(solve()?"YES":"NO")<<endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

/*
input size required time complexity 
n≤10 		O(n!) 
n≤20 		O(2^n) 
n≤500 		O(n^3) 
n≤5000 		O(n^2) 
n≤10^6		O(nlogn) or O(n) 
n is large	O(1) or O(logn)
*/

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/
void dfs(vector<vector<bool>>& edges, int n, int start, vector<bool>& visited, vector<int>& comps)
{
    comps.push_back(start);
    visited[start] = true;
    for(int i = 0; i < n; i++)
    {
        if(i == start)
            continue;
        if(edges[start][i])
        {
            if(visited[i])
                continue;
            dfs(edges, n, i, visited, comps);
        }
    }
}

void bfs(vector<vector<bool>>& edges, int n, int start, vector<bool>& visited, vector<int>& comps)
{
    // cout<<"bfs"<<endl;
    queue<int> que;
    que.push(start);
    visited[start] = true;

    while(!que.empty())
    {
        int curr = que.front();
        que.pop();

        comps.push_back(curr);

        for(int i = 0 ; i < n; i++)
        {
            if(i == curr)
                continue;
            
            if(edges[curr][i] && (!visited[i]))
            {
                que.push(i);
                visited[i] = true;
            }
        }
    }
}

void getConnectedComponentsBFS(vector<vector<bool>> edges, int n)
{
    vector<bool> visited(n, false);
    vector<vi> components;
    vi comps;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            bfs(edges, n, i, visited, comps);
            components.push_back(comps);
            comps.clear();
        }
    }
    for(auto vec : components)
    {
        for(int t : vec)
        {
            cout<<t<<" ";
        }
        cout<<endl;
    }
}

void getConnectedComponentsDFS(vector<vector<bool>> edges, int n)
{
    vector<bool> visited(n, false);
    vector<vi> components;
    vi comps;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(edges, n, i, visited, comps);
            components.push_back(comps);
            comps.clear();
        }
    }
    cout<<components.size()<<endl;
}

void solve()
{
    int n,e;
    cin>>n>>e;
    vector<vector<bool>> edges(n, vector<bool>(n, false));

    int f,s;
    for(int i = 0; i < e; ++i)
    {
        cin>>f>>s;
        edges[f-1][s-1] = true;
        edges[s-1][f-1] = true;
    }

    getConnectedComponentsDFS(edges, n);
    // getConnectedComponentsBFS(edges, n);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;

    cin>>cases;

    while(cases-->0)
        solve();

    return 0;
}

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
void dfs(vector<vector<bool>>& edges, int n, int start, vector<bool>& visited)
{
    cout<<start<<endl;
    visited[start] = true;
    for(int i = 0; i < n; i++)
    {
        if(i == start)
            continue;
        if(edges[start][i])
        {
            if(visited[i])
                continue;
            dfs(edges, n, i, visited);
        }
    }
}

void bfs(vector<vector<bool>>& edges, int n, int start, vector<bool>& visited)
{
    // cout<<"bfs"<<endl;
    queue<int> que;
    que.push(start);
    visited[start] = true;

    while(!que.empty())
    {
        int curr = que.front();
        que.pop();

        cout<<curr<<" ";

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

void printBFS(vector<vector<bool>> edges, int n)
{
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            bfs(edges, n, i, visited);
    }
}

void printDFS(vector<vector<bool>> edges, int n)
{
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            dfs(edges, n, i, visited);
    }
}

bool hasPathDFS(vector<vector<bool>>& edges, int n, int v1, int v2, vector<bool>& visited)
{
    visited[v1] = true;
    for(int i = 0; i < n; i++)
    {
        if(i == v1)
            continue;
        if(edges[v1][i])
        {
            if(i == v2)
                return true;
            if(visited[i])
                continue;
            if(hasPathDFS(edges, n, i, v2, visited))
                return true;
        }
    }
    return false;
}

bool getsPathDFS(vector<vector<bool>>& edges, int n, int v1, int v2, vector<bool>& visited)
{
    visited[v1] = true;
    for(int i = 0; i < n; i++)
    {
        if(i == v1)
            continue;
        if(edges[v1][i])
        {
            if(i == v2)
            {
                cout<<v2<<" "<<v1<<" ";
                return true;
            }
            if(visited[i])
                continue;
            if(getsPathDFS(edges, n, i, v2, visited))
            {
                cout<<v1<<" ";
                return true;
            }
        }
    }
    return false;
}

bool getsPathBFS(vector<vector<bool>>& edges, int n, int v1, int v2, vector<bool>& visited)
{
    queue<int> que;
    que.push(v1);
    map<int, int> parent;
    while(!que.empty())
    {
        int curr = que.front();
        que.pop();

        for(int i = 0 ; i < n; i++)
        {
            if(i == curr)
                continue;
            if(edges[curr][i] && !visited[i])
            {
                if(i == v2)
                {
                    int tmp = curr;
                    cout<<i<<" "<<curr<<" ";
                    while(tmp != v1)
                    {
                        tmp  = parent[tmp];
                        cout<<tmp<<" ";
                    }
                    return true;
                }
                parent[i] = curr;
                visited[i] = true;
                que.push(i);
            }
        }
    }
    return false;
}

void hasPath(vector<vector<bool>>& edges, int n)
{
    int v1, v2;
    cin>>v1>>v2;
    if(v1 == v2)
    {
        cout<<v2<<endl;
        return;
    }
    vector<bool> visited(n, false);

    // cout<<( hasPathDFS(edges, n, v1, v2,visited) ? "true" : "false" ) <<endl;
    // getsPathDFS(edges, n, v1, v2,visited);
    getsPathBFS(edges, n, v1, v2, visited);
}

bool isConnected(vector<vector<bool>>& edges, int n)
{
    vector<bool> visited(n, false);
    queue<int> que;
    que.push(0);
    visited[0] = true;

    while(!que.empty())
    {
        int curr = que.front();
        que.pop();

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
    for(bool b : visited)
        if(!b)  return false;
    return true;
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
        edges[f][s] = true;
        edges[s][f] = true;
    }

    // printDFS(edges , n);
    // printBFS(edges , n);
    // hasPath(edges, n);
    cout<< ((isConnected(edges, n)) ? "true" : "false" )<<endl;
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

/*

Dijkstra's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5

*/

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

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/
class dijkstra
{
    public:
    int v,e;
    vector<vi> edges;   //adjency matrix
    vi dist;    //min distance from 0 to i
    vector<bool> visited;   //has the element been visited before

    dijkstra()
    {
        cin>>v>>e;
        edges.resize(v , vi(v, 0));
        fo(i, e)
        {
            int st, en, w;
            cin>>st>>en>>w;
            edges[st][en] = w;
            edges[en][st] = w;  //undirected
        }

        dist.resize(v, INT_MAX);
        visited.resize(v, false);
        dist[0] = 0;
    }

    void solve()
    {
        int src = 0;

        for(int i = 0; i < v; i++)
        {
            int min = INT_MAX;
            for(int ti = 0; ti < v; ti++)
            {
                if(!visited[ti])
                {
                    if(min > dist[ti])
                    {
                        min = dist[ti];
                        src = ti;
                    }
                }
            }

            visited[src] = true;
            for(int j = 0; j < v; j++)
            {
                if(!visited[j] && edges[src][j] && (dist[j] > dist[src]+edges[src][j]))
                {
                    dist[j] = dist[src]+edges[src][j];
                }
            }
        }

        for(int i = 0; i < v; i++)
        {
            cout<< i << " " << dist[i] << endl;
        }
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    dijkstra dj;
    dj.solve();
    return 0;
}

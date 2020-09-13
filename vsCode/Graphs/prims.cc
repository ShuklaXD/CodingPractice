/*
Prim's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5

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
class prims
{
    public:
    int v,e;
    vector<vi> edges;   //adjency matrix
    vi parent;      //parent of vertex i is parent[i]
    vi cost;         //cost for this vertex
    vector<bool> visited;   //has the element been visited before

    prims()
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

        parent.resize(v, -1);   //no-one has valid parent
        cost.resize(v, INT_MAX);     //cost for all vertices is max
        visited.resize(v, false);   //none of the vertices are visited
        cost[0] = 0;     //let's start from vertex 0 so its starting cost is 0
    }

    int getMinIndex()   //return minimum cost vertex possible
    {
        int minV = -1, min = INF;
        for(int i = 0; i < v; i++)
        {
            if(!visited[i]) //for all non visited vertices
            {
                if(min > cost[i])   //if cost is min update minV index
                {
                    min = cost[i];
                    minV = i;
                }
            }
        }
        return minV;
    }

    void solve()
    {
        for(int i = 0; i < v-1;i++)
        {
            int minV = getMinIndex();   //find next minimum cost unvisited vertex
            visited[minV] = true;

            for(int j = 1; j < v; ++j)
            {
                if(edges[minV][j]!=0 && !visited[j])    //for every unvisited neighbour of curr vertex
                {
                    if(cost[j] > edges[minV][j])    //if its cost is greater than the cost to reach from current vertex update the cost
                    {
                        parent[j] = minV;       //if the minimum cost is from current vertex then this will become its parent
                        cost[j] = edges[minV][j];
                    }
                }
            }
        }

        for(int i = 1; i < v; i++)
        {
            cout<<min(i, parent[i])<<" "<<max(i, parent[i])<<" "<<cost[i]<<endl;
        }
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    prims p;
    p.solve();
    return 0;
}

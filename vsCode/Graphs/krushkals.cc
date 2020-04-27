/*
Kruskal's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
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
class krushkals
{
    public:
    int v, e;
    vi parentDir;   //parent of vertex i is parent[i]
    vector<pair<int, pi>> edges;    //adjency list based on weights
    vector<pair<int, pi>> mst;      //minimim spanning tree

    krushkals(int vertices, int eds)
    {
        v = vertices;
        e = eds;
        edges.resize(e);
        int v1,v2,w;
        fo(i, e)
        {
            cin>>v1>>v2>>w;
            edges[i] = { w, {min(v1,v2), max(v1,v2)}};
        }

        parentDir.resize(v);
        fo(i, v)
            parentDir[i] = i;

    }

    bool unionFind(int v1, int v2)  //check if they are in same component or not
    {
        if(parentDir[v1] == parentDir[v2])  //if they have same parent
            return false;
        else
        {
            int goner = parentDir[v2];  //all vertices with parent p2 will now have parent as p1
            for(int i = 0; i < v; i++)
            {
                if(parentDir[i] == goner)
                    parentDir[i] = parentDir[v1];
            }
            return true;
        }
    }

    void solve()
    {
        sort(edges.begin(), edges.end());

        int mst_edges = 0;
        for(int i = 0; mst_edges < v-1; i++)
        {
            if(unionFind(edges[i].second.first, edges[i].second.second))    //find next min weight unconnected edge
            {
                mst_edges++;
                mst.push_back(edges[i]);
            }
        }
        
        for(int i = 0; i < v-1; i++)
        {
            cout<<mst[i].second.first<<" "<<mst[i].second.second<<" "<<mst[i].first<<endl;
        }
    }
};


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v,e;
    cin>>v>>e;
    krushkals k(v,e);
    k.solve();
    return 0;
}

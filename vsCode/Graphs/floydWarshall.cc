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
#define deb(x) cout << #x << endl;

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/
class floyd
{
    public:
    int v,e;
    vector<vi> edges, minPath;   //adjency matrix

    floyd()
    {
        cin>>v>>e;
        edges.resize(v+1, vi(v+1, 0));

        for(int i = 0; i < e; ++i)
        {
            int st,en,w;
            cin >> st >> en >> w;
            edges[st][en] = w;
            edges[en][st] = w;
        }
    }

    void printMinPaths()
    {
        cout<<"Minimum Cost Paths : "<<endl;
        for(int i = 1; i <= v; i++){
            for(int j = 1; j <= v; ++j){
                cout<<minPath[i][j]<<"\t";
            }
            cout<<endl;
        }
    }

    void getMinPaths()
    {
        minPath = edges;
        for(int i = 1; i <= v; i++){
            for(int j = 1; j <= v; ++j){
                if(edges[i][j] == 0)
                    minPath[i][j] = INF;
                if(i == j)
                    minPath[i][i] = 0;
            }
        }

        for(int vertex = 1; vertex <= v; vertex++){
            for(int i = 1; i <= v; i++){
                for(int j = 1; j <= v; ++j){
                    minPath[i][j] = min(minPath[i][j], minPath[i][vertex]+minPath[vertex][j]);
                }
            }
        }
        printMinPaths();
    }
};

void solve()
{
    floyd f;
    f.getMinPaths();
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

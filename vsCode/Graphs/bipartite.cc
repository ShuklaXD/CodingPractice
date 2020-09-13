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
#define rows(e) e.size()
#define cols(e) e[0].size()

#define foreach(i,a,b) for (int i = a; i <= b; i++)
#define fo(i,n) for (int i = 0; i < n; i++)
#define deb(x) cout << #x << " " << x << endl;

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/
class graph{
    public:
    int v,e;

    vector<vi> adj;
    graph(){
        cin>>v>>e;
        int src,dest;

        adj.resize(v);

        fo(i,e){
            cin>>src>>dest;
            adj[src-1].push_back(dest-1);
            // adj[dest-1].push_back(src-1);
        }
    }

    bool isbitartie(){
        unordered_set<int> domain[2];
        queue<pair<int,int>> que;
        que.push(make_pair(0, 0));
        domain[0].insert(0);

        int dom = 0;

        while(!que.empty()){
            pair<int, int> curr = que.front();
            que.pop();

            int alt = (curr.second + 1) % 2;

            for( int i = 0; i < adj[curr.first].size(); ++i ){
                int &dest = adj[curr.first][i];
                //check in other set
                if(domain[curr.second].count(dest))
                    return false;
                
                if(domain[alt].count(dest))
                    continue;

                domain[alt].insert(dest);
                que.push(make_pair(dest, alt));
            }
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases;
    cin>>cases;
    while(cases-->0){
        graph g;
        cout<<(g.isbitartie()?"Bipartite":"Not Bipartite")<<endl;
    }
}

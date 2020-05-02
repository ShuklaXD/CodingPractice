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
class graph{
    public:
    int v,e;

    vector<vi> adj;
    vector<set<int>> paths;
    
    vector<bool> visited;

    graph(){
        cin>>v;
        if(v==0)
            exit(0);
        cin>>e;
        int src,dest;
        
        adj.resize(v);
        visited.resize(v, false);

        fo(i,e){
            cin>>src>>dest;
            adj[src-1].push_back(dest-1);
        }
        paths.resize(v);
    }

    void dfsPush(int src, set<int> &st){
        visited[src] = true;
        for(int i = 0; i < adj[src].size(); ++i){
            if(!visited[adj[src][i]])
                dfsPush(adj[src][i], st);
        }
        st.insert(src);
    }


    void getNumScc(){
        set<int> res;
        set<int> st;
        int top = 0;
        for(int i =0; i < v; ++i){
            st.clear();
            visited.clear();
            visited.resize(v, false);
            dfsPush(i, st);
            paths[i] = st;
        }

        for(int src = 0; src < v; ++src){

            bool valid = true;
            for(int dst : paths[src]){
                //path bw i and paths[i]
                //check if i is in list of tpath[path[i]]
                bool found = false;
                for(int rev : paths[dst]){
                    if(rev == src){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    valid = false;
                    break;
                }
            }
            if(!valid){
                continue;
            }
            else{
                res.insert(src);
            }
        }
        if(res.empty()){
            cout<<endl;
        }
        else{
            for(int r : res){
                cout<<r+1<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;
    // cin>>cases;
    while(cases){
        graph g;
        g.getNumScc();
    }
}

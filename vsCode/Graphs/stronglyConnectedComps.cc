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
    vector<vi> paths;
    
    vector<bool> visited;

    graph(){
        cin>>v>>e;
        int src,dest;
        
        adj.resize(v);
        visited.resize(v, false);

        fo(i,e){
            cin>>src>>dest;
            adj[src-1].push_back(dest-1);
        }
    }

    void dfsPush(int src, stack<int> &st){

        visited[src] = true;

        for(int i = 0; i < adj[src].size(); ++i){
            if(!visited[adj[src][i]])
                dfsPush(adj[src][i], st);
        }
        st.push(src);
    }

    vector<vi> getTranspose(){
        vector<vi> transpose(v);
        for(int i = 0; i < v; ++i){
            for(int j = 0; j < adj[i].size(); ++j){
                transpose[adj[i][j]].push_back(i);
            }
        }
        return transpose;
    }

    void dfsPop(int src, vector<vi> &trans, unordered_set<int> &tmp){
        visited[src] = true;
        tmp.insert(src);
        for(int i = 0; i < trans[src].size(); ++i){
            if(!visited[trans[src][i]])
                dfsPop(trans[src][i], trans, tmp);
        }
    }

    vector<unordered_set<int>> getscc(stack<int> &st){

        vector<vi> transpose = getTranspose();
        visited.clear();
        visited.resize(v, false);
        vector<unordered_set<int>> comps;
        unordered_set<int> tmp;

        while(!st.empty()){
            int src = st.top();
            st.pop();
            if(!visited[src]){
                tmp.clear();
                dfsPop(src, transpose, tmp);
                comps.push_back(tmp);
            }
        }
        return comps;
    }

    int getNumScc(){
        stack<int> st;
        int top = 0;
        for(int i =0; i < v; ++i){
            if(!visited[i]){
                dfsPush(i, st);
                
                for(int i = st.size(); i >= top; --i){
                    
                }
            }
        }
        vector<unordered_set<int>> ans = getscc(st);
        return ans.size();
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
        cout<<g.getNumScc()<<endl;
    }
}

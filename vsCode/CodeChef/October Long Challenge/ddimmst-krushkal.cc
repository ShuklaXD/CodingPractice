#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define sortn(a) sort(a.begin(), a.end())
#define rep(n) for (int i = 0; i < n; i++)
#define forn(i,a,b) for (int i = a; i < b; i++)
#define deb(x) cout << #x << " : " << x << endl;
#define isBitSet(S, i) ((S >> i) & 1)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;
// int 2 * 1e9
// long long 9 * 1e18
struct SubSet 
{
    int parent, rank;
};

vector<SubSet> parentDir;   //parent of vertex i is parent[i]

int find(int vertex){
    if(parentDir[vertex].parent!=vertex)
        return find(parentDir[vertex].parent);
    return vertex;
}

void unify(int x, int y){
    int x_set_parent = find(x);
    int y_set_parent = find(y);

    //attach the smaller rank tree to the higher rank tree
    if(parentDir[x_set_parent].rank > parentDir[y_set_parent].rank){
        //make x as parent of y
        parentDir[y_set_parent].parent = x_set_parent;

    }else if(parentDir[y_set_parent].rank < parentDir[y_set_parent].rank){
        //make y as parent of x
        parentDir[x_set_parent].parent = y_set_parent;

    }else{
        // make any tree child of other tree
        parentDir[y_set_parent].parent = x_set_parent;
        //now increase the rank of x for the next time
        parentDir[x_set_parent].rank++;
    }
}

void solve(int case_num)
{
    int n,d;
    cin>>n>>d;
    vector<vi> points(n,vi(d));
    rep(n)
        forn(j,0,d) cin>>points[i][j];
    
    vector<pair<int, pi>> edges(n*(n-1));
    parentDir.resize(n);

    int index = 0;
    forn(i, 0, n)
    {
        forn(j, i+1, n)
        {
            if(i == j)  continue;
            int sum = 0;
            forn(k, 0, d)
            {
                sum += abs(points[i][k] - points[j][k]);
            }
            edges[index++] = {-sum, {i, j}};
            edges[index] = {sum, {j,i}};
        }
    }
    points.clear();
    rep(n)
    {
        parentDir[i].parent = i;
        parentDir[i].rank = 0;
    }
    sort(edges.begin(), edges.end());

    int mst_edges = 0, ret = 0;
    for(int i = 0; mst_edges < n-1; i++)
    {
        int x = find(edges[i].second.first);
        int y = find(edges[i].second.second);

        // If including this edge does't cause cycle,  
        // include it in result and increment the index  
        // of result for next edge
        if (x != y)
        {
            mst_edges++;
            ret += -edges[i].first;
            // mst.push_back(edges[i]);
            unify(x, y);  
        }
    }
    cout<<ret<<endl;
}

int main() 
{
    #ifdef LOCAL_PROJECT
    freopen("/home/shubham/CodingPractice/vsCode/input.txt", "r", stdin);
    freopen("/home/shubham/CodingPractice/vsCode/output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    // cin>>cases;
    forn(i,0,cases)
    {
        solve(i);
    }
    return 0;
}

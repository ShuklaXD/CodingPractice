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
void countCC(vector<vector<bool>> &edges, vector<vector<bool>> &visited, int &curr, int i, int j)
{
    visited[i][j] = true;

    if(i-2 >-1 && j-1>-1 && edges[i-2][j-1] && !visited[i-2][j-1])
        countCC(edges, visited, ++curr, i-2, j-1);

    if(i-2 >-1 && j+1<cols(edges) && edges[i-2][j+1] && !visited[i-2][j+1])
        countCC(edges, visited, ++curr, i-2, j+1);

    if(i+2 <rows(edges) && j-1>-1 && edges[i+2][j-1] && !visited[i+2][j-1])
        countCC(edges, visited, ++curr, i+2, j-1);

    if(i+2 <rows(edges) && j+1<cols(edges) && edges[i+2][j+1] && !visited[i+2][j+1])
        countCC(edges, visited, ++curr, i+2, j+1);

    if(i-1 >-1 && j-2>-1 && edges[i-1][j-2] && !visited[i-1][j-2])
        countCC(edges, visited, ++curr, i-1, j-2);

    if(i-1 >-1 && j+2<cols(edges) && edges[i-1][j+2] && !visited[i-1][j+2])
        countCC(edges, visited, ++curr, i-1, j+2);

    if(i+1 <rows(edges) && j-2>-1 && edges[i+1][j-2] && !visited[i+1][j-2])
        countCC(edges, visited, ++curr, i+1, j-2);

    if(i+1 <rows(edges) && j+2<cols(edges) && edges[i+1][j+2] && !visited[i+1][j+2])
        countCC(edges, visited, ++curr, i+1, j+2);
}

int fact(int r)
{
    if(r==1)
        return 1;
    else
    {
       return (int)( ((ll)r * fact(r-1))%mod);
    }
}

int solve()
{
    int n,m,q;

    cin>>n>>m>>q;
    vector<vector<bool>> horse(n+1,vector<bool>(m+1,false)), visited(n+1,vector<bool>(m+1,false));
    if(q<2)
        return q;

    int a,b;
    fo(i,q){
        cin>>a>>b;
        horse[a-1][b-1] = true;
    }

    int res=1,curr=1,master=1;

    for(int i = 0; i< n; ++i){
        for(int j = 0; j < m; ++j){
            int r = 1;
            if(horse[i][j] && !visited[i][j]){
                countCC(horse, visited, r, i,j);
                cout<<"horse in component : "<<r<<endl;
                master = (int) ( ( ( (ll)master%mod) * ( (ll)fact(r)%mod) ) % mod );
            }
        }
    }
    return master;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;

    cin>>cases;

    while(cases-->0){
        cout<<solve()<<endl;
    }

    return 0;
}

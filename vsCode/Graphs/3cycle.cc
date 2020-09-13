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
void solve()
{
    int n , m;
    cin>>n>>m;
    vi u(m,0),v(m,0);

    for(int i = 0; i<m;i++)
        cin>>u[i];
    for(int i = 0; i<m;i++)
        cin>>v[i];
    
    vector<vi> edges(n+1, vi(n+1, 0));

    for(int i = 0; i < m; i++)
    {
        edges[u[i]][v[i]] = 1;
        edges[v[i]][u[i]] = 1;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = n; j > i+1; j--)
        {
            if((edges[i][j] && edges[i][j-1]) && edges[j][j-1])
                cnt++;
            
            if(j < n)
            {
                if((edges[i][j] && edges[i][j+1]) && edges[j][j+1])
                    cnt++;
            }
            if(i > 0)
            {
                if((edges[i][j] && edges[i-1][j]) && edges[i][i-1])
                    cnt++;
            }
            if(i < n)
            {
                if((edges[i][j] && edges[i+1][j]) && edges[i][i+1])
                    cnt++;
            }
        }
    }
    cout<<cnt/2;
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

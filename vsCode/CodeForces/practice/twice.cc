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

int backtr(vector<string> &grid, vector<vi> &wz, int i, int j, const int &n)
{
    if(i >= n || j >= n || grid[i][j] != '0')    return 0;
    if(i == n-1 && j == n-1)    return 1;
    
    wz[i][j]++;
    grid[i][j] = '1';
    int ans = backtr(grid, wz, i+1,j,n) +
    backtr(grid, wz, i-1,j,n) +
    backtr(grid, wz, i,j+1,n) +
    backtr(grid, wz, i,j-1,n);
    grid[i][j] = '0';
    if(ans == 0)
        wz[i][j]--;
    return ans;
}

int backtr1(vector<string> &grid, vector<vi> &wz, int i, int j, const int &n)
{
    if(i >= n || j >= n || grid[i][j] != '1')    return 0;
    if(i == n-1 && j == n-1)    return 1;
    
    grid[i][j] = '0';
    int ans = backtr(grid, wz, i+1,j,n) +
    backtr(grid, wz, i-1,j,n) +
    backtr(grid, wz, i,j+1,n) +
    backtr(grid, wz, i,j-1,n);
    grid[i][j] = '1';
    
    wz[i][j] = ans;

    return ans;
}

void solve(int case_num)
{
    int n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++)
        cin>>grid[i];
    
    vector<vector<int>> wz(n,vi(n,0)), wo(n,vi(n,0));

    int num_ways = 0;

    grid[0][0] = grid[n-1][n-1] = '0';
    int numz = backtr(grid, wz, 0, 0, n);

    int numo = backtr1(grid, wo, 0, 0, n);

    int nump = 0;
    vector<vector<int>> ans(2);
    if(numz == 0 && numo == 0)
    {
        cout<<0<<endl;
        return;
    }
    else
    {
        int r = grid[0][1], l = grid[1][0], lr = grid[n-1][n-2], lc = grid[n-2][n-1];
        if(numz && numo)
        {
            cout<<2<<endl;
            if(r == 0)
            {
                cout<<0<<" "<<1<<endl;
            }
            else
            {
                
            }
            if(lr == 1)
            {
                ans.push_back({n-1,n-2});
            }
            else
                ans.push_back({n-2,n-1});
        }
        if(numz)
        {
            if(r == l && lr == lc)
            {
                nump = 2;
                
            }
        }
    }
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
    cin>>cases;
    forn(i,0,cases)
    {
        solve(i);
    }

    return 0;
}

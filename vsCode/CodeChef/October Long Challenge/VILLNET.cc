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

int limit = 1e3;

void solve(int case_num)
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    unordered_map<int, unordered_map<int, int>> grid;
    queue<pi> que;

    que.push({x1,y1});
    grid[x1][y1] = 0;
    while(!que.empty())
    {
        auto c = que.front();
        que.pop();
        int &x = c.first, &y = c.second;
        if(x == x2 && y == y2)
        {
            cout<<grid[x][y]<<endl;
            break;
        }
        if(grid[x+2*y][y] == 0)
        {
            grid[x+2*y][y] = grid[x][y] + 1;
            que.push({x+2*y,y});
        }
        if(grid[x-2*y][y] == 0)
        {
            grid[x-2*y][y] = grid[x][y] + 1;
            que.push({x-2*y,y});
        }
        
        if(y + 2*(x) >= 0 && grid[x][y + 2*(x)] == 0)
        {
            grid[x][y+2*(x)] = grid[x][y] + 1;
            que.push({x,y+2*(x)});
        }
        else if(grid[-x][-(y + 2*(x))] == 0)
        {
            grid[-x][-(y+2*(x))] = grid[x][y] + 1;
            que.push({-x,-(y+2*(x))});
        }
        
        if(y - 2*(x) >= 0 && grid[x][y - 2*(x)] == 0)
        {
            grid[x][y-2*(x)] = grid[x][y] + 1;
            que.push({x,y-2*(x)});
        }
        else if(grid[-x][-(y - 2*(x))] == 0)
        {
            // cout<<"inv"<<endl;
            grid[-x][-(y-2*(x))] = grid[x][y] + 1;
            que.push({-x,-(y-2*(x))});
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

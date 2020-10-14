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

string convert(string s, int numRows) {
    int w = s.size();
    vector<vector<char>> rows(numRows, vector<char>(w, '*'));
    int k = numRows - 1;
    
    int target = s.size();
    
    for(int i = 0; i< w && target; i++)
    {
        if(i % k == 0)
        {
            for(int j = 0; j <= k && target; j++)
            {
                rows[j][i] = '#';
                target--;
            }
        }
        else
        {
            rows[k - i%k][i] = '#';
            target--;
        }
    }
    // forn(j,0,k+1)
    // {
    //     for(int i = 0; i < 10; i++)
    //     {
    //         cout<<rows[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }

    int index = 0;
    target = s.size();
    for(int i = 0; i < w && index < target; i++)
    {
        for(int j = 0; j <= k && index < target; j++)
        {
            if(rows[j][i] == '#')
            {
                rows[j][i] = s[index++];
            }
        }
    }
    string ans = s;
    index = 0;
    forn(j,0,k+1)
    {
        for(int i = 0; i < 10; i++)
        {
            // cout<<rows[j][i]<<" ";
            if(rows[j][i]!='*')
                ans[index++] = rows[j][i];
        }
        // cout<<endl;
    }
    // index = 0;
    // for(int j = 0; j <= k && index < target; j++)
    // {
    //     for(int i = 0; i < w && index < target; i++)
    //     {
    //         if(rows[j][i] != ' ')
    //             ans[index++] = rows[j][i];
    //     }
    // }
    return ans;
}

void solve(int case_num)
{
    string s;   cin>>s;
    int k;  cin>>k;

    cout<<convert(s,k)<<endl;
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

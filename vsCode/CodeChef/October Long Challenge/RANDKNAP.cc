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
const int mod = 998244353;
// int 2 * 1e9
// long long 9 * 1e18
#define sum(a, b) (int)(((long)(a % mod) + (b % mod) ) % mod)

vector<vector<bool>> co;
vector<int> arr;

unordered_map<int, vector<bool>> dp;

// bool getsum(int i, int sumsofar, vector<bool> &positions)
// {
//     if(i >= 240)
//         return false;
//     if(dp[i].count(sumsofar)!=0)    return false;
//     if(getsum(i+1, sumsofar, positions))    return true;
//     dp[i].insert(sumsofar);
//     positions[i] = 1;
//     int a = sum(sumsofar, arr[i]);
//     if(getsum(i+1, a, positions))    return true;
//     positions[i] = 0;
//     dp[i].insert(a);
//     return false;
// }

bool isSubsetSum(int n, int target, int sfr, vector<bool> &ans)
{
    // Base Cases
    if(sfr > target || n >= 240)        return false;
    if (target == sfr)      return true;
    
    // If last element is greater than sum, 
    // then ignore it 
    if (arr[n] > target)
    {
        if(isSubsetSum(n + 1, target, sfr, ans))    return true;
    }

    bool a =  isSubsetSum(n + 1, target, sfr, ans);
    if(a)
    {
        dp[sfr] = ans;
        return true;
    }

    ans[n] = true;
    int sb = sum(sfr, arr[n]);
    bool b =  isSubsetSum(n + 1, target, sb, ans); 
    if(b)
        return true;
    else
    {
        ans[n] = false;
        return false;
    }
} 

void solve(int case_num)
{
    int n,q;
    cin>>n;
    arr.resize(n);
    rep(n)  cin>>arr[i];
    cin>>q;
    vector<bool> ans(240, 0);
    // getsum(0,0,ans);
    // co.resize(998244353);
    int f;
    dp.resize(240);
    while(q--)
    {
        cin>>f;
        // auto b = co[f];
        isSubsetSum(0,f,0,ans);
        auto &b = ans;
        // getsum(0,0,ans);
        ll res = 0;
        for(int i = 0; i<60; i++)
        {
            if(b[i])
                res = res | (1<<i);
        }
        cout<<res<<" ";
        res = 0;
        for(int i = 60; i<120; i++)
        {
            if(b[i])
                res = res | (1<<(i-60));
        }
        cout<<res<<" ";
        res = 0;
        for(int i = 120; i<180; i++)
        {
            if(b[i])
                res = res | (1<<(i-120));
        }
        cout<<res<<" ";
        res = 0;
        for(int i = 180; i<240; i++)
        {
            if(b[i])
                res = res | (1<<(i-180));
        }
        cout<<res<<endl;
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
    // cin>>cases;
    forn(i,0,cases)
    {
        solve(i);
    }
    return 0;
}

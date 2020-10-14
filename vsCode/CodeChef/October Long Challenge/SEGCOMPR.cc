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

int firstBit(int a)
{
    for(int i = 31; i >=0; i--)
    {
        if(a>>i&1)
        {
            return 1<<(i);
        }
    }
    return 0;
}
vector<vector<bool>> dp;
void segment(vi arr, int i, int j, int &ans)
{
    if(i > j || j >= arr.size())   return;
    if(dp[i][j])    return;
    int res = 0;
    if(i == j)
    {
        res = arr[i];
        // segment(arr,i+1,j,ans);
        // segment(arr,i,j+1,ans);
        // return;
    }
    else{
        vi tmp = arr;
        for(int k = 2; k < INT_MAX/2; k=k<<1)
        {
            res = 0;
            int found = -1;
            for(int as = i; as < j; as++)
            {
                if(tmp[as] % k)
                {
                    found = as;
                    res^=tmp[as];
                    res = firstBit(res);
                    tmp[as] = 0;
                }
            }
            if(found != -1)
                tmp[found] = firstBit(res);
        }
    }
    cout<<i<<" "<<j<<" "<<res<<endl;
    dp[i][j] = true;
    ans += res;
    segment(arr,i+1,j,ans);
    segment(arr,i,j+1,ans);
}

void solve(int case_num)
{
    int n;
    cin>>n;   
    vector<int> arr(n);
    rep(n)      cin>>arr[i];
    dp.resize(n+1,vector<bool>(n+1,false));
    int ret = 0;
    segment(arr, 0, 0, ret);    
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

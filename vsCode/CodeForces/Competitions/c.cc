#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int,int>> vpi;
#define sortn(a) sort(a.begin(), a.end())
#define rep(n) for (int i = 0; i < n; i++)
#define forn(i,a,b) for (int i = a; i < b; i++)
#define deb(x) cout << #x << " : " << x << endl;
#define isBitSet(S, i) ((S >> i) & 1)
#define cin(arr)    for(int &a : arr)   cin>>a;

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;
// int 2 * 1e9
// long long 9 * 1e18

#define mad(a,b)    (int)((((ll)a%mod) + ((ll)b%mod))%mod);

void solve(int case_num)
{
    int n;
    cin>>n;
    vi arr(n);
    cin(arr);
    sortn(arr);
    int avg = accumulate(arr.begin(), arr.end(),0) / n;
    auto st = lower_bound(arr.begin(), arr.end(), avg);
    auto en = upper_bound(arr.begin(), arr.end(), *st);
    auto mid = st, tw = st;
    while(tw != en)
    {
        mid++;
        tw++;
        if(tw == en)    break;
        else    tw++;        
    }
    int time = *mid, prev = *mid, sum = 0;
    for(auto it = mid; it != arr.end(); it++)
    {
        if(*it == prev)
        {
            time++;
            sum+=(time - *it);
        }
        else
        {
            time = *it;
        }
        prev = *it;
    }
    time = arr[0];
    prev = *mid;
    for(auto it = arr.begin(); it != mid; it++)
    {
        if(*it == prev)
        {
            time++;
            sum+=(time - *it);
        }
        else
        {
            time = *it;
        }
        prev = *it;
    }
    cout<<sum<<endl;
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

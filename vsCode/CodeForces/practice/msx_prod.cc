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

void solve(int case_num)
{
    int n;
    cin>>n;
    vi arr(n);
    ll ans = INT_MIN, tmp = 1;
    for(int &a : arr)   cin>>a;

    sort(arr.begin(), arr.end());
    int nump = 0;
    for(int i : arr)
    {
        if(i%2==0)    nump++;
    }

    if(arr[0] >= 0)
    {
        ans = arr[n-1]*arr[n-2]*arr[n-3]*arr[n-4]*arr[n-5];
    }
    else if(arr[n-1] == 0)
    {
        ans = 0;
    }
    else if(arr[n-1] > 0)
    {
        ans = arr[n-1];
        int l = arr[0]*arr[1];
        int r = arr[n-2] * arr[n - 3];
        if(l > r)
        {
            ans*=l;
            l = arr[2]*arr[3];
        }
        else
        {
            ans*=r;
            r= arr[n-4]*arr[n-5];
        }
        if(l > r)   ans*=l;
        else    ans*=r;
    }
    else
    {
        ans = arr[0]*arr[1]*arr[2]*arr[3]*arr[4];
    }
    
    cout<<ans<<endl;
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

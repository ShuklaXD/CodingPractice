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
    int n,x, p, k;
    cin>>n>>x>>p>>k;
    vector<int> arr(n+1);
    forn(i,1, n+1)      cin>>arr[i];

    sort(arr.begin(), arr.end());

    if(p < k)
    {
        if(x <= arr[p])
        {
            int ans = 0;
            for(int i = p; i >=0 && arr[i] > x; i--)
            {
                ans++;
            }
            cout<<ans<<endl;
        }
        else
        {
            cout<<-1<<endl;
            return;
        }
    }
    else if(p==k)
    {
        if(x <= arr[p])
        {
            int ans = 0;
            for(int i = p; i >=0 && arr[i] > x; i--)
            {
                ans++;
            }
            cout<<ans<<endl;
        }
        else if(arr[p] <= x)
        {
            int ans = 0;
            for(int i = p; i <= n && arr[i] < x; i++)
            {
                ans++;
            }
            cout<<ans<<endl;
        }
    }
    else
    {
        if(arr[p] <= x)
        {
            int ans = 0;
            for(int i = p; i <= n && arr[i] < x; i++)
            {
                ans++;
            }
            cout<<ans<<endl;
        }
        else
        {
            cout<<-1<<endl;
            return;
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

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
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    rep(n)      cin>>arr[i];
    
    ll i = 0;
    ll left = 0;
    for(; i < n; i++)
    {
        left += arr[i];
        if(left < k)
        {
            cout<<i+1<<endl;
            return;
        }
        left-=k;
    }
    if(left > k)
    {
        i+= (left)/k;
        // if(left % k)
        //     i++;
    }
    cout<<i+1<<endl;
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

#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define vsort(a) sort(a.begin(), a.end())
#define sizeOf(a) a.size()

#define For(i,a,b) for (int i = a; i < b; i++)
#define deb(x) cout << #x << " : " << x << endl;
#define isBitSet(S, i) ((S >> i) & 1)

void solve()
{
    int n, x;
    cin>>n;
    int arr[n+1];

    bool can = true;
    For(i,1,n+1)
    {
        cin>>arr[i];
        if(i%arr[i] != 0)
            can = false;
    }
    if(can)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    cin>>cases;

    For(i,0,cases)
    {
        solve();
    }
    return 0;
}

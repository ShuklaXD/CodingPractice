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

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;


void solve()
{
    int a,b,c,d,n,m,k;
    cin>>a;
    vector<int> arr(a, 0), left(a, 0), right(a, 0);
    For(i,0,a)  cin>>arr[i];
    
    int max = 0;
    left[0] = 1;
    right[a-1] = 1;

    For(i,1,a)
    {
        if(arr[i] >= arr[i-1])              left[i] = left[i-1] + 1;
        else                                left[i] = 1;
        if(arr[a - 1 - i] >= arr[a - i])    right[a - 1 - i] = right[a - i] + 1;
        else                                right[a - 1 - i] = 1;
    }
    For(i,0,a)
    {
        if(left[i] + right[i] - 1> max)
        {
            max = left[i] + right[i] - 1;
        }
    }

    cout<<max<<endl;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    // cin>>cases;

    For(i,0,cases)
    {
        // cout << "Case #"<<i<<": ";
        solve();
        // cout <<"\n"[i==cases-1];
    }
    return 0;
}

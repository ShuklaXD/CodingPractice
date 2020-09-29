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
    int n;
    cin>>n;
    int arr[n+1], ans = 0;
    int min = 0;
    For(i,1,n+1)
    {
        cin>>arr[i];
        if(arr[i] < 0)
        {
            min -= arr[i];
            arr[i] = 0;
        }
        else
        {
            min -= arr[i] % i;
            arr[i] = arr[i] - arr[i]%i;
        }
    }

    if(min > 0)
    {
        for(int i = n; i > 0; i--)
        {
            while(arr[i] > min)
            {
                arr[i] -= i;
            }
            min -= arr[i];
            if(min == 0)
                break;
        }
    }

    if(min == 0)
        cout<<"YES"<<endl;
    else
    {
        cout<<"NO"<<endl;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    cin>>cases;

    For(i,0,cases)
    {
        // cout << "Case #"<<i<<": ";
        solve();
        // cout <<"\n"[i==cases-1];
    }
    return 0;
}

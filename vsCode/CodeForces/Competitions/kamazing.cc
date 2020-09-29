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
    cin>>n;
    int arr[n];
    For(i,0,n)  cin>>arr[i];

    vector<int> ans;
    for(int i = n-1; i >= 0; i--)
    {
        int st = n -1 - i, end = i;
        if(st <= end)
        {
            int min_e = INT_MAX;
            for(int ti = st; ti <= end; ti++)
            {
                min_e = min(min_e, arr[ti]);
            }
            ans.push_back(min_e);
        }
        else
        {
            int a = arr[st], b = arr[end];
            bool cana = true, canb = true;
            int sa = st, sb = end;
            while(sa >=0 && cana)
            {
                if(arr[sa] != arr[st])
                    cana = false;
                sa -= (i+1);
            }
            while(sb < n && canb)
            {
                if(arr[sb] != arr[end])
                    canb = false;
                sb += (i+1);
            }
            if(cana && canb)
                ans.push_back(min(a,b));
            else if(cana)
                ans.push_back(a);
            else if(canb)
                ans.push_back(b);
            else
                ans.push_back(-1);
        }
    }
    for(int i = n-1 ; i >= 0; i--)
        cout<<ans[i]<<" ";
    cout<<endl;
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

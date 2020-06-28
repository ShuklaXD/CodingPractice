#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vp;

#define sv(a) sort(a.begin(), a.end())
#define sz(a) a.size()

#define foreach(i,a,b) for (int i = a; i <= b; i++)
#define fo(i,n) for (int i = 0; i < n; i++)
#define deb(x) cout << #x << x << endl;

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/
void update(int index, int val, vi &bit)
{
    while(index < bit.size()){
        bit[index] += val;
        index += index&(-index);
    }
}

int query(int index, vi &bit)
{
    int res = 0;
    while(index > 0){
        res += bit[index];
        index -= index&(-index);
    }
}

void fenwick()
{
    int n;
    cin>>n;
    vi arr(n+1, 0), bit(n+1, 0);
    foreach(i,1,n)
    {
        cin>>arr[i];
        update(i, arr[i], bit);
    }
    foreach(i,1,n){
        cout<<bit[i]<<" ";
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;

    // cin>>cases;

    while(cases-->0)
        fenwick();

    return 0;
}

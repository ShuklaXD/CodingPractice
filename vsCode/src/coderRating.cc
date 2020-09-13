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
struct coders
{
    int first, second, index;
};

bool comp(coders &a, coders &b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int query(int index, vi be)
{
    int ans = 0;
    for(;index > 0; index -= index&(-index))
    {
        ans+=be[index];
    }
    return ans;
}

void update(int index, vector<int> &be)
{
    for(;index < 100001; index += index&(-index))
    {
        be[index] += 1; 
    }
}


void solve()
{
    int n;
    cin>>n;
    vector<coders> coder(n+1);
    foreach(i,1,n){
        cin>>coder[i].first>>coder[i].second;
        coder[i].index = i;
        // cout<<i<<" "<<coder[i].first<<" "<<coder[i].second<<endl;
    }
    sort(coder.begin(), coder.end(), comp);

    vi bit(100001, 0);
    foreach(i,1,n)
    {
        update(i, bit, coder[i].second);
        cout<<"coder "<<i<<" "<<coder[i].first<<" "<<coder[i].second<<endl;
    }
    vi ans(n+1);
    foreach(i,1,n)
    {
        ans[coder[i].index] = bit[i] - 1;
    }
    foreach(i,1,n)
    {
        cout<<ans[i]<<endl;
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;

    // cin>>cases;

    while(cases-->0)
        solve();

    return 0;
}

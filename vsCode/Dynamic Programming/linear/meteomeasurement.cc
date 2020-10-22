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
    int n, k;  cin>>n>>k;
    vi data(n);
    for(int & a : data) cin>>a;
    int minimum = INT_MAX, maximum = INT_MIN;
    int avg = 0;
    forn(i,0,k) avg += data[i];

    minimum = maximum = avg;

    forn(i, k, n)
    {
        avg -= data[i - k];
        avg += data[i];
        minimum = min(minimum, avg);
        maximum = max(maximum, avg);
    }
    cout<< round((double)minimum/k) << endl << round((double)maximum/k) << endl;
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
    forn(i,0,cases)
    {
        solve(i);
    }
    return 0;
}

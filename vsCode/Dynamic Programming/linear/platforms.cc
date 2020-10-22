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
    int n;  cin>>n;
    vi h(n);
    for(int &a : h) cin>>a;
    pair<int, vi> fi, se;
    fi.second.reserve(n);
    se.second.reserve(n);
    // string s(n+1, '0');
    fi = {0,{1}};
    se = {abs(h[0]- h[1]), {1,2}};
    pair<int, vi> tmp;
    tmp.second.reserve(n);
    for(int i = 2; i < n; i++)
    {
        int one = se.first + abs(h[i]-h[i-1]);
        int two = fi.first + 3 * (abs(h[i-2] - h[i]));
        // if(one == two)
        // {
        //     tmp.first = one;
        //     tmp.second = se.second;
        // }
        if(one < two)
        {
            tmp.first = one;
            tmp.second = se.second;
            tmp.second.push_back(i+1);
        }
        else
        {
            tmp.first = two;
            tmp.second = fi.second;
            tmp.second.push_back(i+1);
        }
        fi = se;
        se = tmp;           
    }
    cout<<se.first<<endl;
    cout<<se.second.size()<<endl;
    for(int a : se.second) cout<<a<<" ";
    cout<<endl;
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
    // cin>>cases;
    forn(i,0,cases)
    {
        solve(i);
    }
    return 0;
}

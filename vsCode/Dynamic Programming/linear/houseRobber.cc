#include <bits/stdc++.h>

using namespace std;

typedef long long                   ll;
typedef vector<int>                 vi;
typedef pair<int,int>               pi;
#define sortn(a)                    sort(a.begin(), a.end())
#define rep(n)                      for (int i = 0; i < n; i++)
#define forn(i,a,b)                 for (int i = a; i < b; i++)
#define deb(x)                      cout << #x << " : " << x << endl;
#define isBitSet(S, i)              ((S >> i) & 1)
#define si(a)                       int a; scanf("%d",&a);
#define take(a)                     for(int &elem : a)  cin>>elem;

// Input macros 
#define s(n)                        scanf("%d",&n) 
#define sc(n)                       scanf("%c",&n) 
#define sl(n)                       scanf("%lld",&n) 
#define sf(n)                       scanf("%lf",&n) 
#define ss(n)                       scanf("%s",n) 

// Useful hardware instructions 
#define bitcount                    __builtin_popcount 
#define gcd                         __gcd 
 
// Useful container manipulation / traversal macros 
#define all(a)                      a.begin(), a.end() 
#define in(a,b)                     ( (b).find(a) != (b).end()) 
#define pb                          push_back 
#define fill(a,v)                   memset(a, v, sizeof a) 
#define sz(a)                       ((int)(a.size())) 
#define mp                          make_pair 
 
// Some common useful functions 
#define maX(a,b)                     ( (a) > (b) ? (a) : (b)) 
#define miN(a,b)                     ( (a) < (b) ? (a) : (b)) 
#define checkbit(n,b)                ( (n >> b) & 1) 
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end()) 
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;
// int 2 * 1e9
// long long 9 * 1e18

int solve(int case_num)
{
    ll max, first, second;
    int n;  cin>>n;
    vi house(n);
    take(house);
    // for(int &a: house)  cin>>a;
    
    if(n == 1)  return house[0];
    if(n == 2)  return maX(house[0], house[1]);
    
    first = house[0];
    second = maX(house[0], house[1]);

    for(int i = 2; i < n; i++)
    {
        max = maX(first + house[i], second);
        first = second;
        second = max;
    }
    return max;
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
        cout << solve(i) << endl;
    }
    return 0;
}

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

__int128_t target = 5213096522073683233230240000;
vector<__int128_t> A = {2316931787588303659213440000,
     1303274130518420808307560000,
     834095443531789317316838400,
     579232946897075914803360000,
     425558899761116998631040000,
     325818532629605202076890000,
     257436865287589295468160000,
     208523860882947329329209600,
     172333769324749858949760000,
     144808236724268978700840000,
     123386899930738064691840000,
     106389724940279249657760000,
     92677271503532146368537600,
     81454633157401300519222500,
     72153585080604612224640000,
     64359216321897323867040000,
     57762842349846905631360000,
     52130965220736832332302400,
     47284322195679666514560000,
     43083442331187464737440000,
     39418499221729173786240000,
     36202059181067244675210000,
     33363817741271572692673536,
     30846724982684516172960000,
     28604096143065477274240000,
     26597431235069812414440000,
     24794751591313594450560000,
     23169317875883036592134400,
     21698632766175580575360000,
     20363658289350325129805625,
     19148196591638873216640000,
     18038396270151153056160000,
     17022355990444679945241600};

void solve(int case_num)
{

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
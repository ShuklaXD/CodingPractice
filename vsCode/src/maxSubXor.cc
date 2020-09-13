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
#define deb(x) cout << #x <<" : "<< x << endl;

#define ll child[0]
#define rr child[1]

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/

struct Trie
{
    int c;
    struct Trie *child[2];
    
    Trie()
    {
        c = 0;
        child[0] = child[1] = NULL;    
    }
};

void put(int a, Trie *trie)
{
    Trie *t = trie;
    for(int i = 31; i >= 0; --i)
    {
        // if( a>>i & 1)
        // {
        //     if(t->rr == NULL)
        //         t->rr = new Trie();
        //     t = t->rr;
        //     t->rr->c++;
        // }
        // else
        // {
        //     if(t->ll == NULL)
        //         t->ll = new Trie();
        //     t = t->ll;
        //     t->ll->c++;
        // }

        int ind =  a>>i & 1 ;
        
        if(t->child[ind] == NULL)
            t->child[ind] = new Trie;
        
        t = t->child[ind];
        t->c++;
    }
}

int check(int k, int pre, Trie *trie)
{
    Trie *t = trie;
    int ans = 0;

    for(int i = 31; i >= 0; --i)
    {
        if( k >> i & 1 )
        {
            int m = pre >> i & 1;

            if(t->child[m] != NULL)
            {
                ans += t->child[m]->c;
            }

            if(t->child[1-m] != NULL)
            {
                t = t->child[1-m];
            }
            else
                return ans;
        }
        else
        {
            int m = pre >> i & 1;

            if(t->child[m] == NULL)
                return ans;
            else
                t = t->child[m];
        }
    }
    return ans;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    
    vi input(n);
    fo(i,n) cin>>input[i];

    Trie *trie = new Trie();

    int pre = 0, cnt = 0;
    for(int a : input)
    {
        int c = check(k, pre, trie);
        put(a, trie);
        pre ^= a;
        deb(pre);
        deb(c);
        cnt += c;
    }
    cout<<cnt<<endl;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;

    cin>>cases;

    while(cases-->0)
        solve();

    return 0;
}

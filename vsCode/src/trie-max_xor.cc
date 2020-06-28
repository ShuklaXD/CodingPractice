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
struct trie_s
{
    struct trie_s *left, *right;
    trie_s()
    {
        left = right = NULL;
    }
};


void put(int a, trie_s *trie)
{
    trie_s *ptr = trie;
    for(int i = 31; i >= 0 ; --i)
    {
        if(a>>i & 1)
        {
            if(ptr->right == NULL)
                ptr->right = new trie_s();
            ptr = ptr->right;
        }
        else
        {
            if(ptr->left == NULL)
                ptr->left = new trie_s();
            ptr = ptr->left;    
        }
    }
}


int maxXor(int a, trie_s *trie)
{
    int res = 0;
    trie_s *ptr = trie;

    for(int i = 31 ; i >= 0; --i)
    {
        if(a>>i & 1)
        {
            if(ptr->left != NULL)
            {
                ptr = ptr->left; 
                res |= (1 << i);
            }
            else
                ptr = ptr->right;
        }
        else
        {
            if(ptr->right != NULL)
            {
                ptr = ptr->right;
                res |= (1 << i);
            }
            else
                ptr = ptr->left;
        }
    }
    return res;
}


void maxXorSubarr()
{
    trie_s *trie = new trie_s();

    int n;
    cin>>n;
    
    vi vals(n);

    fo(i, n)    cin>>vals[i];

    int res = INT_MIN, pre = 0;
    for(int a : vals)
    {
        pre = pre^a;
        put(pre, trie);
        int ss =  maxXor(pre, trie);
        res = max(res, ss);
    }
    cout<< res << endl;
}

void solve()
{
    trie_s *trie = new trie_s();

    int n;
    cin>>n;
    
    int x;

    fo(i, n)    
    {
        cin>>x;
        put(x, trie);
    }

}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;

    while(cases-->0)
        maxXorSubarr();

    return 0;
}

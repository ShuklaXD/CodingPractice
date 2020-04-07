#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

/*
input size required time complexity 
n≤10 		O(n!) 
n≤20 		O(2^n) 
n≤500 		O(n^3) 
n≤5000 		O(n^2) 
n≤10^6		O(nlogn) or O(n) 
n is large	O(1) or O(logn)
*/

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

const int INF = 1e7 + 5;
const int mod = 1e9 + 7;


void solve(vi pos, int n)
{
    vector<vector<ll>> dp(n+1, vector<ll>((n/2) +1, 0));
    vi allowed(n + 1, 1);

    for(int g : pos)
        allowed[g] = 0;

    int j = 0;
    dp[1][1] = 1;
    for(int i = 2; i<= n; i++)
    {
        for(int k = 0; k <=n/2; k++)
        {
            if(k > 0)
                if(allowed[i])
            	    dp[i][k-1] += dp[i-1][k];
            if(k < n/2)
                dp[i][k+1] += dp[i-1][k];
        }
    }

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int tk = 0; tk <= (n/2); tk++)
    //     {
    //         cout<<"   dp["<<i<<"]["<<tk<<"] : "<<dp[i][tk];
    //     }
    //     cout<<endl;
    // }

    cout<<dp[n][0]<<endl;
}

int main()
{
    int cases;
    cin>>cases;
    while(cases-->0)
    {
    	int n,k;
        cin>>n>>k;
        vector<int> pos(k);
        
        for(int i = 0 ; i < k; i++)
            cin>>pos[i];
        
        solve(pos,2*n);
    }
    return 0;
}

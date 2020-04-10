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

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;


void dp(vector<pi>& party, int budget)
{
    int sz = party.size();

    vector<vector<pi>> dp(sz+1, vector<pi>(budget+1));

    for(int i = 1; i <=sz; i++)
    {
        for(int k = party[i-1].first; k<= budget; k++)
        {
            dp[i][k].second = max( party[i-1].second + dp[i-1][budget - party[i-1].first].second, dp[i-1][k].second);
            
            if ( dp[i][k].first == (party[i-1].second + dp[i-1][budget - party[i-1].first].first))
                dp[i][k].first = dp[i-1][budget - party[i-1].first].first + party[i-1].first;
            else
                dp[i][k].first = dp[i-1][k].first;            
        }
    }
    
    for(int i = 1; i <=sz; i++)
    {
        for(int k = 0; k<= budget; k++)
        {
            cout<<dp[i][k].first<<" "<<dp[i][k].second<<" || ";
        }
        cout<<endl;
    }
    cout<<dp[sz][budget].first<<" "<<dp[sz][budget].second<<endl;
}

void solve()
{
	int budget, n;
    cin>>budget>>n;
    vector<pi> party(n);    //first : fees; second : fun

    for(int i = 0; i < n; ++i)
        cin>>party[i].first>>party[i].second;
    

    dp(party, budget);
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

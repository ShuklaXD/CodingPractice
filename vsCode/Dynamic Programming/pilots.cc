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


void solve(vector<pair<int, int>>& pilot)
{
    int sz = pilot.size();

    vector<vector<int>> dp(sz+1, vector<int>((sz/2) + 1, INF));

    dp[1][1] = pilot[0].second;

    for(int i = 2; i <= sz; i++)
    {
        for(int tk = 1; tk <= (sz/2); tk++)
        {
            dp[i][tk] = min(dp[i][tk], dp[i-1][tk-1] + pilot[i-1].second);
            dp[i][tk-1] = min(dp[i][tk-1], dp[i-1][tk] + pilot[i-1].first);
        }
    }

    for(int i = 1; i <= sz; i++)
    {
        for(int tk = 0; tk <= (sz/2); tk++)
        {
            cout<<"   dp["<<i<<"]["<<tk<<"] : "<<dp[i][tk];
        }
        cout<<endl;
    }
    cout<<dp[sz][0];
}
int main()
{
    int size;
    cin>>size;
    
    vector<pair<int, int>> pilot(size);
    
    for(int i = 0; i < size; i++)
        cin>>pilot[i].first>>pilot[i].second;
    
    
    int curr = size - 1, mains = 0;
    solve(pilot);
    // cout<<solve(curr, 0, dp, pilot)<<endl;
    return 0;
}

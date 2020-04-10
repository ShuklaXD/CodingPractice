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

/**************************************************/

int num,w;

void print(vector<vi>& dp)
{
    for(int i = 0; i <= num; i++)
    {
        for(int k = 0; k <= w; k++)
        {
            cout<<dp[i][k]<<" ";
        }
        cout<<endl;
    }
}

int optimisedSolver(vector<pair<int,int>>& elem, int w)
{
    vector<int> first(w+1 , 0);
    vector<int> second(w+1, 0);
    for(int i = 1 ; i <= elem.size(); i++)
    {
        for(int k = elem[i-1].first; k <= w; k++)
        {
            second[k] = max(elem[i-1].second + first[k - elem[i-1].first] , first[k]);
        }
        first = second;
    }
    return second[w];
}

void solve(vector<pair<int,int>>& elem, int w, vector<vector<int>>& dp)
{
    for(int i = 1 ; i <= elem.size(); i++)
    {
        for(int k = 0; k <= w; k++)
        {
            if(k >= elem[i-1].first)
                dp[i][k] = max(elem[i-1].second + dp[i-1][k - elem[i-1].first] , dp[i-1][k]);
            else
                dp[i][k] = dp[i-1][k];
        }
    }

    cout<<dp[elem.size()][w]<<endl;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>w>>num;
    vector<pair<int,int>> elem(num);
    for(int i = 0; i < num; ++i)
        cin>>elem[i].first;
    for(int i = 0; i < num; ++i)
        cin>>elem[i].second;

    vector<vector<int>> dp(num+1, vector<int>(w + 1, 0));    //store max sum possible
    // solve(elem, w, dp);
    cout<<optimisedSolver(elem, w);

    return 0;
}
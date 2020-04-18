/*
PARTY - Problem

You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
Input
The first line of the input specifies your party budget and the number n of parties.

The following n lines contain two numbers each. The first number indicates the entrance fee of each party. Parties cost between 5 and 25 francs. The second number indicates the amount of fun of each party, given as an integer number ranging from 0 to 10.

The budget will not exceed 500 and there will be at most 100 parties. All numbers are separated by a single space.

There are many test cases. Input ends with 0 0.
Output
For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space. 

Sample Input
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9 

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0
Sample Output
49 26
48 32
*/

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

pi fun(vector<pi>& party, int i, int budget, vector<vector<pi>>& dp)
{
    pi res = {0,0};
    if(budget == 0 || i == dp.size())
        return res;
    if(budget < 0)
    {
        res.second = -100000;
        return res;
    }

    if(dp[i][budget].second != - 1)
        return dp[i][budget];
    else
    {
        pi f = fun(party, i+1, budget, dp);
        pi s = fun(party, i+1, budget - party[i].first, dp);

        if(i == dp.size() - 1)
        {
            dp[i][budget].second = f.second;
            dp[i][budget].first = f.first;
        }
        else if(f.second == party[i].second + s.second)
        {
            if(f.first <= party[i].first + s.first)
            {
                dp[i][budget].second = f.second;
                dp[i][budget].first = f.first;
            }
            else
            {
                dp[i][budget].second = party[i].second + s.second;
                dp[i][budget].first = party[i].first + s.first;
            }
        }
        else if(f.second > party[i].second + s.second)
        {
            dp[i][budget].second = f.second;
            dp[i][budget].first = f.first;
        }
        else
        {
            dp[i][budget].second = party[i].second + s.second;
            dp[i][budget].first = party[i].first + s.first;
        }
        
        // cout<<"dp "<<i<<" "<<budget<<" : "<<dp[i][budget].first<<" fun : "<<dp[i][budget].second<<endl;
        return dp[i][budget];
    }
}

bool solve()
{
	int budget, n;
    cin>>budget>>n;
    
    if(budget == 0 && n == 0)
        return false;
    vector<vector<pi>> dp;
    vector<pi> party;

    party.resize(n, {0,0});    //first : fees; second : fun

    for(int i = 0; i < n; ++i)
        cin>>party[i].first>>party[i].second;
    
    dp.resize(n+1, vector<pi>(budget+1, pi(0,-1)));

    pi res = fun(party, 0, budget, dp);
    cout<<"Ans : "<<res.first<<" "<<res.second<<endl;

    return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cases = 10;

	// cin>>cases;
    bool t = true;
	while(t)
	{
        t = solve();
    }
	
	return 0;
}
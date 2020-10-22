/*
Buying tickets
There is a queue of n people to buy tickets to a musical premiere. Each person wants to buy exactly one ticket. Only one ticket-office was working, therefore ticketing was very slowly, bringing "guests" to despair. The most smart people quickly noticed that, as a rule, the cashier sells several tickets in one hand faster than when those same tickets are sold one by one. So they proposed for a number of people standing in a row to give money to the first one of them, so that he would buy tickets for all.

However to deal with speculators, the cashier decided to sell maximum of three tickets per person, so to agree with each other in such way can only two or three successive persons.

It is known that to sell one ticket for the i-th person in the queue takes ai seconds, to sell two tickets takes bi seconds, to sell three tickets takes ci seconds. Write a program that calculates the minimum time to serve all the customers.

Please note that tickets for a group of united people always buys the first one. Also, no one buys extra tickets for speeding up the process (i.e. the tickets that are not wanted).

Input
The first line contains the number of people in the queue n (1 ≤ n ≤ 5000). Then n triples of positive integers ai, bi, ci are given. Each of these numbers is not greater than 3600. People in the queue are numbering starting from the booking office.

Output
Print the minimum time in seconds to serve all customers.

Input example #1
5
5 10 15
2 10 15
5 5 5
20 20 1
20 1 1
Output example #1
12
Input example #2
2
3 4 5
1 1 1
Output example #2

*/
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
    int n;
    cin>>n;
    vector<vector<int>> cost(n, vi(3));
    for(auto &c : cost)
    {
        for(auto &a : c)    cin>>a;
    }
    vector<int> dp(n+1, INT_MAX);   //cost to reach position x i.e. this person will now purchase his ticket.
    if(n == 1)
    {
        cout<<cost[0][0]<<endl;
        return;
    }
    dp[0] = 0;
    dp[1] = cost[0][0];
    dp[2] = min(cost[0][1], dp[1] + cost[1][0]);

    for(int i = 3; i <= n; i++)
    {
        dp[i] = min(min(dp[i-1] + cost[i-1][0], dp[i-2] + cost[i-2][1]), dp[i-3] + cost[i-3][2]);
    }

    cout<<dp[n]<<endl;  //cost needed to reach end of line
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

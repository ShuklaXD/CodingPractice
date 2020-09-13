/*
Kingdom Of Monkeys
Send Feedback
This is the story in Zimbo, the kingdom officially made for monkeys. Our Code Monk visited Zimbo and declared open a challenge in the kingdom, thus spoke to all the monkeys :

You all have to make teams and go on a hunt for Bananas. The team that returns with the highest number of Bananas will be rewarded with as many gold coins as the number of Bananas with them. May the force be with you!
Given there are N monkeys in the kingdom. Each monkey who wants to team up with another monkey has to perform a ritual. Given total M rituals are performed. Each ritual teams up two monkeys. If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the same team.

You are given an array A where Ai is the number of bananas i'th monkey gathers.

Find out the number of gold coins that our Monk should set aside for the prize.
Input:
First line contains an integer T. T test cases follow. First line of each test case contains two space-separated N and M. M lines follow. Each of the M lines contains two integers Xi and Yi, the indexes of monkeys that perform the i'th ritual. Last line of the testcase contains N space-separated integer constituting the array A.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
0 ≤ M ≤ 10^5
0 ≤ Ai ≤ 10^12
SAMPLE INPUT
1
4 3
1 2
2 3
3 1
1 2 3 5
SAMPLE OUTPUT
6
Explanation
Monkeys 1,2 ,3 are in the same team. They gather 1+2+3=6 bananas.
Monkey 4 is a team. It gathers 5 bananas.
Therefore, number of gold coins (highest number of bananas by a team) = 6.

*/
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
int cc(int st, vector<vi> &ed, vi &cost, vector<bool> &vi){
    if(vi[st]){
        return 0;
    }
    vi[st] = true;
    int ans = cost[st];
    for(int i = 0; i < ed[st].size(); i++){
        if(!vi[ed[st][i]]){
            ans += cc(ed[st][i], ed, cost, vi);
        }
    }
    return ans;
}

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<vi> ed(n+1);
    int a,b;
    fo(i,m){
        cin>>a>>b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    vi cost(n+1);
    for(int i = 1; i <= n; i++){
        cin>>cost[i];
    }
    vector<bool> visited(n+1);
    int ans = INT_MIN;
    for(int i = 1; i <= n ; i++){
        if(!visited[i]){
            ans = max(ans, cc(i, ed, cost, visited));
        }
    }
    cout<<ans<<endl;
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

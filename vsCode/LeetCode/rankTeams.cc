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


inline int toint(char c)
{
    return c-'A';
}

string rankTeams(vector<string>& votes) {
    if(votes.size() == 1)   return votes[0];
    
    int cands = votes[0].size();
    vector<pair<char, vector<int>>> ranks(26);
    
    for(int i = 0; i < 26; i++)
    {
        ranks[i].first = 'A'+i;
        ranks[i].second.resize(cands, 0);
    }

    for(string s : votes)
    {
        for(int i = 0; i < cands; i++)
        {
            int ind = toint(s[i]);
            ranks[ind].second[i]++;
        }
    }
    
    sort(ranks.begin(), ranks.end(), [](pair<char, vector<int>> &a, pair<char, vector<int>> &b)->bool{
        int s = a.second.size();
        
        for(int i = 0; i < s; i++)
        {
            if(a.second[i] == b.second[i])    continue;
            else    return a.second[i] > b.second[i];
        }
        return a.first < b.first;
    });
    
    string ans = {};
    for(int i = 0; i < cands; i++)
    {
        ans.push_back(ranks[i].first);
    }
    return ans;
}


void solve(int case_num)
{
    vector<string> q = {"ABC","ACB","ABC","ACB","ACB"};

    string ans = rankTeams(q);

    cout<<ans<<endl;
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

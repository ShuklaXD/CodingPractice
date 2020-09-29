#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int ans = 0;
    
    int find(int a, int b, const int& sa,const int& sb, const string &s,const string& t)
    {
        // cout<<a<<" "<<b<<endl;
        if(a >= sa || b >= sb)
            return 0;
        else if(b == sb - 1 && a < sa && s[a] == t[b])
        {
            dp[a][b] += 1;
            ans+=dp[a][b];
            return 1;
        }
        else if(dp[a][b] != 0)
        {
            if(dp[a][b]) ans+=dp[a][b];
            return dp[a][b];
        }
        else
        {
            if(s[a] == t[b])
            {
                dp[a][b] = find(a+1, b+1, sa, sb, s, t) + find(a+1, b, sa, sb, s, t);
            }
            else
            {
                dp[a][b] = find(a+1,b,sa,sb,s,t);
            }
            return dp[a][b];
        }
    }
    
    int numDistinct(string s, string t) {
        int a = s.size(), b = t.size();
        dp.resize(a+1, vector<int> (b, 0));
        find(0,0,a,b,s,t);
        return ans;
    }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    int ans = s.numDistinct("babgbag", "bag");
    cout<<ans<<endl;
    return 0;
}

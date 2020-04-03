#include "bits/stdc++.h"

using namespace std;

int iterative_LCS(string s1, string s2, vector<vector<int>>& dp)
{
    dp[0][0] = 0;
    fill(dp[0].begin(), dp[0].end(), 0);
    for(int i = 0; i<s1.size(); i++)
        dp[i][0] = 0;

	for (int i = 1; i <= s1.size(); i++)
    {
		for (int j = 1; j<= s2.size(); j++)
        {

			if (s1[s1.size() - i] == s2[s2.size() - j])
            	dp[i][j] = 1 + dp[i - 1][j - 1];
			else
             	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
    return dp[s1.size()][s2.size()];
}

int LCS(string s1, string s2, vector<vector<int>>& dp)
{
    if(s1.size() == 0 || s2.size() == 0)
    {
        return 0;
    }
    if(dp[s1.size()][s2.size()] > -1)
    {
        return dp[s1.size()][s2.size()];
    }
    if(s1[0] == s2[0])
    {
        dp[s1.size()][s2.size()] = 1 + LCS(s1.substr(1) , s2.substr(1), dp);
        return dp[s1.size()][s2.size()];
    }
    else
    {
        int r1 = LCS(s1.substr(1), s2, dp);
        int r2 = LCS(s1, s2.substr(1), dp);
        dp[s1.size()][s2.size()] = max(r1, r2);
        return dp[s1.size()][s2.size()];
    }
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;

    vector<vector<int>> dp(s1.size() + 1, vector<int>( s2.size() + 1 , -1));
    cout<<LCS(s1,s2,dp)<<endl;
    vector<vector<int>> dp1(s1.size() + 1, vector<int>( s2.size() + 1 , -1));
    cout<<iterative_LCS(s1,s2,dp1)<<endl;
    return 0;
}
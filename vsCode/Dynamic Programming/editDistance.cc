/*

Edit Distance - Problem

Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2

*/

#include "bits/stdc++.h"

using namespace std;

int solve(string s1, string s2, vector<vector<int>>& dp)
{
    if(s1.size() == 0)
    {
        return (s2.size());
    }
    if(s2.size() == 0)
    {
        return (s1.size());
    }
    if(dp[s1.size()][s2.size()] > -1)
    {
        return dp[s1.size()][s2.size()];
    }
    if(s1[0] == s2[0])
    {
        dp[s1.size()][s2.size()] = solve(s1.substr(1) , s2.substr(1), dp);
        return dp[s1.size()][s2.size()];
    }
    else
    {
        int r1 = 1 + solve(s1.substr(1), s2, dp);
        int r2 = 1 + solve(s1, s2.substr(1), dp);
        int r3 = 1 + solve(s1.substr(1) , s2.substr(1), dp);
        dp[s1.size()][s2.size()] = min( min(r1 , r3), r2);
        return dp[s1.size()][s2.size()];
    }
}

int editDistance(string s1, string s2)
{
    int size1 = s1.size();
    int size2 = s2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1 , -1));
    return solve(s1, s2, dp);
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<editDistance(s, t)<<endl;
    return 0;
}
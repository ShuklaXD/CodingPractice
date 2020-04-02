#include "bits/stdc++.h"

using namespace std;

int solve(int n,vector<int>A)
{
    vector<int> freq(1001, 0);

    for(int i = 0; i < n; i++)
    {
      freq[A[i]]++;
    }
    
    vector<int> dp(1001, 0);
    dp[1] = freq[1];
    for(int i = 2; i < 1001; i++)
    {
        dp[i] = max( dp[i - 2] + i * freq[i], dp[i - 1]);
    }
    return dp[1000];
}
#include <bits/stdc++.h>
#define mod(i) i%1000000007

using namespace std;

int countBST( int n)
{
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= n; i++)
    {
        long tmp1 = (long)dp[i - 1] * dp [i - 1];
        tmp1 = mod(tmp1);
        long tmp2 = (long)dp[i -1] * dp[i - 2] * 2;
        tmp2 = mod(tmp2);
        
        tmp1 += tmp2;
        
        dp[i] = (int)mod(tmp1);
    }
    return dp[n];
}
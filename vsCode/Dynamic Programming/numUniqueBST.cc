/*
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.

 1 234  
 1 2 34 
 12 3 4
 
 1234 5
 123 45
 12 345
 1 2345
 
 1 23456 42 
 1 2 3456 14
 12 3 456 10
 123 4 56 10
 1234 5 6 14
 12345 6 42
*/
#include <bits/stdc++.h>
#define mod(i) i%1000000007

using namespace std;

int countBST( int n)
{
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for(int i = 4; i <= n; i++)
    {
        long st = 0;
        for(int j = 0; j < i; j++)
        {
            st += (long)dp[j] * dp[(i - j) - 1];
            st = mod(st);
        }
        dp[i] = (int)st;
    }
    return dp[n];
}

int main()
{
    int i;
    cin>>i;
    cout<<countBST(i)<<endl;
    return 0;
}

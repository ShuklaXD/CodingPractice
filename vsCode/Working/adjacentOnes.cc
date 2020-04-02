#include<bits/stdc++.h>

using namespace std;

long dp[100][100][2];
int mod = 1e9+7;
long numCount(int n,int k,int start)
{
    // cout<<"n : "<<n<<" k : "<<k<<" start : "<<start<<endl;
    if( (k < 0) || (n == 0) || (n <= k) )
    {
        return 0;
    }
    if(n == 1)
    {
        if(k == 0)
        {
            return 1;
        }
        return 0;
    }
    if(n == k + 1)
    {
        if(start)
            return 1;
        else
            return 0;
    }
    if(start)
    {
        if( dp[n - 1][k][0] == -1)
        {
            dp[n - 1][k][0] = numCount(n-1, k, 0) % mod;
            // cout<<"Got : "<<dp[n - 1][k][0]<<endl;
        }
        if( dp[n-1][k - 1][1] == -1)
        {
            dp[n-1][k - 1][1] = numCount(n-1, k - 1, 1) % mod;
            // cout<<"Got : "<<dp[n - 1][k -1][1]<<endl;
        }
        // cout<<" n : "<<n<<" k : "<<k<<" Start : "<<start<<" Ans : "<<dp[n - 1][k][0] + dp[n-1][k - 1][1]<<endl;
        return (dp[n - 1][k][0] + dp[n-1][k - 1][1]) % mod;
    }
    else
    {
        if( dp[n - 1][k][0] == -1)
        {
            dp[n - 1][k][0] = numCount(n-1, k, 0) % mod;
            // cout<<"Got : "<<dp[n - 1][k][0]<<endl;
        }
        if( dp[n-1][k][1] == -1)
        {
            dp[n - 1][k][1] = numCount(n-1, k, 1) % mod;
            // cout<<"Got : "<<dp[n - 1][k][1]<<endl;
        }
        // cout<<" n : "<<n<<" k : "<<k<<" Start : "<<start<<" Ans : "<<dp[n-1][k][1] + dp[n-1][k][0]<<endl;
        return (dp[n-1][k][1] + dp[n-1][k][0]) % mod;
    }
}

int main()
{
    int p,a,n,k;
    cin>>p;
    for(int i = 1; i < 100; i++)
    {
        dp[i + 1][i][1] = 1;
    }
    while(p-->0)
    {
        memset(dp , -1 , sizeof(dp));
        cin>>a>>n>>k;
        cout<<a<<" "<<(int)((numCount(n, k, 0) % mod + numCount(n, k, 1) % mod) % mod)<<endl;
    }
}
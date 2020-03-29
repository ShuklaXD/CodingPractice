#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int arr[m][n], dp[m][n];
    memset(arr, 0, sizeof(arr));
    memset(dp, 0xc0, sizeof(dp));
    
    for(int i = 0; i < m; i++)
    {
        for(int i = 0; i < n; i++)
        {
            cin>>arr[m][n];
        }
    }
    dp[m-1][n-1] = arr[m-1][n-1];
    for(int i = m -2; i >= 0; i--)
        dp[i][n - 1] = dp[i + 1][n - 1] + arr[i][n - 1];
    for(int i = n -2; i >= 0; i--)
        dp[m - 1][i] = dp[m - 1][i + 1] + arr[m - 1][i];
    
    for(int i = m - 2; i >= 0; i--)
    {
        for(int j = n - 2; j >=0; j--)
        {
            
        }
    }

    
    return 0;
}

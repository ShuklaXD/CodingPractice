#include "bits/stdc++.h"
#define mod(i) i%1000000007
using namespace std;

int main()
{
    int size;
    cin>>size;
    vector<int> values(size);
    vector<vector<long>> dp(size, vector<long>(101, 0));
    for(int i = 0; i < size; i++) cin>>values[i];

    for(int i = 0; i < size; i++)
    {
        dp[i][values[i]] = 1;
        for(int k = i - 1; k >= 0; k--)
        {
            if(values[k] < values[i])
            {
                for(int gc = 1; gc <= 100; gc++)
                {
                    if( dp[k][gc] > 0 )
                    {
                        int ngc = __gcd(values[i], gc);
                        dp[i][ngc] += dp[k][gc];
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < size; i++)
    {
        ans = mod(dp[i][1] + ans);
    }

    cout<<ans;
    return 0;
}


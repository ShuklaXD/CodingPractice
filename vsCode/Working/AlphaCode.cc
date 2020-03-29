#include <bits/stdc++.h>
#define toInt(i) i - 48
#define mod(i) i%1000000007

using namespace std;

int main()
{
    string s = "";
    while(true)
    {
        cin>>s;
        if(s == "0")
            break;
        else
        {
            int size = s.size();
            int dp[size + 1];
            dp[0] = dp[1] = 1;
            for(int i = 2; i <= size; i++)
            {
                dp[i] = 0;
                char c1 = s[i - 2] - '0', c2 = s[i - 1] - '0';

                if( (c1 == 1)|| ( (c1 == 2) && (c2 <= 6) ) )
                {
                    long tmp = (long)dp[i] + dp[i - 2];
                    dp[i] = (int)mod(tmp);
                }
                if(c2 != 0)
                {
                    long tmp = (long)dp[i] + dp[i - 1];
                    dp[i] = (int)mod(tmp);
                }
            }
            cout<<dp[size]<<endl;
        }
    }
    return 0;
}
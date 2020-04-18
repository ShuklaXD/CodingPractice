#include <bits/stdc++.h>
using namespace std;

int s1,s2;

int dp[101][101];


void iterative(string a, string b, int t)
{
    int sz1 = a.size();
    int sz2 = b.size();

    vector<vector<vector<int>>> dp(sz1 + 1 , vector<vector<int>>( sz2 + 1 , vector<int> (t+1, 0)));

    for(int i = 1; i<= sz1; i++)
    {
        for(int j = 1; j<= sz2; j++)
        {
            if(a[i-1] == b[j-1])
            {           
                for(int k = 1; k<=t && (k<=j || k<=i); k++)
                {
                    if(k == 1 || dp[i-1][j-1][k-1] > 0)
                        dp[i][j][k] = max(dp[i-1][j-1][k], dp[i-1][j-1][k-1] + a[i-1]);
                    // cout<<"dp "<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<" ";
                }
            // cout<<endl;
            }
        }
    }
    int max = INT_MIN;
    for(int i = 1; i<= sz1; i++)
    {
        for(int j = 1; j<= sz2; j++)
        {
            // for(int k = 0; k <=t ; k++)
            //     cout<<dp[i][j][t]<<" ";
            if(max < dp[i][j][t])
                max = dp[i][j][t];
            // cout<<"||";
        }
        // cout<<endl;
    }
    cout<<max<<endl;
}
void findSub(string a, string b, int k, int s1i, int s2i, string& res)
{
    if(s1i == s1 || s2i == s2)
    {
        return;
    }
    
    if(a[0] == b[0])
    {   
        // findSub( a.substr(1), b.substr(1), k, s1i+1, s2i+1, res);	//ignored letter completely
        if(k==0)		//maintaining max ascii value
        {
            sort(res.begin(), res.end());
            if(a[0] > res[0])
            {
                res = res.substr(1) + a[0];
            }
        }
        else
        {
            res+=a[0];
        }
        
        findSub( a.substr(1), b.substr(1),k - 1, s1i+1, s2i+1, res);	//using new max   
    }
    else
    {
        findSub(a.substr(1),b,k,s1i+1,s2i,res);
        findSub(a,b.substr(1),k,s1i,s2i+1,res);
    }
}

void solve()
{
	string a,b;
    int k;
    cin>>a>>b>>k;
    s1 = a.size();
    s2 = b.size();
    // memset(dp, -1, sizeof(dp));
    // string res = "";
    // findSub(a,b,k,0,0,res);
    // cout<<res<<endl;
    iterative(a,b,k);
}

int main()
{
    int cases;
    cin>>cases;
    while(cases-->0)
        solve();
    return 0;
}

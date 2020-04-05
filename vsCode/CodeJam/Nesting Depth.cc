#include "bits/stdc++.h"

//ques 2
using namespace std;

void solve(int i)
{
    string in;
    cin>>in;
    vector<int> dp;
    for(char c : in)
    {
        dp.push_back(c - 48);
    }
    int degree = 0, pos = 0;
    for( int i = 0; i < dp.size(); i++)
    {
        if(degree < dp[i])
        {
            string prefix = in.substr(0,pos), suffix = in.substr(pos);
            for(int j = 0; j < dp[i] - degree; j++)
            {
                prefix += '(';
                pos++;
            }
            prefix += suffix;
            degree = dp[i];
            in = prefix;
        }
        else if(degree > dp[i])
        {
            string prefix = in.substr(0,pos), suffix = in.substr(pos);
            for(int j = 0; j < (degree - dp[i]); j++)
            {
                prefix += ')';
                pos++;
            }
            prefix += suffix;
            in = prefix;
            degree = dp[i];
        }
        pos++;
    }
    for(int i = 0; i < degree; i++)
    {
        in += ")";
    }
    cout<<"Case #"<<i<<": "<<in<<endl;
}

int main()
{
    int cases;
    cin>>cases;
    int i = 1;
    while(cases-->0)
    {
        solve(i++);
    }
    return 0;
}
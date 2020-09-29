#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a,b,c,d,n,m,k;
    cin>>n>>a>>b;
    if(a*b < n)
    {
        cout<<"-1"<<endl;
        return;
    }
    else
    {
        vector<int> bowler(a+1, b);
        vector<int> ans(n, 0);
        int j = 0, p = -1;
        for(int i = 0; i < n; i++)
        {
            j = j % a + 1;
            if(bowler[j] && j != p)
            {
                ans[i] = j;
                p = j;
            }
            else
            {
                cout<<-1<<endl;
                return;
            }
        }
        for(int i : ans)
            cout<<i<<" ";
        cout<<endl;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    cin>>cases;

    while(cases-->0)
    {
        solve();
    }
    return 0;
}

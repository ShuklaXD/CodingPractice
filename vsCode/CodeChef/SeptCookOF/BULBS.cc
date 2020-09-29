#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for (int i = a; i < b; i++)

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return ((double)a.first / a.second) > ((double)b.first / b.second);
}
void solve()
{
    int a,b,c,d,n,m,k;
    cin>>n>>k;
    string target;
    For(i,0,n)  cin>>target[i];
    vector<pair<int,int>> zeroes;
    
    for(int i = 0; i < n; i++)
    {
        int len = 0, start = i, end = i;
        while(i < n && target[i] == '0')
        {
            len++;
            end++;
            i++;
        }
        if(len > 0)
        {
            if((start == 0) || (end == n-1))
                zeroes.push_back({len,1});
            else            
                zeroes.push_back({len,2});
        }
    }
    sort(zeroes.begin(), zeroes.end(), comp);
    int i = 0;
    for(; i < zeroes.size() && k > 0; i++)
    {
        if(k >= zeroes[i].second)
        {
            zeroes[i].first = 0;
            k-=zeroes[i].second;
        }
    }
    int ans = 0;
    for(auto p : zeroes)
    {
        ans+=p.first;
    }
    cout<<ans<<endl;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    cin>>cases;

    For(i,0,cases)
    {
        solve();
    }
    return 0;
}

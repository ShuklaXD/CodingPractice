#include "bits/stdc++.h"

//
using namespace std;

bool ans(int n, vector<pair<int, int>> k, multimap<pair<int, int>, char>& op, int c_free, int j_free, int j)
{
    if(j == n)  //all intervals addressed
    {
        return true;
    }
    else
    {
        if(c_free <= k[j].first)
        {
            op.insert(make_pair(k[j], 'C'));
            c_free = k[j].second;
            if(ans(n,k,op,c_free,j_free,j+1))
                return true;
            else
                return false;
        }
        else if(j_free <= k[j].first)
        {
            op.insert(make_pair(k[j], 'J'));
            j_free = k[j].second;
            if(ans(n,k,op,c_free,j_free,j+1))
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
    }
}


void solve(int i)
{
    int n;
    cin>>n;

    vector<pair<int, int>> input(n), copy(n);

    for(int i= 0; i < n; i++)
    {
        cin>>input[i].first>>input[i].second;
    }
    cout<<"Case #"<<i<<": ";
    copy = input;
    sort(copy.begin(), copy.end());
    multimap<pair<int, int>, char> res;
    if(ans(n, copy, res, 0, 0, 0))
    {
        string r = "";
        int i = 0;
        for(auto f : input)
        {
            for(multimap<pair<int, int>, char>::iterator it = res.begin(); it != res.end() && i < n; it++)
            {
                if(it->first == f)
                {
                    r+=it->second;
                    res.erase(it);
                    i++;
                    break;
                }
            }
        }
        cout<<r<<endl;
    }
    else
        cout<<"IMPOSSIBLE"<<endl;
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
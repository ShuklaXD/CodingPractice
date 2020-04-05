#include "bits/stdc++.h"

//ques 2
using namespace std;

bool overlap(vector<pair<int, int>>& checker, pair<int, int>& value)
{
    for( pair<int, int> check : checker)
    {
        if( value.first < check.first && value.second > check.first)
        {
            return true;
        }
        if( value.first < check.second && value.second > check.first)
        {
            return true;
        }
        if( value.first < check.first && value.second > check.second)
        {
            return true;
        }
    }
    return false;
}

bool ans(vector<pair<int, int>>& input, int n)
{
    string r = "";
    vector<pair<int, int>> cameron, jamie;

    for(pair<int, int> in : input)
    {
        if(!overlap(cameron , in))
        {
            cameron.push_back(in);
            r += 'C';
            continue;
        }
        else if(!overlap(jamie, in))
        {
            jamie.push_back(in);
            r += 'J';
            continue;
        }
        else
        {
            return false;
        }
    }
    cout<<r<<endl;
    return true;
}


void solve(int i)
{
    int n;
    cin>>n;
    vector<pair<int, int>> input(n);
    map<pair<int, int>, int> uniq;
    for(int i= 0; i < n; i++)
    {
        cin>>input[i].first>>input[i].second;
    }
    
    cout<<"Case #"<<i<<": ";
    if(!ans(input, n))
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
#include "bits/stdc++.h"

//ques 2
using namespace std;

bool findd(multimap<pair<int, int>, char>& op, pair<int, int>& v, char ch)
{
    // char sec = (ch == 'C') ? 'J' : 'C';
    // bool one = true, two = true;    //insertion valid
    // for(map<pair<int, int>, char>::iterator it = op.begin(); it != op.end(); it++)
    // {
    //     if(it->first == v)
    //     {
    //         if(it->second == ch)
    //             one = false;    //already present
    //         if(it->second == sec)
    //             two = false;
    //     }
    // }

    // return one | two;

    for(multimap<pair<int, int>, char>::iterator it = op.begin(); it != op.end(); it++)
    {
        if(it->first == v)
        {
            if(it->second == ch)
                return true;
        }
    }
    return false;
}

bool ans(int n, vector<pair<int, int>> k, multimap<pair<int, int>, char>& op, int c_free, int j_free, int j)
{
    if(j == n)
    {
        return true;
    }
    else
    {       
        if(k[j].second >= c_free)
        {
            if(findd(op, k[j],'C'))
            {
                if(k[j].second >= j_free)
                {
                    if(findd(op, k[j],'J'))
                        return false;
                    else
                    {
                        op.insert(make_pair(k[j], 'J'));
                        j_free = k[j].first;
                        if(ans(n,k,op,c_free,j_free,j+1))
                            return true;    
                        else
                            return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                op.insert(make_pair(k[j], 'C'));
                c_free = k[j].first;
                if(ans(n,k,op,c_free,j_free,j+1))
                    return true;
                else
                    return false;
            }
        }
        else
        {
            if(k[j].second >= j_free)
            {
                if(findd(op, k[j],'J'))
                {
                    if(k[j].second >= c_free)
                    {
                        if(findd(op, k[j],'C'))
                            return false;
                        else
                        {
                            op.insert(make_pair(k[j], 'C'));
                            c_free = k[j].first;
                            if(ans(n,k,op,c_free,j_free,j+1))
                                return true;
                            else
                                return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    op.insert(make_pair(k[j], 'J'));
                    j_free = k[j].first;
                    if(ans(n,k,op,c_free,j_free,j+1))
                        return true;
                    else
                        return false;   
                }
            }
            else
            {
                return false;
            }
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
        cin>>input[i].second>>input[i].first;
        if(input[i].second > input[i].first)
        {
            input[i].first += 1500;
        }
    }
    cout<<"Case #"<<i<<": ";
    copy = input;
    multimap<pair<int, int>, char> res;
    sort(input.begin(), input.end());
    if(ans(n, input, res, 0, 0, 0))
    {
        string r = "";
        int i = 0;
        for(auto f : copy)
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
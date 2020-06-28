#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

/*
input size required time complexity 
n≤10 		O(n!) 
n≤20 		O(2^n) 
n≤500 		O(n^3) 
n≤5000 		O(n^2) 
n≤10^6		O(nlogn) or O(n) 
n is large	O(1) or O(logn)
*/

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vp;

#define F first 
#define S second 
#define PB push_back 
#define MP make_pair
#define sv(a) sort(a.begin(), a.end())
#define sz(a) a.size()

#define foreach(i,a,b) for (int i = a; i <= b; i++)
#define fo(i,n) for (int i = 0; i < n; i++)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/

// int max(int a, int b)
// {
//     if(a > b)
//         return a;
//     return b;
// }

int minNumberOfFrogs(string cf) {
    int c = 0, r= 0, o = 0, a = 0, ma = 0;

    for(char ch : cf)
    {
        if(ch == 'c')
        {
            if(c <= max({r,o,a}))
                c++;
            if(ma < c)
                ma = c;
        }
        else if(ch == 'r')
        {
            if(c > 0)
            {
                r++;
            }
            else
            {
                return -1;
            }
        }
        else if(ch == 'o')
        {
            if(r > 0)
            {
                o++;
            }
            else
            {
                return -1;
            }
        }
        else if(ch == 'a')
        {
            if(o > 0)
            {
                a++;
            }
            else
            {
                return -1;
            }
        }
        else if(ch == 'k')
        {
            if(a > 0)
            {
                c--;
                r--;
                o--;
                a--;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    if(c+r+o+a > 0)
    {
        return -1;
    }
    return ma;
}
int minNumberOfFrogs1(string cf) {
    int max = 0;
    vector<stack<char>> frogs;
    for(char c: cf)
    {
        if(c == 'c')
        {
            bool stfree = false;
            for(int i = 0; i < max; i++)
            {
                if(frogs[i].top() == ' ')
                {
                    frogs[i].push(c);
                    stfree = true;
                    break;
                }
            }
            if(max == 0 || !stfree)
            {
                max++;
                stack<char> st;
                st.push(c);
                frogs.push_back(st);
            }
        }
        else if(c == 'r')
        {
            bool stfree = false;
            for(int i = 0; i < max; i++)
            {
                if(frogs[i].top() == 'c')
                {
                    frogs[i].push(c);
                    stfree = true;
                    break;
                }
            }
            if(!stfree)
                return -1;
        }
        else if(c == 'o')
        {
            bool stfree = false;
            for(int i = 0; i < max; i++)
            {
                if(frogs[i].top() == 'r')
                {
                    frogs[i].push(c);
                    stfree = true;
                    break;
                }
            }
            if(!stfree)
                return -1;
        }
        else if(c == 'a')
        {
            bool stfree = false;
            for(int i = 0; i < max; i++)
            {
                if(frogs[i].top() == 'o')
                {
                    frogs[i].push(c);
                    stfree = true;
                    break;
                }
            }
            if(!stfree)
                return -1;
        }
        else if(c == 'k')
        {
            bool stfree = false;
            for(int i = 0; i < max; i++)
            {
                if(frogs[i].top() == 'a')
                {
                    frogs[i].push(' ');
                    stfree = true;
                    break;
                }
            }
            if(!stfree)
                return -1;
        }
        else
        {
            return -1;
        }
    }
    return max;
}

void solve()
{
    string s = "crcoakroak";
    cout<<minNumberOfFrogs(s);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;

    // cin>>cases;

    while(cases-->0)
        solve();

    return 0;
}

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
typedef pair<int,int> pi;

#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/
bool backspaceCompare(string s, string T) {
    
    stack<char> s1,s2;
    for(char c : s)
    {
        if(c == '#')
        {    if(s1.size())
                s1.pop();
        }
        else
        {
            cout<<c<<" ";
            s1.push(c);
        }
            
    }
    for(char c : T)
    {
        if(c == '#')
        {
            if(s2.size())
                s2.pop();
        }
        else
        {
            cout<<c<<" ";
            s2.push(c);
        }
    }
    if(s1.size() != s2.size())
        return false;
    else
    {
        while(s1.size() > 0)
        {
            if(s1.top() != s2.top())
                return false;
            s1.pop();
            s2.pop();
        }
    }
    return true;
}

void solve()
{
    string a = "xywrrmp", b = "xywrrmu#p";

    cout<<backspaceCompare(a,b);
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

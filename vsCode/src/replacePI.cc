#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vp;

#define sv(a) sort(a.begin(), a.end())
#define sz(a) a.size()

#define foreach(i,a,b) for (int i = a; i <= b; i++)
#define fo(i,n) for (int i = 0; i < n; i++)
#define deb(x) cout << #x << x << endl;

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/

int size(char *a)
{
    int s = 0;
    for(;a[s]!='\0';s++){}
    return s;
}

void shift(char *a, int curr, int sz)
{
    for(int i = sz; i > curr+1; i--)
    {
        a[i+2] = a[i];
    }
    a[curr++] = '3';
    a[curr++] = '.';
    a[curr++] = '1';
    a[curr++] = '4';
   // a[sz+2] = '\0';
}

void replace(char *a, int curr)
{
    int sz = size(a);
    if(sz - curr < 2)
        return;
    if(a[curr] == 'p' && a[curr+1] == 'i')
    {
        shift(a, curr, sz);
        curr += 4;
    }
    else
        curr++;
    replace(a, curr);
}

void solve()
{
    char input[10000] = "ppipippip";
    int sz = size(input);
    replace(input, 0);
    sz = size(input);
    
    cout<<input<<endl;
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

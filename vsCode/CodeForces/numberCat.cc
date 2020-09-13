#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define vsort(a) sort(a.begin(), a.end())
#define sizeOf(a) a.size()

#define For(i,a,b) for (int i = a; i < b; i++)
#define deb(x) cout << #x << " : " << x << endl;
#define isBitSet(S, i) ((S >> i) & 1)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;


void solve()
{
    int a,b,c,d,n,m,k;
    string s;
    cin>>s;
    int neg = 0;

    if(s.size() < 3)
    {
        cout<<"byte"<<endl;
        return;
    }
    else if(s.size() < 5)
    {
        if(stoi(s) <= 127)
            cout<<"byte"<<endl;
        else
            cout<<"short"<<endl;
    }
    else if(s.size() < 10)
    {
        if(stoi(s) <= 32767)
            cout<<"short"<<endl;
        else
            cout<<"int"<<endl;
    }
    else if(s.size() < 19)
    {
        long tmp = stol(s);
        if(tmp <= long(2147483647))
            cout<<"int"<<endl;
        else
            cout<<"long"<<endl;
    }
    else
    {
        if(s.size() == 19)
        {
            string t = s.substr(1);
            if(s[0] < '9')
                cout<<"long";
            else
            {
                long tmp = stol(t);
                if(tmp <= long(223372036854775807))
                    cout<<"long"<<endl;
                else
                {
                    cout<<"BigInteger"<<endl;
                }
            }
        }
        else
            cout<<"BigInteger"<<endl;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    // cin>>cases;

    For(i,0,cases)
    {
        // cout << "Case #"<<i<<": ";
        solve();
        // cout <<"\n"[i==cases-1];
    }
    return 0;
}

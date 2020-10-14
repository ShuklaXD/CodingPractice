#include <bits/stdc++.h>
#include <stdio.h> 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define sortn(a) sort(a.begin(), a.end())
#define rep(n) for (int i = 0; i < n; i++)
#define forn(i,a,b) for (int i = a; i < b; i++)
#define deb(x) cout << #x << " : " << x << endl;
#define isBitSet(S, i) ((S >> i) & 1)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;
// int 2 * 1e9
// long long 9 * 1e18

int g (int n) {
    return n ^ (n >> 1);
}

void solve(int case_num)
{
    int n;
    cin>>n;
    
    if(n == 1)
    {
        cout<<1<<endl;
        return;
    }
    int cnt = 0, index = 0;
    while(index < 32)
    {
        if((n>>index++)&1)    cnt++;
    }
    if(cnt == 1)
    {
        cout<<-1<<endl;
        return;
    }
    else
    {
        if(n >= 3)
        {
            cout<<"2 3 1 ";
        }
        int power = 2;
        int i = 4;
        for(; i+1 <= n; i++)
        {
            if(i == 1 << power)
            {
                cout<<i+1<<" "<<i<<" ";
                i++;
                power++;
            }
            else
            {
                cout<<i<<" ";
            }
        }
        if(i <= n) cout<<n<<endl;
        else    cout<<endl;
    }
}

int main() 
{
    #ifdef LOCAL_PROJECT
    freopen("/home/shubham/CodingPractice/vsCode/input.txt", "r", stdin);
    freopen("/home/shubham/CodingPractice/vsCode/output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    cin>>cases;
    forn(i,0,cases)
    {
        solve(i);
    }
    return 0;
}

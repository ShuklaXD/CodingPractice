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

bool zAlgo(string a, string b){
    int l = 1,r = 1;
    a = b+"$"+a;
    int as = a.size();
    int bs = b.length();
    vector<int> z(a.size(), 0);

    int i = 1;

    while(i < as){

        if(l < r){
            if(z[i - l]+i <= r){
                z[i] = z[i-l];
                i++;
                continue;
            }
            else{
                int j = r, ti = i;
                while(j < as && ti < as && a[j++] == a[ti++]){}
                z[i] = ti-1-i;
                l = i;
                r = l+z[i]-1;
                i++;
            }
        }
        else{
            int j = 0, ti = i;
            while(j < as && ti < as && a[j++] == a[ti++]){}
            z[i] = ti-1-i;
            l = i;
            r = l+z[i]-1;
            i++;
        }
    }

    for(int i = 0; i < as ; ++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    for(int i = 0; i < as ; ++i){
        cout<<z[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str,reg;
    cin>>str>>reg;
    zAlgo(str, reg);
}

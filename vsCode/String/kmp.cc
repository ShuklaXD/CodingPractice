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
vi longestPrefixSuffix(string a){
    vi prefix(a.size(), 0);

    int i = 1, j = 0;
    while(i < a.size()){
        if(a[i]==a[j]){
            prefix[i++] = (j++)+1;
        }
        else{
            if(j!=0){
                j = prefix[j-1];
            }
            else{
                prefix[i++] = 0;
            }
        }
    }
    return prefix;
}

bool kmp(string pattern, string reg){
    int lenPattern = pattern.size();
    int lenReg = reg.size();

    int i=0, j=0;

    vi lps = longestPrefixSuffix(pattern);
    while(i < lenPattern && j < lenPattern){
        if(pattern[i] == reg[j]){
            i++;
            j++;
        } else{
            if(j!=0){
                j = lps[j-1];
            } else{
                i++;
            }
        }
    }
    if(j == lenReg)
        return true;
    return false;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    vi prefix = longestPrefixSuffix(str);

    fo(i,str.size())
        cout<<str[i]<<" ";
    cout<<endl;
    fo(i,str.size())
        cout<<prefix[i]<<" ";
}

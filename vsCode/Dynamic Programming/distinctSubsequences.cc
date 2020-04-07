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


const int MAX_CHAR = 256; 
  
// Returns count of distinct sunsequences of str. 
void countSub() 
{ 
    string str;
    cin>>str;

    // Create an array to store index 
    // of last 
    vector<int> last(MAX_CHAR, -1); 
  
    // Length of input string 
    int n = str.length(); 
  
    // dp[i] is going to store count of distinct 
    // subsequences of length i. 
    vector<int> dp(n + 1, 0);
  
    // Empty substring has only one subsequence 
    dp[0] = 1; 
  
    // Traverse through all lengths from 1 to n. 
    for (int i = 1; i <= n; i++) { 
        // Number of subsequences with substring 
        // str[0..i-1] 
        dp[i] = (int)( ((ll)dp[i-1]<<1) % mod );
  
        cout<<"dp "<<i<<" : "<<dp[i]<<endl;
        // If current character has appeared 
        // before, then remove all subsequences 
        // ending with previous occurrence. 
        if (last[str[i - 1]] != -1)
            dp[i] = ((dp[i]%mod) - (dp[last[str[i - 1]]]%mod))%mod;
        
        if(dp[i] < 0)
        {
            dp[i] = (dp[i] + mod)%mod;
        }
  
        // Mark occurrence of current character
        last[str[i - 1]] = (i - 1);
    }
  
    cout<< dp[n]<<endl; 
} 

void solve()
{
	string s;
    cin>>s;

    int sz = s.size();
    vi dp(sz + 1, 0);
    dp[sz] = 2;
    s += '.';
    for(int i = sz-1; i>=0; i--)
    {
        int j = i+1;
        for(char c : s.substr(i+1, sz))
        {
            if(c != s[i])
            {
                dp[i] += (int)((dp[j++])%mod);
            }
            else
            {
                dp[i]++;
            }
            
        }
        cout<<"dp "<<i<<" "<<dp[i]<<endl;
    }
    cout<<dp[0]<<endl;
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cases = 1;

	cin>>cases;

	while(cases-->0)
		countSub();
	
	return 0;
}

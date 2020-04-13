// #include <bits/stdc++.h>

// using namespace std;
// // int 2 * 1e9
// // long long 9 * 1e18

// /*
// input size required time complexity 
// n≤10 		O(n!) 
// n≤20 		O(2^n) 
// n≤500 		O(n^3) 
// n≤5000 		O(n^2) 
// n≤10^6		O(nlogn) or O(n) 
// n is large	O(1) or O(logn)
// */

// typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int,int> pi;

// #define F first 
// #define S second 
// #define PB push_back 
// #define MP make_pair

// #define Fo(i,a,b) for (int i = a; i < b; i++)
// #define fo(i,n) for(int i = 0; i < n; i++)
// #define srt(a)  sort(a.begin(), a.end())
// #define srtc(a, b)  sort(a.begin(), a.end(), b)
// #define deb(x) cout<<#x<<" "<<x<<endl;


// const int INF = 1e6 + 5;
// const int mod = 1e9 + 7;

// void solve()
// {
// 	int n, k;
//     cin>>n>>k;
//     vi arr(n, 0), dp(n,0);
//     fo(i,n) cin>>arr[i];

//     srt(arr);

//     int sumTillk = 0;

//     fo(i,k)
//     {
//         Fo(j,i+1,k)
//         {
//             dp[k-1] += abs(arr[i] - arr[j]);
//         }
//         sumTillk += arr[i];
//     }

//     sumTillk -= arr[0];

//     Fo(i, k, n)
//     {
//         int tmp = (dp[i-1] + (k-1)*arr[i] + (k-1)*arr[i-k] - 2*sumTillk);
//         dp[i] = tmp;
//         sumTillk -= arr[i + 1 -k];
//         sumTillk += arr[i]; 
//     }
//     // deb(dp[n-1]);
//     int ans = INT_MAX;
//     Fo(i,k-1,n)
//     {
//         if(ans > dp[i])
//             ans = dp[i];
//     }
//     cout<<ans;
// }

// int main() 
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);

// 	int cases = 1;

// 	// cin>>cases;

// 	while(cases-->0)
// 		solve();
	
// 	return 0;
// }


#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

/*
input size required time complexity 
nâ¤10 		O(n!) 
nâ¤20 		O(2^n) 
nâ¤500 		O(n^3) 
nâ¤5000 		O(n^2) 
nâ¤10^6		O(nlogn) or O(n) 
n is large	O(1) or O(logn)
*/

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;

#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

#define Fo(i,a,b) for (int i = a; i < b; i++)
#define fo(i,n) for(int i = 0; i < n; i++)
#define srt(a)  sort(a.begin(), a.end())
#define srtc(a, b)  sort(a.begin(), a.end(), b)
#define deb(x) cout<<#x<<" "<<x<<endl;


const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

void solve()
{
	ll n, k;
    cin>>n>>k;
    vi arr(n, 0);
    fo(i,n) cin>>arr[i];

    srt(arr);

    ll sumTillk = arr[0];
    ll target = 0;
    for(int i=1;i<k;i++)
    {
        target = target + i*arr[i] - sumTillk;
        sumTillk += arr[i];
    }
    ll cost = target;
    Fo(i, k, n)
    {
        sumTillk = sumTillk - arr[i-k];
        target = target - 2*(sumTillk) + (k-1)*arr[i-k] + (k-1)*arr[i];
        sumTillk = sumTillk + arr[i];
        cost = min(target,cost);
    }

    cout<<cost;
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
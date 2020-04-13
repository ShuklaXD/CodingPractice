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

class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b)
    {
        if(a.first == b.first)
        {
            return a.second < b.second;
        }
        else
            return a.first < b.first;
    }
    int getKth(int lo, int hi, int k) {
        map<int, int> dp;
        
        for(int i = lo; i <=hi; i++)
        {
            int num = i;
            if(dp.find(i) == dp.end())
            {
                int cnt = 0;
                while(num != 1)
                {
                    if(dp.find(num) != dp.end())
                    {
                        cnt+=dp[num];
                        break;
                    }
                    cnt++;
                    if(num&1)
                    {
                        num = 3*num + 1;
                    }
                    else
                    {
                        num = num>>1;
                    }
                }
                dp[i] = cnt;
                // cout<<i<<" : "<<dp[i]<<endl;
            }
        }
        vector<pair<int, int>> ranger(hi-lo+1);
        for(int i = 0; i < hi-lo+1; i++)
        {
            ranger[i].first = dp[lo+i];
            ranger[i].second = lo + i;
        }
        sort(ranger.begin(), ranger.end(), compare);
        
        return ranger[k-1].second;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int lo = stringToInteger(line);
        getline(cin, line);
        int hi = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().getKth(lo, hi, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
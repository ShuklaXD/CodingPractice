#include "bits/stdc++.h"
#include "map"

using namespace std;

int minCount(int n){
    set<int> squares;
    int sq = 1;
    for(int i = 1; sq < n; i++)
    {
        sq = i * i;
        squares.insert(sq);
    }
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    int prev = 1;
    for(int i = 2; i <= n; i++)
    {
        if(squares.find(i) != squares.end())
        {
            dp[i] = 1;
            prev = i;
        }
        else
        {
            int min = INT_MAX;
            for(auto sq : squares)
            {
                if(sq < i)
                {
                    int tmp = 1 + dp[i - sq];
                    if(min > tmp)
                        min = tmp;
                }
            }
            dp[i] = min;
        }
    }
    return dp[n];
}

int main(){
    
    int num;
    cin >> num;
    cout << minCount(num);
    
}
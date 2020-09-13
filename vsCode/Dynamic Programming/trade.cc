#include <bits/stdc++.h>

using namespace std;

int profit;
const int INF = 1e6;

void trade(vector<int> &arr, int curr, int k, int cost, bool buy)
{
    if (k == 0)
    {
        if (profit < cost)
            profit = cost;
        return;
    }
    if (curr == arr.size())
    {
        return;
    }
    trade(arr, curr + 1, k, cost, buy);
    if (buy)
    {
        trade(arr, curr + 1, k, cost - arr[curr], !buy);
    }
    else
    {
        cost += arr[curr];
        if (profit < cost)
            profit = cost;
        trade(arr, curr + 1, k - 1, cost, !buy);
    }
}

void tr(vector<int> &arr, int k)
{
    int sz = arr.size();
    vector<vector<int>> buy(k + 1, vector<int>(sz + 1, -INF));
    vector<vector<int>> sell(k + 1, vector<int>(sz + 1, 0));

    for (int tk = 1; tk <= k; tk++)
    {
        for (int i = 1; i <= sz; i++)
        {
            buy[tk][i] = max(buy[tk][i - 1], sell[tk - 1][i - 1] - arr[i - 1]);
            sell[tk][i] = max(sell[tk][i - 1], buy[tk][i - 1] + arr[i - 1]);
        }
    }

    // for(int tk = 1; tk<=k; tk++)
    // {
    //     for(int i = 1; i <= sz; i++)
    //     {
    //         cout<<"  buy ["<<tk<<"]["<<i<<"] : "<<buy[tk][i];
    //         cout<<"  sell ["<<tk<<"]["<<i<<"] : "<<sell[tk][i];
    //     }
    //     cout<<endl;
    // }

    int best = 0;
    for (int i = 1; i <= sz; i++)
    {
        if (best < sell[k][i])
            best = sell[k][i];
    }
    cout << best << endl;
}

void solve()
{
    int k, n;
    cin >> k >> n;
    profit = 0;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    tr(arr, k);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases-- > 0)
        solve();
    return 0;
}

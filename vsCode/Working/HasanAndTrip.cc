#include<bits/stdc++.h>

using namespace std;

// float distance(int x1, int y1, int x2, int y2) 
// { 
//     // Calculating distance 
//     return sqrt(pow(x2 - x1, 2) +  
//                 pow(y2 - y1, 2) * 1.0); 
// }

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

void minCount(int n){
    vector<double> dp(n, INT_MIN);

    vector<double> x(n, 0), y(n, 0), h(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i]>>h[i];
    }

    dp[0] = h[0];


    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            dp[j] = max( dp[i] + h[j] - dist(x[i], y[i], x[j], y[j]), dp[j] );
        }
    }
    
    for(int i = 0; i < n; i++) cout<<dp[i]<<endl;
    cout << fixed << setprecision(6) << dp[n - 1] <<endl; 
}

int main()
{
    int n; cin>>n;
    minCount(n);
}
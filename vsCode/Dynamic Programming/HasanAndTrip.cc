/*
Hasan and Trip

Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line contain integer N.
Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.
Output format:
Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get. Note: If answer is 2 print 2.000000
Constraints:
1 <= N <= 3,000
0 <= Xi, Yi, Fi <= 100,000
Sample Input
3
0 0 1
3 1 1
6 0 9
Sample Output
4.675445

*/
#include<bits/stdc++.h>

using namespace std;

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
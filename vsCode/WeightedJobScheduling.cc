/*Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
sample input 2
8
3455 5829 2447
1778 6621 3585
5786 8113 5087
807 10139 8713
2637 10599 8208
3913 11083 7236
4652 14046 1486
15000 19303 9710

9
2122 3730 9766
2279 4578 2638
1232 6635 4654
5614 8305 6354
4116 8603 881
4370 11606 1389
2369 12084 9463
10316 12317 7917
8105 18245 4820

*/

#include<bits/stdc++.h>
using namespace std;

struct jobs
{
    int start;
    int end;
    int profit;
};

bool compare(jobs& j1, jobs& j2)
{
    return (j1.end < j2.end);
}

int main()
{
    //Array input
    int size = 0;
    cin>>size;
    jobs arr[size];
    for(int i = 0; i < size; i++){
        cin>>arr[i].start>>arr[i].end>>arr[i].profit;
    }
    
    sort(arr, arr + size, compare);

    int profits[size];
    profits[0] = arr[0].profit;

    int max_profit = 0;

    for(int i = 1; i < size; i++)
    {
        int inc = 0, exc = profits[i-1];
        int max_prev = 0;
        int low = 0, high = i - 1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid].end <= arr[i].start)
            {
                low = mid + 1;
                max_prev = profits[mid];
            }
            else
                high = mid - 1;
        }

        inc = max_prev + arr[i].profit;

        // for(int j = i - 1; j >= 0; j--)
        // {
        //     if(arr[j].end <= arr[i].start)
        //     {
        //         worthyElem = true;
        //         inc = profits[j] + arr[i].profit;
        //         break;
        //     }
        // }
        profits[i] = (inc > exc) ? inc : exc;
        max_profit = (max_profit > profits[i]) ? max_profit : profits[i];
    }
    cout<<max_profit<<endl;
    return 0;
}
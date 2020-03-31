#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = a[0]; 
    int curr_max = a[0]; 

    for (int i = 1; i < size; i++) 
    { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max);
    } 
    return max_so_far;
} 

int main()
{
    int rows, cols;
    cin>> rows>> cols;
    int arr[rows][cols];
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin>>arr[i][j];
        }
    }

    int maxArea = INT_MIN;

    int runningRowSum[rows];
    for(int cl = 0; cl < cols; cl++)
    {
        //moving start point
        memset(runningRowSum, 0 , sizeof(runningRowSum));
        for(int cr = cl; cr < cols; cr++)
        {
            //moving end point
            for(int r = 0; r < rows; r++)
            {
                //updating running row sum
                runningRowSum[r] += arr[r][cr];
            }
            int currMax = maxSubArraySum(runningRowSum, rows);
            if(maxArea < currMax)
            {
                maxArea = currMax;
            }
        }
    }

    cout<<maxArea;
    return 0;
}

/*
Maximum Sum Rectangle

Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29

*/
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

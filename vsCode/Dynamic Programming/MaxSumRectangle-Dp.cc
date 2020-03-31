#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size) 
{ 
   int max_so_far = 0, max_ending_here = 0;
   for (int i = 0; i < size; i++) 
   { 
       max_ending_here = max_ending_here + a[i]; 
       if (max_ending_here < 0) 
           max_ending_here = 0; 
  
       /* Do not compare for all elements. Compare only    
          when  max_ending_here > 0 */
       else if (max_so_far < max_ending_here) 
           max_so_far = max_ending_here; 
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

    for(int cl = 0; cl < cols; cl++)
    {
        //moving start point
        int runningRowSum[rows];
        memset(runningRowSum, 0 , sizeof(runningRowSum));
        for(int cr = cl; cr < cols; cr++)
        {
            //moving end point
            for(int r = 0; r < rows; r++)
            {
                runningRowSum[r] += arr[r][cr];
            }
            int currMax = maxSubArraySum(runningRowSum, rows);
            if(maxArea < currMax)
            {
                maxArea = currMax;
                // cout<<maxArea<<" @ cl : "<<cl<<" cr : "<<cr<<endl;
            }
        }
    }

    cout<<maxArea;
    return 0;
}

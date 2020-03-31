#include "bits/stdc++.h"

using namespace std;

int findMaxSquareWithAllZeros(int** arr,int rows,int cols)
{
    /*
    Find the max square with all 0's
    */
   int dp[rows][cols];
   memset(dp, 0 ,sizeof(dp));
   int max = 0;
   for(int i = 0; i < rows; i++)
   {
       dp[i][0] = (arr[i][0] == 0) ? 1 : 0;
       if(dp[i][0])
            max = 1;
   }
   for(int j = 0; j < cols; j++)
   {
       dp[0][j] = (arr[0][j] == 0) ? 1 : 0;
        if(dp[0][j])
            max = 1;
   }
   for(int i = 1; i < rows; i++)
   {
       for(int j = 1; j < cols; j++)
       {
           if(arr[i][j] == 1)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = min(min(dp[i-1][j - 1], dp[i][j - 1]), dp[i -1][j]) + 1;
                max = (max < dp[i][j]) ? dp[i][j] : max;
            }
       }
   }
   return max;
}

int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}
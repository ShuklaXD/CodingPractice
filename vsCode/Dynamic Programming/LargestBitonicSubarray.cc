/*
Largest Bitonic Subarray
Send Feedback
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 100000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*/

#include<bits/stdc++.h>

using namespace std;

void scanLeft(vector<int>& input, vector<int>& left)
{
    for(int i = 0; i < input.size(); i++)
    {
        int tmpLeft = 0;
        for(int j = i - 1; j >= 0; j--)
        {
            if(input[j] < input[i])
            {
                if(tmpLeft < left[j])
                    tmpLeft = left[j];
            }
        }
        left[i] = tmpLeft + 1;
    }
}


void scanRight(vector<int>& input, vector<int>& right)
{
    for(int i = input.size() - 1; i >= 0; i--)
    {
        int tmpRight = 0;
        for(int j = i + 1; j < input.size(); j++)
        {
            if(input[j] < input[i])
            {
                if(tmpRight < right[j])
                    tmpRight = right[j];
            }
        }
        right[i] = tmpRight + 1;
    }
}

int longestBitonicSubarray(vector<int>& input) {
    vector<int> left(input.size(), 0);
    vector<int> right(input.size(), 0);
    scanLeft(input, left);
    scanRight(input, right);
    int max = 0;
    for(int i = 0; i < input.size(); i++)
    {
        if((left[i] + right[i]) > max)
            max = (left[i] + right[i]);
    }
    // cout<<max - 1<<endl;
    return max -1;
}


int main()
{
    //Test Cases
    int cases = 0;
    cin>>cases;
    while(cases-->0)
    {
        //Array input
        int size = 0;
        cin>>size;
        vector<int> arr(size, 0);
        for(int i = 0; i < size; i++)
            cin>>arr[i];
        cout<<longestBitonicSubarray(arr);
    }
    return 0;
}
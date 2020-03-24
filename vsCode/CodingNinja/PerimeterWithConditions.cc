/*Perimeter with conditions
Send Feedback
Tanya gives an array of integers and asks Harshit to find which three elements form a triangle (non-degenerate). The task seems easy to Harshit.
So, Tanya adds some conditions to this task -
1. Find the triangle with maximum perimeter
2. If there are two or more combinations with same value of maximum perimeter, then find the one with the longest side.
3.If there are more than one combinations which satisfy all the above conditions the find with maximum longest minimum side.
Input Format
The First line contains no of elements of array: N
Each T lines contains N space-separated integers: A [i]
Output Format
The output contains three space-separated elements that denote the length of the sides of triangle. If no such triangle is possible, then print -1.
Constraints
1 =< N <= 10^5 
1 <= A[i] <= 10^9
Time Limit: 1 second
Sample Input1:
5
1 1 1 3 3
Sample Output1:
1 3 3 
Sample Input2:
3
2 2 4
Sample Output3:
-1 
Explaination
In the First Sample case, the elements that form a triangle with maximum perimeter is 1,3,3.
In the Second Sample case, the elements that can form a triangle are degenerate, so, we printed -1.
*/

#include<bits/stdc++.h>
#include "set"
using namespace std;

bool hasTriangle(int64_t& a, int64_t& b, int64_t& c)
{
    if(((a + b) > c)  && ((a + c) > b) && ((c + b) > a))
        return true;
    else
        return false;
}

int main()
{    
    //Array input
    int size = 0;
    cin>>size;
    vector<int64_t> sides(size);
    for(int i = 0; i < size; i++){
        cin>>sides[i];
    }

    sort(sides.begin(), sides.end(), greater<int64_t>());

    int fi = 0, si = 1, ti = 2;
    int64_t first = sides[fi], second = sides[si], third = sides[ti];

    while(!hasTriangle(first, second, third))
    {
        if((second + third) <= first)
        {
            first = sides[++fi];
            second = sides[++si];
            if(ti + 1 < size)
                third = sides[++ti];
            else
            {
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
    cout<<third<<" "<<second<<" "<<first<<endl;
    return 0;
}
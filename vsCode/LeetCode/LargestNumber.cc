/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    static bool compare(string& v1 , string& v2)
    {
        string res1 = v1 + v2;
        string res2 = v2 + v1;
        return (res1 > res2);
    }
    
    string largestNumber(vector<int>& nums) {
        string snum[nums.size()];
        int j = 0;
        for(auto n : nums)
            snum[j++] = to_string(n);
        
        sort(snum, snum + nums.size(), compare);
        string res="";
        if(snum[0] == "0")
            return "0";
        for(int i = 0 ; i < nums.size(); i++)
        {
            res += snum[i];
        }
        return res;
    }
};
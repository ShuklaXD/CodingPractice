/*
165. Compare Version Numbers
Medium

404

1321

Add to List

Share
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.

 

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
Example 4:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
Example 5:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"
 

Note:

Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
Version strings do not start or end with dots, and they will not be two consecutive dots.
*/
#include <bits/stdc++.h>
#include "vector"

using namespace std;
class Solution {
public:
    
    int compareVersion(string version1, string version2) {
       
        vector<int> c1,c2;
        string s = "";
        for(auto c : version1)
        {
            if(c == '.')
            {
                c1.push_back((int)stoi(s));
                s = "";
            }
            else
            {
                s += c;
            }
        }
        c1.push_back((int)stoi(s));
        s = "";
        for(auto c : version2)
        {
            if(c == '.')
            {
                c2.push_back(stoi(s));
                s = "";
            }
            else
            {
                s += c;
            }
        }
        c2.push_back((int)stoi(s));
        int v1 = c1.size();
        int v2 = c2.size();
        
        for(int i = 0, j = 0; (i < v1) && (j < v2); i++,j++)
        {
            if(c1[i] < c2[i])
                return -1;
            else if(c1[i] > c2[i])
                return 1;
            else
                continue;
        }
        if(v1 < v2)
        {
            int sum = 0;
            for(int i = v1; i < v2; i++)
                sum += c2[i];
            if(sum)
                return -1;
            else
                return 0;
        }
        else if(v2 < v1)
        {
            int sum = 0;
            for(int i = v2; i < v1; i++)
                sum += c1[i];
            if(sum)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
};
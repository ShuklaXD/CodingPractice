#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    
    int res = -1;    // 0 - tie  1 - alice   -1 - bob
        
    void winner(vector<int>& s, string player, int aS, int bS, int index, int size)
    {
        if(index >= size)
        {
            if(aS == bS)
            {
                res = 0;
                return;
            }
            if(aS > bS)
            {
                res = 1;
                return;
            }
            else
            {
                return;
            }
            
        }
        if(player == "Alice")
        {
            winner(s, "Bob", aS + s[index], bS, index + 1, size);
            winner(s, "Bob", aS + s[index] + s[index + 1], bS, index + 2, size);
            winner(s, "Bob", aS + s[index] + s[index + 1] + s[index + 2], bS, index + 3, size);
        }
        else
        {
            winner(s, "Alice", aS, bS + s[index], index + 1, size);
            winner(s, "Alice", aS, bS + s[index] + s[index + 1], index + 2, size);
            winner(s, "Alice", aS, bS + s[index] + s[index + 1] + s[index + 2], index + 3, size);
        }
    }
    
    string stoneGameIII(vector<int>& s) {
        int size = s.size();
        s.push_back(0);
        s.push_back(0);
        s.push_back(0);
        
        winner(s, "Alice", 0,0,0,size);
        
        if(res == 1)
            return "Alice";
        else if(res == 0)
            return "Tie";
        else
            return "Bob";
    }
};

int main()
{
    Solution s;
    vector<int> in = {1,2,3,7};
    string str = s.stoneGameIII(in);
    cout<<str;
}
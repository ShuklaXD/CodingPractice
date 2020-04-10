#include <bits/stdc++.h>
using namespace std;

class CombinationSum2 {
public:
    
    vector<vector<int>> sol;
    
    void bt(vector<int>& c, int target, int curr, int sum, vector<int>& tmp)
    {
        if(sum == target)
        {
            sol.push_back(tmp);
            return;
        }
        for(int i = curr; i < c.size(); i++)
        {
            if( sum + c[i] <= target)
            {
                tmp.push_back(c[i]);
                bt(c, target, i + 1, sum + c[i], tmp);
                tmp.pop_back();
                while(i+1 < c.size())
                {
                    if(c[i] == c[i+1])
                        i++;
                    else
                        break;
                }
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        vector<int> tmp;
        bt(c, target, 0, 0, tmp);
        return sol;
    }
};


int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1, 0);    // nums of ways to arrive at i :: size is target +1 as we want to get to index target
    
    dp[0] = 1;  //only way to arrive at 0 is empty set 

// Note that 1 may not be included in the given numbers so to arrive at any number less than the min in given values we would have no option but to give only empty set
    
    for(int i = 1; i <=target; i++)
    {
        //for all numbers before N calculate possible ways to arrive there
        for(int x : nums)
        {
            if(i-x >= 0)
            {
                dp[i] += dp[i-x];
                // x is single coin that can be added to all combinations req for making i - x making sum as i
            }
        }
    }
    return dp[target];
}

int main()
{
    vector<int> nums = {3,33,333};
    int target = 10000;
    // cout<<combinationSum4(nums, target)<<endl;
    vector<int> n2 = {10,1,2,7,6,1,5};
    int t = 8;
    CombinationSum2 c;
    vector<vector<int>> sol = c.combinationSum2(n2, t);
    

    return 0;
}
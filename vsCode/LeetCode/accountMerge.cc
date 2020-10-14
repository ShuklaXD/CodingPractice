#include <bits/stdc++.h>

using namespace std;

#define vsort(a) sort(a.begin(), a.end())
#define sizeOf(a) a.size()

#define For(i,a,b) for (int i = a; i < b; i++)

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, vector<set<string>>> accs;
        for(auto s : accounts)
        {
            set<string> emails;
            string name = s[0];
            vector<int> found;
            for(int i = 1; i < s.size(); i++)
            {
                emails.insert(s[i]);
                if(accs.find(name) != accs.end())
                {
                    for(int e = 0; e < accs[name].size(); e++)
                    {
                        if(accs[name][e].find(s[i]) != accs[name][e].end())
                        {
                            found.push_back(e);
                            break;
                        }
                    }
                }
            }
            if(found.size()==0)
                accs[name].push_back(emails);
            else
            {
                for(string s : emails)
                    accs[name][found].insert(s);
            }
        }
        vector<vector<string>> ans;
        int i = 0;
        for(auto x : accs)
        {
            for(auto v : x.second)
            {
                vector<string> an;
                an.push_back(x.first);
                for(string s : v)
                    an.push_back(s);
                ans.push_back(an);
            }
        }
        return ans;
    }
};


void solve()
{
    vector<vector<string>> que = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    // Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]];
    Solution s;
    auto ans = s.accountsMerge(que);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    cin>>cases;

    For(i,0,cases)
        solve();

    return 0;
}

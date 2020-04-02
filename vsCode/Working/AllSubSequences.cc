#include "bits/stdc++.h"
#define ll long long

using namespace std;

ll ans = 0;

void solve(const vector<int>& values, vector<int> taken, int curr)
{
    for(int i : taken) cout<<i<<" ";
    cout<<endl;
    if(curr == values.size())
        return;
    else
    {
        cout<<"Current : "<<values[curr]<<endl;
        // cout<<" | "<<values[curr]<<" > "<< ((taken.size() > 0) ? taken[taken.size() - 1] : -1)<<endl;
        solve(values, taken, curr + 1);
        // if(values[curr] == 1)
        //     ans++;
        if(taken.size() == 0)
        {
            
            if(values[curr] == 1)
                ans++;
            taken.push_back(values[curr]);
            solve(values, taken, curr + 1);
            taken.pop_back();
        }
        else
        {
            cout<<"check "<<values[curr]<<" > "<<taken[taken.size() - 1]<<endl;
            // for(int x = curr; x <values.size(); x++)
            // {
                int x = curr;
                if(values[x] > taken[taken.size() - 1])
                {
                    bool  skip = false;
                    for(int i : taken)
                    {
                        if(__gcd(values[x], i) != 1)
                        {
                            skip = true;
                            break;
                        }
                    }
                    if(!skip)
                    {
                        ans++;
                        taken.push_back(values[x]);
                        cout<<"------------------------"<<endl;
                        // for(int i : taken) cout<<i<<" ";
                        // cout<<endl;
                        // cout<<"------------------------"<<endl;
                        solve(values, taken, x + 1);
                        taken.pop_back();
                    }
                }
            // }
        }
    }
}
int main()
{
    int size;
    cin>>size;
    vector<int> values(size);
    for(int i = 0; i < size; i++) cin>>values[i];
    vector<int> taken;
    solve(values, taken, 0);
    cout<<ans;
    return 0;
}
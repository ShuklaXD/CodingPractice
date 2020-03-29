#include <bits/stdc++.h>
#include "map"
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s) {
    int len = 0;
    bool div = false;
    map<int, int> mods;
    for(auto value : s)
    {
        int rem = value % k;
        // cout<<value<<" "<<rem<<endl;
        if((rem == 0) && (!div))
        {
            mods[rem] = 1;
            div = false;
        }
        else
        {
            if(mods.find(rem) != mods.end())
            {
                mods[rem]++;
            }
            else
            {
                mods[rem] = 1;
            }
        }
    }

    for(map<int, int>::iterator it = mods.begin(); it != mods.end(); it++)
    {
        // cout<<"map : "<<it->first<<" : "<<it->second<<endl;
        int curr = (it->second);
        if(mods.find(k - it->first) != mods.end())
        {
            if(curr > mods[k - it->first])
            {
                len += curr;
            }
            else
            {
                len += mods[k - it->first];
            }
            mods[it->first] = 0;
            mods[k - it->first] = 0;
            // cout<<"map : "<<it->first<<" : "<<mods[it->first]<<endl;
            // cout<<"map : "<<k - it->first<<" : "<<mods[k - it->first]<<endl;
        }
        else
        {
            len += curr;
        }
    }
    return len;
}

int main()
{

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

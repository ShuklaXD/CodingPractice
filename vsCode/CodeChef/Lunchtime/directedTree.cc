#include "bits/stdc++.h"
using namespace std;

int main()
{
    int cases,n;
    cin>>cases;

    while(cases--)
    {
        cin>>n;
        vector<vector<int>> gr(n+1, vector<int>(n+1, 0));
        vector<int> in(n+1);
        int max = 0;
        for(int i = 0; i < n; i++)
        {
            int x,y;
            gr[x][y] = 1;
            in[y]++;
            if(max < in[y])
                max = in[y];
        }
        
    }

    return 0;
}
#include "bits/stdc++.h"
#include "map"
using namespace std;


int solve(int n, int k, int x, vector<int>A){

    vector<int> freq(1024 , 0);

    for(int i =0 ; i < n; i++)  
        freq[A[i]]++;

    for(int i = 0; i < k; i++)
    {
        vector<int> dpCount(1024, 0);
        int looked = 0;
        for(int i = 0; i < 1024; i++)
        {
            if(freq[i] > 0)
            {
                int tm = 0;
                if( looked % 2 )
                {
                    tm = freq[i] / 2;
                }
                else
                {
                    tm = (freq[i] + 1) / 2;
                }
                looked += freq[i];
                dpCount[i] += freq[i] - tm;
                int xo = i^x;
                dpCount[xo] += tm;
            }
        }
        freq = dpCount;
    }
    int min = 0, max = 1024;
    for(int i = 0; i < 1024; i++)
    {
        if(freq[i] != 0)
        {
            min = i;
            break;
        }
    }
    for(int i = 1023; i >=0; i--)
    {
        if(freq[i] != 0)
        {
            max = i;
            break;
        }
    }
    cout<<max<<" "<<min;
    return 0;
}

int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> arr(n, 0);

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    solve(n,k,x,arr);

    return 0;
}
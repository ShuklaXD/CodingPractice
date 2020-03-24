
#include<bits/stdc++.h>
#include "map"
using namespace std;


int balancedBTs(int h) {

    if(h == 0)
        return 0;
    else if(h ==1)
        return 1;
    else if(h == 2)
        return 3;
    else
    {
        int mod = 1000000007;
        int tmp1 = (balancedBTs( h-1)) % mod;
        int tmp2 = (balancedBTs( h-2)) % mod;
        
        long res1 = (long)tmp1 * tmp1;
        long res2 = (long)tmp1 * tmp2 * 2;
        
        int r1 = (int)(res1 % mod);
        int r2 = (int)(res2 % mod);
        
        return (r1 + r2) % mod;
    }
}

int main()
{
    int height;
    cin>>height;
    int res = balancedBTs(height);
    cout<<res<<endl;
    return 0;
}

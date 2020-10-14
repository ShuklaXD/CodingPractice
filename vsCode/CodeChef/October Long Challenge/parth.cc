#include<bits/stdc++.h>
#define ll long long int

using namespace std;


int main()
{

    ll t;
    cin>>t;

    while(t--)
    {
        unsigned ll n;
        cin>>n;
        vector<int>five={2,3,1,5,4};
        vector<int>three={1,3,2};

        if(!(n&(n-1)))
        {
            cout<<-1<<'\n';
            continue;
        }
        if(n==3)
        {
            for(auto x:three)   cout<<x<<" ";
            cout<<'\n';
            continue;
        }
        if(n==5)
        {
            for(auto x:five)    cout<<x<<" ";
            cout<<'\n';
            continue;
        }

        vector<unsigned ll>v(n+1);

        for(int i=1;i<=n;i++)
        {
            v[i]=i;
        }

        for(int i=1;i<=5;i++)
        {
            v[i]=five[i-1];
        }
        
        ll chk = 8;
        
        while(chk < n)
        {
            v[chk] = chk+1;
            v[chk+1] = chk;
            chk*=2;
        }

        for(int i=1;i<=n;i++)
            cout<<v[i]<<" ";
        
        cout<<'\n';
    }
    return 0;
}
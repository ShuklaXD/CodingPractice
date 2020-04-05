#include "bits/stdc++.h"

using namespace std;

int b, arr[100];
int samepair, diffpair;

int qry(int i)
{
    cout<<i+1<<endl;
    int ans;
    cin>>ans;
    return ans;
}

void findpair(int i)
{
    arr[i] = qry(i);
    arr[b - 1 - i] = qry(b - 1 - i);

    if(samepair == -1 && arr[i] == arr[b -1 -i])
        samepair = i;
    if(diffpair == -1 && arr[i] != arr[b -1 -i])
        diffpair = i;
}

void findchange()
{
    bool comp = false;
    if(samepair != -1 && arr[samepair] != qry(samepair))
        comp = true;
    if(samepair==-1)
        qry(0);
    bool rev = comp;
    if(diffpair != -1 && arr[diffpair] != qry(diffpair))
        rev = !comp;
    if(diffpair==-1)
        qry(0);
    if(comp)
        for(int i = 0; i < b; i++)
            arr[i] = !arr[i];
    if(rev)
        for(int i = 0; i < b/2; i++)
            swap(arr[i], arr[b - 1 - i]);
}

void solve()
{
    samepair = -1;
    diffpair = -1;

    int c = 0;
    for(; c < 5; c++)
    {
        findpair(c);
    }

    findchange();

    while(c < b/2)
    {
        int i = 0;
        for(; i < 4 && c < b/2; ++i,++c)
            findpair(c);
        if(i == 4)
            findchange();
    }
    for(int i = 0; i < b; i++)
        cout<<arr[i];
    cout<<endl;
    char ok;
    cin>>ok;
    if(ok == 'N')
        exit(0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin>>cases>>b;
    int i = 1;
    while(cases-->0)
        solve();
    return 0;
}
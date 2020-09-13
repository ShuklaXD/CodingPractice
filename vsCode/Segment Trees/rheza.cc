#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vi;

struct sol
{
    int a,b,i;
    sol()
    {
        a = b = i = 0;
    }
};

typedef vector<sol> vs;

void construct(vector<pair<int,int>>& arr, vs& tree, int start, int end, int ti)
{
    if(start == end)
    {
        tree[ti].a = arr[start].first;
        tree[ti].b = arr[start].second;
        tree[ti].i = start;
        return;
    }
    
    int mid = (start + end)/2;
    
    construct(arr, tree, start, mid, 2*ti);
    construct(arr, tree, mid + 1, end, 2*ti + 1);
    
	sol ta = tree[2*ti];
    sol tb = tree[2*ti + 1];
    
    if(ta.a == tb.b)
    {
        if(ta.b <= tb.b)
        {
            tree[ti].a = ta.a;
            tree[ti].b = ta.b;
            tree[ti].i = ta.i;
        }
        else
        {
            tree[ti].a = tb.a;
            tree[ti].b = tb.b;
            tree[ti].i = tb.i;
        }
    }
    else if(ta.a > tb.a)
    {
            tree[ti].a = ta.a;
            tree[ti].b = ta.b;
        	tree[ti].i = ta.i;
    }
    else
    {
            tree[ti].a = tb.a;
            tree[ti].b = tb.b;
        	tree[ti].i = tb.i;
    }
}

sol query(vs& tree, int start, int end, int ti, int left, int right)
{
    sol res;
    if(start >= left && right >= end)
    {
        return tree[ti];
    }
    if(end < left || start > right)
    {
        return res;
    }
    
    int mid = (start + end)/2;
    
    sol ta = query(tree, start, mid, 2*ti, left, right);
    sol tb = query(tree, mid+1, end, 2*ti+1, left, right);
    
    if(ta.a == tb.b)
    {
        if(ta.b <= tb.b)
        {
            res.a = ta.a;
            res.b = ta.b;
            res.i = ta.i;
        }
        else
        {
            res.a = tb.a;
            res.b = tb.b;
            res.i = tb.i;
        }
    }
    else if(ta.a > tb.a)
    {
            res.a = ta.a;
            res.b = ta.b;
        	res.i = ta.i;
    }
    else
    {
            res.a = tb.a;
            res.b = tb.b;
        	res.i = tb.i;
    }
    return res;
}

int main() {

    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    
    for(int i = 0; i < n; i++)
        cin>>arr[i].first;
    
    for(int i = 0; i < n; i++)
        cin>>arr[i].second;
    
    vector<sol> tree(4*n);
    
    construct(arr, tree, 0, n-1, 1);
    
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        sol ans = query(tree, 0, n-1, 1, l-1, r-1);
        cout<<ans.i + 1<<endl;
    }
}
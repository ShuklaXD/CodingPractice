#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

/*
input size required time complexity 
n≤10 		O(n!) 
n≤20 		O(2^n) 
n≤500 		O(n^3) 
n≤5000 		O(n^2) 
n≤10^6		O(nlogn) or O(n) 
n is large	O(1) or O(logn)
*/

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first 
#define S second 
#define PB push_back 
#define MP make_pair
#define li (2*treeIndex)
#define ri (2*treeIndex+1)
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define deb(x) cout<<#x<<" "<<x<<endl;

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/

int sz;
vi segTree, arr, lazy;

void printArr()
{
	for(int i = 0; i < sz; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void printTree()
{
	for(int i = 0; i < segTree.size(); i++)
	{
		cout<<segTree[i]<<" ";
	}
	cout<<endl;
}

void construct(vi& arr, int start, int end, int treeIndex)
{
	if(start == end)
	{
		segTree[treeIndex] = arr[end];
		return;
	}

	int mid = (start + end) / 2;
	construct(arr, start, mid, 2*treeIndex);
	construct(arr, mid + 1, end, 2*treeIndex + 1);

	segTree[treeIndex] = segTree[2*treeIndex] + segTree[2*treeIndex + 1];
}

int update(int lr,	
            int rr,
			int treeIndex,	//to update in segment tree
			int value,	//value to update
			int start = 0,	//start of subtree
			int end = arr.size() - 1)	//end of subtree
{
	int diff = 0;
	if(start > rr || end < lr )
	{
		return;
	}

    if(start >= lr && end <= rr)
    {
        segTree[treeIndex] += value;
        if(lr != rr)
        {
            lazy[li] += value;
            lazy[ri] += value;
        }
        return;
    }

	int mid = (start + end) / 2;
	
    update(lr, rr, 2*treeIndex, value, start, mid);
    update(lr, rr, 2*treeIndex + 1, value, mid+1, end);

	segTree[treeIndex] = segTree[2*treeIndex] + segTree[2*treeIndex+1];
}

int query(int treeIndex, int left, int right, int start = 0, int end = arr.size() - 1)
{
    if(lazy[treeIndex] != 0)
    {
        segTree[treeIndex] += lazy[treeIndex];
        if(left != right)
        {
            lazy[li] += lazy[treeIndex];
            lazy[ri] += lazy[treeIndex];
        }
        lazy[treeIndex] = 0;
    }

	if(left > end || right < start)
		return 0;
	
	if(start >= left && right >= end)
    {
        return segTree[treeIndex];
    }
	
	int mid = (start + end) / 2;

	int lt = query(2*treeIndex , left, right, start, mid);
	int rt = query(2*treeIndex + 1 , left, right, mid+1, end);

	return lt + rt;
}

void solve()
{
	segTree.clear();
	cin>>sz;
	arr.resize(sz);

	for(int i = 0; i < sz; i++)
		cin>>arr[i];
	
	segTree.resize(4*sz);
    lazy.resize(4*sz);
    
	construct(arr, 0, sz - 1, 1);

	// printTree();
	// printArr();
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cases = 1;

	// cin>>cases;

	while(cases-->0)
		solve();
	
	return 0;
}

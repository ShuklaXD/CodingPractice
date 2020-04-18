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

#define Fo(i,a,b) for (int i = a; i <= b; i++)
#define fo(i,n) for(int i = 0; i < n; i++)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;
/***************************************************/


struct info
{
    int odd, even;
    info()
    {
        odd = even = 0;
    }
};


int n,q;
vi arr;
vector<info> segTree;


void printArr()
{
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void printTree()
{
	for(int i = 0; i < segTree.size(); i++)
	{
		cout<<segTree[i].odd<<" "<<segTree[i].even<<endl;
	}
	cout<<endl;
}

void construct(vi& arr, int start, int end, int treeIndex)
{
	if(start == end)
	{
        if((arr[end]&1))
		    segTree[treeIndex].odd = 1;
        else
            segTree[treeIndex].even = 1;
      
		return;
	}

	int mid = (start + end) / 2;
	construct(arr, start, mid, 2*treeIndex);
	construct(arr, mid + 1, end, 2*treeIndex + 1);

	segTree[treeIndex].odd = segTree[2*treeIndex].odd + segTree[2*treeIndex + 1].odd;
    segTree[treeIndex].even = segTree[2*treeIndex].even + segTree[2*treeIndex + 1].even;
}

void update(int index,	//to update in the actual array
			int treeIndex,	//to update in segment tree
			int value,	//value to update
			int start = 0,	//start of subtree
			int end = arr.size() - 1)	//end of subtree
{
	int diff = 0;
	if(start == end)
	{
		arr[index] = value;
        if((arr[index]&1))
		{
            segTree[treeIndex].odd = 1;
            segTree[treeIndex].even = 0;
        }
        else
        {
            segTree[treeIndex].odd = 0;
            segTree[treeIndex].even = 1;
        }
        return;
	}

	int mid = (start + end) / 2;
	
	if(index <= mid)
	{
		update(index, 2*treeIndex, value, start, mid);
	}
	else
	{
		update(index, 2*treeIndex + 1, value, mid+1, end);
	}

	segTree[treeIndex].odd = segTree[2*treeIndex].odd + segTree[2*treeIndex+1].odd;
    segTree[treeIndex].even = segTree[2*treeIndex].even + segTree[2*treeIndex+1].even;
}

int query(int treeIndex, int op, int left, int right, int start = 0, int end = arr.size() - 1)
{
	if(left > end || right < start)
		return 0;
	
	if(start >= left && right >= end)
    {
        if(op == 1)
            return segTree[treeIndex].even;
        else
            return segTree[treeIndex].odd;
    }
	
	int mid = (start + end) / 2;

	int lt = query(2*treeIndex , op, left, right, start, mid);
	int rt = query(2*treeIndex + 1, op, left, right, mid+1, end);
	return lt + rt;
}

void solve()
{
    cin>>n;

    arr.resize(n, 0);
    segTree.resize(4*n);

    fo(i,n)
        cin>>arr[i];
    construct(arr, 0, n-1, 1);
    int q;
    cin>>q;
    // printTree();
    int op, l, r;
    while(q-->0)
    {
        cin>>op>>l>>r;
        if(op == 0)
        {
            update(l-1,1,r);
            // printTree();
        }
        else
        {
            cout<<query(1, op, l-1, r-1)<<endl;
        }
    }
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

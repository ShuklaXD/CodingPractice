#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define REP(i,a,b) for (int i = a; i <= b; i++)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/

int n,q;
vi segTree,arr;

void printArr()
{
	cout<<"Array : "<<endl;
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}

void printTree()
{
	cout<<"Segment Tree : "<<endl;
	for(int i = 0; i < segTree.size(); i++)
	{
		cout<<segTree[i]<<"\t";
	}
	cout<<endl;
}

int merge(int a, int b)
{
	return a+b;	//Operation based on queries
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

	segTree[treeIndex] = merge(segTree[2*treeIndex], segTree[2*treeIndex + 1]);	//query based operation
}

void update(int index,	//to update in the actual array
			int treeindex,	//to update in segment tree
			int value,	//value to update
			int start = 0,	//start of subtree
			int end = arr.size() - 1)	//end of subtree
{
	if(start == end)
	{
		arr[index] = value;
		segTree[treeindex] = value;		//query based operation
		return;
	}

	int mid = (start + end) / 2;
	
	if(index <= mid)
		update(index, 2*treeindex, value, start, mid);
	else
		update(index, 2*treeindex + 1, value, mid+1, end);
	
	segTree[treeindex] = merge(segTree[2*treeindex], segTree[2*treeindex + 1]);	//query based operation
}

int query(int treeIndex, int left, int right, int start = 0, int end = arr.size() - 1)
{
	if(left > end || right < start)
		return 0;
	
	if(start >= left && right >= end)
		return segTree[treeIndex];
	
	int mid = (start + end) / 2;

	int lt = query(2*treeIndex , left, right, start, mid);
	int rt = query(2*treeIndex + 1 , left, right, mid+1, end);
	return merge(lt, rt);		//query based operation
}

void solve()
{
	segTree.clear();
	n = 5;
	// cin>>n;
	arr.resize(n);

	arr = {1,2,3,4,5};

	// REP(i,0,n)	
	// 	cin>>arr[i];
	
	segTree.resize(4*n);
	construct(arr, 0, n - 1, 1);

	printArr();
	printTree();
	update(0, 1, 12);	//1 indexed query
	printArr();
	printTree();

	cout<<query(1, 1,3)<<endl;
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

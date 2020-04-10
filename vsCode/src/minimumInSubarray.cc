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

#define REP(i,a,b) for (int i = a; i <= b; i++)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/

int size, queries;
vi segTree,arr;

void printArr()
{
	for(int i = 0; i < size; i++)
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

int construct(int start, int end, int treeIndex)
{
    if(start > end)
        return;
    if(start == end)
    {
        segTree[treeIndex] = arr[start];
        return segTree[treeIndex];
    }

    int mid = (start+end)/2;

    // construct(start, mid, 2*treeIndex);
    // construct(mid + 1, end, 2*treeIndex + 1);

    segTree[treeIndex] = min(construct(start, mid, 2*treeIndex), construct(mid + 1, end, 2*treeIndex + 1));

    return segTree[treeIndex];
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
        segTree[treeindex] = value;
        return;
    }

    int mid = (start + end) / 2;
    if(index <= mid)
        update(index, 2*treeindex, value, start, mid);
    else
        update(index, 2*treeindex + 1, value, mid + 1, end);

    segTree[treeindex] = min( segTree[2*treeindex] , segTree[2*treeindex + 1]);
}

int query(int treeIndex, int left, int right, int start = 0, int end = arr.size() - 1)
{
    if(right < start || left > end)
        return INT_MAX;
    
    if(start >= left && end <= right)
        return segTree[treeIndex];

    int mid = (start + end) / 2;

    return min(query(2*treeIndex, left, right, start, mid), query(2*treeIndex + 1, left, right, mid + 1, end));
}

void solve()
{
    arr.clear();
    segTree.clear();
    cin>>size>>queries;
    arr.resize(size, 0);

    for(int i = 0; i < size; i++)
        cin>>arr[i];
    
    segTree.resize(4*size, INT_MAX);

    construct(0, size-1, 1);

    // printTree();
    // printArr();

    char c;
    int l,r;
    while(queries-->0)
    {
        cin>>c>>l>>r;
        if(c=='q')
        {
            //query
            int res = query(1, l-1, r-1);
            cout<<res<<endl;
        }
        else
        {
            //update
            update(l - 1,1,r);
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

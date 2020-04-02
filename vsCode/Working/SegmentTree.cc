#include<bits/stdc++.h>

using namespace std;

void buildSegmentTree(vector<int>& arr, int start, int end, vector<int>& segmentTree, int index)
{
    cout<<" Index : "<<index<<endl;
    if(start == end)
    {
        // cout<<" Elem : "<<elem++<<" : "<<arr[start]<<" Index : "<<index<<endl;
        segmentTree[index] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildSegmentTree(arr, start, mid, segmentTree, 2*index);
    buildSegmentTree(arr, mid + 1, end, segmentTree, ( 2*index ) + 1);
    
    segmentTree[index] = segmentTree[ 2*index ] + segmentTree[ (2*index) + 1];
}

void build(vector<int>& arr, vector<int>& tree, int n)
{  
    // insert leaf nodes in tree 
    for (int i=0; i<n; i++)
        tree[n+i] = arr[i]; 
    
    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[i<<1] + tree[i<<1 | 1];       // sum tree[ 2 * i ] + tree[ 2 * i + 1]
}

void updateTreeNode( vector<int>& arr, vector<int>& tree, int size , int index, int value )
{ 
	// set value at position p 
	tree[index + size] = value; 
	index = index + size; 
	
	// move upward and update parents 
	for (int i=index; i > 1; i >>= 1)
		tree[i>>1] = tree[i] + tree[i^1]; 
} 

// function to get sum on interval [l, r) 
int query( vector<int>& tree, int size, int l, int r)
{ 
	int res = 0; 
	// loop to find the sum in the range 
	for (l += size, r += size; l < r; l >>= 1, r >>= 1)
	{ 
		if (l&1)
			res += tree[l++]; 
	
		if (r&1)
			res += tree[--r]; 
	}
	return res; 
}

int main()
{
    //Array input
    int size = 0;
    cin>>size;
    vector<int> arr(size, 0);
    // int arr[size];
    for(int i = 0; i < size; i++)   cin>>arr[i];
    
    vector<int> segmentTree( 4*size );

    // build(arr, segmentTree, size);
    buildSegmentTree(arr, 0, size - 1, segmentTree, 1);

    for(int i = 1; i < 4 * size; i++)   cout<<segmentTree[i]<<" ";

    return 0;
}
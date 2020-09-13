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


struct elem
{
    int max;
    int smax;
};

int size;
vi arr;
vector<elem> segTree;

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
		cout<<segTree[i].max<<" , "<<segTree[i].smax<<" | ";
	}
	cout<<endl;
}

void refreshValAt(int treeIndex)
{
    if(segTree[2*treeIndex].max > segTree[2*treeIndex + 1].max)
    {
        segTree[treeIndex].max = segTree[2*treeIndex].max;
        segTree[treeIndex].smax = max( segTree[2*treeIndex].smax, segTree[2*treeIndex + 1].max);
    }
    else
    {
        segTree[treeIndex].max = segTree[2*treeIndex + 1].max;
        segTree[treeIndex].smax = max( segTree[2*treeIndex + 1].smax, segTree[2*treeIndex].max);
    }
}

void construct(int start, int end, int treeIndex)
{
	if(start == end)
	{
		segTree[treeIndex].max = arr[end];
        segTree[treeIndex].smax = INT_MIN;
		return;
	}

	int mid = (start + end) / 2;
	construct(start, mid, 2*treeIndex);
	construct(mid + 1, end, 2*treeIndex + 1);

    refreshValAt(treeIndex);
}

void update(int index,	//to update in the actual array
			int treeIndex,	//to update in segment tree
			int value,	//value to update
			int start = 0,	//start of subtree
			int end = arr.size() - 1)	//end of subtree
{
	if(start == end)
	{
		arr[index] = value;
		segTree[treeIndex].max = value;
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
	
    refreshValAt(treeIndex);
}

elem query(int treeIndex, int left, int right, int start = 0, int end = arr.size() - 1)
{
    elem res;
	if(left > end || right < start)
	{
        res.max = INT_MIN;
        res.smax = INT_MIN;
        return res;
    }
	
	if(start >= left && right >= end)
		return segTree[treeIndex];
	
	int mid = (start + end) / 2;

	elem lt = query(2*treeIndex , left, right, start, mid);
	elem rt = query(2*treeIndex + 1 , left, right, mid+1, end);
	
    if(lt.max == rt.max)
    {
        res.max = res.smax = lt.max;
    }
    else if(lt.max >= rt.max)
    {
        res.max = lt.max;
        res.smax = max( lt.smax, rt.max);
    }
    else
    {
        res.max = rt.max;
        res.smax = max( rt.smax, lt.max);
    }
    return res;
}

void solve()
{
	segTree.clear();
	// size = 5;
	cin>>size;
	arr.resize(size);

	for(int i = 0; i < size; i++)
		cin>>arr[i];
	
	segTree.resize(4*size);
	construct(0, size - 1, 1);

    printArr();
    printTree();

    int q;
    char c;
    int l,r;
    cin>>q;
    while(q-->0)
    {
        cin>>c>>l>>r;
        if(c=='Q')
        {
            //query
            elem res = query(1, l-1, r-1);
            cout<<res.max + res.smax<<endl;
        }
        else
        {
            //update
            update(l - 1,1,r);
            // printTree();
            // printArr();
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

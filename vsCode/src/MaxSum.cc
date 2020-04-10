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
    int bps,bss,sum,max;
};

int size, queries;
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
		cout<<"max "<<segTree[i].max<<" sum "<<segTree[i].sum<<
        " bps "<<segTree[i].bps<<" bss "<<segTree[i].bss<<endl;
	}
	cout<<endl;
}

elem refreshValAt(elem& lt, elem& rt)
{
    elem res;

    res.max= max({lt.max, rt.max, lt.bss + rt.bps});

    res.sum = lt.sum + rt.sum;
    
    res.bps = max(lt.bps, lt.sum + rt.bps);
    
    res.bss = max(rt.bss, lt.bss + rt.sum);

    return res;
}

void construct(int start, int end, int treeIndex)
{
    if(start > end)
        return;

    if(start == end)
    {
        segTree[treeIndex].max = arr[start];
        segTree[treeIndex].sum = arr[start];
        segTree[treeIndex].bps = arr[start];
        segTree[treeIndex].bss = arr[start];
        return;
    }

    int mid = (start+end)/2;

    construct(start, mid, 2*treeIndex);
    construct(mid + 1, end, 2*treeIndex + 1);

    segTree[treeIndex] = refreshValAt(segTree[2*treeIndex], segTree[2*treeIndex+1]);
}

elem query(int treeIndex, int left, int right, int start = 0, int end = arr.size() - 1)
{
    elem res;
    if(right < start || left > end)
    {
        res.max = -INF;
        res.sum = -INF;
        res.bps = -INF;
        res.bss = -INF;
        return res;
    }
    
    if(start >= left && end <= right)
        return segTree[treeIndex];

    int mid = (start + end) / 2;

    elem lt = query(2*treeIndex, left, right, start, mid);
    elem rt = query(2*treeIndex + 1, left, right, mid + 1, end);
    
    res = refreshValAt(lt, rt);
    return res;
}

void solve()
{
    arr.clear();
    segTree.clear();
    cin>>size;
    arr.resize(size, 0);

    for(int i = 0; i < size; i++)
        cin>>arr[i];
    
    segTree.resize(4*size);

    construct(0, size-1, 1);

    printTree();
    printArr();
    cin>>queries;
    
    int l,r;
    while(queries-->0)
    {
        cin>>l>>r;
        elem res = query(1, l-1, r-1);
        cout<<res.max<<endl;
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

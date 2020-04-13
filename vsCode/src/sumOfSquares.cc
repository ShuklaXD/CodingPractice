/*
Sum Of Squares

Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
Input
There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
Output
For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not occur with proper use of 64-bit signed integer.
Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Output:
Case 1:
30
7
13
Case 2:
1

*/
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
#define sq(a) a*a

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

/**************************************************/


struct elem
{
    int n, sum, sq, op; //op 0 set 1 inc
    elem()
    {
        n = sum = sq = op = 0;
    }
};

struct lz
{
    int val, op;
    lz()
    {
        val = op = -1;
    }
};

int sz;
vi arr;
vector<lz> lazy;
vector<elem> segTree;

void printArr()
{
    cerr<<"Arr : ";
	for(int i = 0; i < sz; i++)
		cerr<<arr[i]<<" ";
	cerr<<endl;
}

void printTree()
{
    cerr<<"Tree : ";
	for(int i = 0; i < segTree.size(); i++)
	{
		// cout<<segTree[i].n<<" "<<segTree[i].sum<<" "<<segTree[i].sq<<" ";
        cerr<<segTree[i].sq<<" ";
	}
	cerr<<endl;
}

elem setVal(elem lt, elem rt)
{
    elem t;
    t.sq = lt.sq + rt.sq;
    t.sum = lt.sum + rt.sum;
    t.n = lt.n + rt.n;
    return t;
}

void updatePending(int treeIndex, int start, int end)
{
    int mid = ( start + end )/2;
    if(lazy[treeIndex].op == 1)
    {
        int &k = lazy[treeIndex].val;
        if(start != end)
        {
            if(lazy[li].op != -1)
                updatePending(2*treeIndex, start, mid);
            if(lazy[ri].op != -1)
                updatePending(2*treeIndex + 1, mid + 1, end);

            lazy[li].val = lazy[ri].val = k;
            lazy[li].op  = lazy[ri].op = lazy[treeIndex].op;
        }

        // cerr<<"before "<<segTree[treeIndex].sq<<" "<<segTree[treeIndex].sum<<endl;
        segTree[treeIndex].sq += ( k*(segTree[treeIndex].n*k + 2*segTree[treeIndex].sum));

        segTree[treeIndex].sum += segTree[treeIndex].n*k;
        // cerr<<"after "<<segTree[treeIndex].sq<<" "<<segTree[treeIndex].sum<<endl;
        lazy[treeIndex].val = 0;
        lazy[treeIndex].op = -1;
    }

    if(lazy[treeIndex].op == 0)
    {
        int &k = lazy[treeIndex].val;
        segTree[treeIndex].sq = k*(segTree[treeIndex].n*k );
        segTree[treeIndex].sum = segTree[treeIndex].n*k;
        if(start != end)
        {
            lazy[li].val = lazy[ri].val = k;
            lazy[li].op = lazy[ri].op = lazy[treeIndex].op;
        }
        lazy[treeIndex].val = 0;
        lazy[treeIndex].op = -1;
    }
}

void construct(vi& arr, int start, int end, int treeIndex)
{
	if(start == end)
	{
		segTree[treeIndex].sq = sq(arr[end]);
        segTree[treeIndex].sum = arr[end];
        segTree[treeIndex].n = 1;
		return;
	}

	int mid = (start + end) / 2;
	construct(arr, start, mid, 2*treeIndex);
	construct(arr, mid + 1, end, 2*treeIndex + 1);

	segTree[treeIndex] = setVal(segTree[2*treeIndex], segTree[2*treeIndex + 1]);
}

void update(int lr,	
            int rr,
            int op,
			int treeIndex,	//to update in segment tree
			int k,	//value to update
			int start = 0,	//start of subtree
			int end = arr.size() - 1)	//end of subtree
{
	int diff = 0;

    updatePending(treeIndex, start, end);

	if(start > rr || end < lr )
	{
		return;
	}
	int mid = (start + end) / 2;


    if(start >= lr && end <= rr)
    {
        if(op == 1)
        {
            // cerr<<"before "<<segTree[treeIndex].sq<<" "<<segTree[treeIndex].sum<<endl;
            segTree[treeIndex].sq += ( k*(segTree[treeIndex].n*k + 2*segTree[treeIndex].sum));

            segTree[treeIndex].sum += segTree[treeIndex].n*k;
            // cerr<<"after "<<segTree[treeIndex].sq<<" "<<segTree[treeIndex].sum<<endl;
            lazy[treeIndex].val = 0;
            lazy[treeIndex].op = -1;
        }
        else
        {
            segTree[treeIndex].sq = k*(segTree[treeIndex].n*k );
            segTree[treeIndex].sum = segTree[treeIndex].n*k;
            if(start != end)
            {
                lazy[li].val = k;
                lazy[li].op = lazy[ri].op = op;
                lazy[ri].val = k;
            }
            lazy[treeIndex].val = 0;
            lazy[treeIndex].op = -1;
        }
        return;
    }
	
    update(lr, rr, op, 2*treeIndex, k, start, mid);
    update(lr, rr, op, 2*treeIndex + 1, k, mid+1, end);

	segTree[treeIndex] = setVal(segTree[2*treeIndex], segTree[2*treeIndex+1]);
}

int query(int treeIndex, int left, int right, int start = 0, int end = arr.size() - 1)
{

    if(lazy[treeIndex].op == 1)
    {
        int &k = lazy[treeIndex].val;
        segTree[treeIndex].sq += ( k*(segTree[treeIndex].n*k + 2*segTree[treeIndex].sum));
        segTree[treeIndex].sum += segTree[treeIndex].n*k;
        if(start != end)
        {
            lazy[li].val += k;
            lazy[li].op = lazy[ri].op = lazy[treeIndex].op;
            lazy[ri].val += k;
        }
        lazy[treeIndex].val = 0;
        lazy[treeIndex].op = -1;
    }
    if(lazy[treeIndex].op == 0)
    {
        int &k = lazy[treeIndex].val;
        segTree[treeIndex].sq = k*(segTree[treeIndex].n*k );
        segTree[treeIndex].sum = segTree[treeIndex].n*k;
        if(start != end)
        {
            lazy[li].val = k;
            lazy[li].op = lazy[ri].op = lazy[treeIndex].op;
            lazy[ri].val = k;
        }
        lazy[treeIndex].val = 0;
        lazy[treeIndex].op = -1;
    }

	if(left > end || right < start)
		return 0;
	
	if(start >= left && right >= end)
    {
        return segTree[treeIndex].sq;
    }
	
	int mid = (start + end) / 2;

	int lt = query(2*treeIndex , left, right, start, mid);
	int rt = query(2*treeIndex + 1 , left, right, mid+1, end);

	return lt + rt;
}

void solve(int j)
{
    int q;
	segTree.clear();
    lazy.clear();
    arr.clear();

	cin>>sz>>q;
	arr.resize(sz);

	for(int i = 0; i < sz; i++)
		cin>>arr[i];
	
	segTree.resize(4*sz);
    lazy.resize(4*sz);
    
	construct(arr, 0, sz - 1, 1);

    cout<<"Case "<<j<<":"<<endl;
    int c,l,r,x;
    while(q-->0)
    {
        // printTree();
	    // printArr();
        
        cin>>c;
        switch(c)
        {
            case 2:
            {
                cin>>l>>r;
                cout<<query(1,l-1,r-1)<<endl;
                break;
            }
            default:
                cin>>l>>r>>x;
                update(l-1,r-1,c,1,x);
                break;
        }
    }
    
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cases = 1;

	cin>>cases;

    int j = 1;
	while(cases-->0)
		solve(j++);
	
	return 0;
}

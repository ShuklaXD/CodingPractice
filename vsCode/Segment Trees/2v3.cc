/* 2 vs 3

The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N
Sample Input
5
4 3 2 1 0
1 1 0 1 0
0 1 2 3 4 
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1
 */
#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

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

void solve()
{
	
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cases = 1;

	cin>>cases;

	while(cases-->0)
		solve();
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll tree[400400];
ll lazy[400400];

ll query(ll idx,ll queryStart,ll queryEnd,ll treeStart,ll treeEnd)
{
    if(lazy[idx]!=0)
    {
        tree[idx]+=(treeEnd-treeStart+1)*lazy[idx];
        if(treeStart!=treeEnd)
        {
            lazy[2*idx]+=lazy[idx];
            lazy[2*idx+1]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(treeStart>treeEnd || treeStart>queryEnd || treeEnd<queryStart)
    {
        return 0;
    }
    if(treeStart>=queryStart && treeEnd<=queryEnd)
    {
        return tree[idx];
    }
    ll mid=treeStart+(treeEnd-treeStart)/2;
    return query(2*idx,queryStart,queryEnd,treeStart,mid)+query(2*idx+1,queryStart,queryEnd,mid+1,treeEnd);
}

void update(ll idx,ll updateStart,ll updateEnd,ll treeStart,ll treeEnd,ll val)
{
    if(lazy[idx] != 0)
    {
        tree[idx]+=(treeEnd-treeStart+1)*lazy[idx];
        if(treeStart!=treeEnd)
        {
            lazy[2*idx]+=lazy[idx];
            lazy[2*idx+1]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(treeStart>treeEnd || treeStart>updateEnd || treeEnd<updateStart)
    {
        return ;
    }
    if(treeStart>=updateStart && treeEnd<=updateEnd)
    {
        tree[idx]+=(treeEnd-treeStart+1)*val;
        if(treeStart!=treeEnd)
        {
            lazy[2*idx]+=val;
            lazy[2*idx+1]+=val;
        }
        return ;
    }
    ll mid=treeStart+(treeEnd-treeStart)/2;
    update(2*idx,updateStart,updateEnd,treeStart,mid,val);
    update(2*idx+1,updateStart,updateEnd,mid+1,treeEnd,val);
    tree[idx]=tree[2*idx]+tree[2*idx+1];
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        ll temp,a,b;
        while(c--)
        {
            cin>>temp;
            if(temp)
            {
                cin>>a>>b;
                cout<<query(1,a,b,1,n)<<"\n";
            }
            else
            {
                cin>>a>>b>>temp;
                update(1,a,b,1,n,temp);
            }
        }
    }
    return 0;
}
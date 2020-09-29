#include <bits/stdc++.h>

using namespace std;
// int 2 * 1e9
// long long 9 * 1e18

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define vsort(a) sort(a.begin(), a.end())
#define sizeOf(a) a.size()

#define For(i,a,b) for (int i = a; i < b; i++)
#define deb(x) cout << #x << " : " << x << endl;
#define isBitSet(S, i) ((S >> i) & 1)

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

struct st   //object slicing
{
    char c;
    bool a;
    int b;
};

class Entity
{
    int a;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    st s;
    cout << sizeof(s) << endl;
    cout << sizeof(s.a) << endl;
    cout << sizeof(s.b) << endl;
    cout << sizeof(s.c) << endl;

    int** arr;
    arr = new int*[5];
    for(int i = 0; i< 5; i++)
    {
        arr[i] = new int[5];
        for(int j = 0; j < 5; j++)
        {
            arr[i][j] = j;
        }
    }

    for(int i = 0; i< 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout<<" "<< arr[i][j];
        }
    }
        
    return 0;
}

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

void floodFill(int i, int j, int l, int b, int k, vector<vector<int>> &mat)
{
    if(i < l && i >=0 && j < b && j >=0)
    {
        int t = mat[i][j];
        mat[i][j] = min(mat[i][j], k);

        if(t == mat[i][j])
            return;
            
        if(i + 1 < l)
            floodFill(i+1,j,l,b,k+1, mat);
        
        if(i - 1 >= 0)
            floodFill(i-1,j,l,b,k+1, mat);
        
        if(j + 1 < b)
            floodFill(i,j+1,l,b,k+1, mat);
        
        if(j - 1 >= 0)
            floodFill(i,j-1,l,b,k+1, mat);
    }
    else
        return;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    
    int l = matrix.size(), b = matrix[0].size();
    //flood fill
    vector<vector<int>> ans(l, vector<int> (b, INT_MAX));
    
    
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < b; j++)
        {
            if(matrix[i][j] == 0)
            {
                floodFill(i,j,l,b,0,ans);
                For(p,0,l)
                    For(k,0,b)
                        cout<<ans[p][k]<<" "<<"\n"[k!=b-1];
                cout<<"------------------------------------------"<<endl;
            }
        }
    }
    return ans;
}

void solve()
{
    int l,b;
    cin>>l>>b;
    vector<vector<int>> mat(l, vector<int> (b, INT_MAX));
    For(i,0,l)
        For(j,0,b)
            cin>>mat[i][j];
    
    auto ans = updateMatrix(mat);
    For(i,0,l)
        For(j,0,b)
            cout<<ans[i][j]<<" "<<"\n"[j!=b-1];

}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

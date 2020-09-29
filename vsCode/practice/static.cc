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

int s = 10;

template<typename T>
class factory{
    T t;
    public:
        void print()
        {
            cout<<t<<endl;
        }
        T get()
        {
            return t;
        }
        void set(T t)
        {
            this->t = t;
        }
};
void func()
{
    static int s = 3;
    cout<<s<<endl;
}

int main() 
{
    int a = 5;
    // string s = "absf";
    // factory<int> fi;
    // factory<string> fs;

    // // fi.set(a);
    // // fs.set(s);
    // // fi.print();
    // // fs.print();

    // int32_t x = 128;
    // uint8_t y = x;
    // cout<<y<<endl;

    string s = "hello";
    const char *c = "hellob";

    cout<<strlen(c)<<endl;

    return 0;
}

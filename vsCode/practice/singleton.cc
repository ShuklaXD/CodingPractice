#include <bits/stdc++.h>

using namespace std;

class single
{
    static string name;

    public:
        int roll;
        static string getname()
        {
            return name;
        };
        void setname(string a, int b)
        {
            roll = b;
            name = a;
        }
        int getroll()
        {
            return roll;
        }
        single operator+ (const single &a)
        {
            this->roll += a.roll;
            return *this;
        }
        single operator++ ()
        {
            roll++;
        }
        single operator++(int)
        {
            roll++;
        }
};

struct robot
{
    int a,b;
};

string single::name = "Shubham";

single* whoami(single &a)
{
    return &a;
}

int val(single a)
{
    return a.roll;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    single p,s;
    cout<<single::getname()<<endl;
    p.setname("Shukla", 5);
    s.setname("Manish", 35);
    cout<<single::getname()<<endl;
    p = p + s;
    ++p;
    p++;
    cout<<p.getroll()<<endl;
    cout<<s.getroll()<<endl;
    auto f = whoami;
    auto func = [&](single a){ return p.roll + a.roll;};
    cout<<func(s)<<endl;

    vector<single> singles(5);
    singles[0].roll = 754;
    singles[1].roll = 945;
    singles[2].roll = 321;
    singles[3].roll = 765;
    singles[4].roll = 643;
    
    sort(singles.begin(), singles.end(), [](const single &a, const single &b){ return a.roll < b.roll;});

    for(single a : singles)
        cout<<a.roll<<" ";
    return 0;
    shared_ptr<struct robot> ss = make_shared<struct robot>();
    auto pt2 = ss;
    unique_ptr<struct robot> e2 = make_unique<struct robot>();
}

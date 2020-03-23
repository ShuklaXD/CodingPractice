#include "iostream"
#include "vector"
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases-->0)
    {    
        long size,sum;
        cin>>size>>sum;
        vector<long> vec;
        vec.resize(size);
        for(int i=0; i<size; i++)
        {
            cin>>vec[i];
        }
        int min_index,max_index;
        long long temp_sum;
        bool found = false;
        for(int i=0;i<size;i++)
        {
            temp_sum += vec[i];
            if(sum == temp_sum)
            {
                cout <<min_index<<" "<<i;
                break;
            }
            else if(sum > temp_sum)
            {
                continue;
            }
            else
            {
                temp_sum -= vec[min_index];
                min_index++;
            }
        }
    }
}
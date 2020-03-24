#include<bits/stdc++.h>
using namespace std;

void swapper(int* arr, int size)
{
    if(size == 0)
        return;
    if(arr[0] = arr[1] + 1)
    {
        int temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
    swapper(arr + 1, size - 1);
}

bool check(int* arr, int size)
{
    cout<<arr[0]<<" ";
    for(int i = 0; i < size - 1; i++)
    {
        cout<<arr[i + 1]<<" ";
        if(arr[i] > arr[i + 1])
            return false;
    }
    cout<<endl;
    return true;
}
int main()
{
    int cases;
    cin>>cases;
    while(cases-->0)
    {
        int size;
        cin>>size;
        int arr[size];
        for(int i = 0; i < size; i++)
            cin>>arr[i];
        
        swapper(arr, size);
        if(check(arr, size))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
	return 0;
}

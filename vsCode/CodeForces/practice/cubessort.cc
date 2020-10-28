#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for (int i = a; i < b; i++)

int merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    long long inv = 0; 
  
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    { 
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++]; 
        else
        { 
            temp[k++] = arr[j++]; 
            inv = inv + (mid - i); 
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++]; 
    while (j <= right)
        temp[k++] = arr[j++]; 
  
    for (i=left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv; 
} 
  

long long mergeSort(int arr[], int temp[], int left, int right) 
{ 
    long long mid, ans = 0; 
    if (right > left) 
    {
        mid = (right + left)/2; 
        ans  = mergeSort(arr, temp, left, mid); 
        ans += mergeSort(arr, temp, mid+1, right); 
        ans += merge(arr, temp, left, mid+1, right); 
    }
    return ans;
} 

void solve()
{
    int a,b,c,d,n,m,k;
    cin>>n;
    int arr[n],tmp[n];
    For(i,0,n)
        cin>>arr[i];
    
    long long cnt = mergeSort(arr,tmp,0,n-1);
    long long max = ((long long)n*(n-1)/2) - 1;

    // cout<<max<<" "<<cnt<<endl;

    if(cnt > max)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    cin>>cases;

    For(i,0,cases)
    {
        // cout << "Case #"<<i<<": ";
        solve();
        // cout <<"\n"[i==cases-1];
    }
    return 0;
}

#include "bits/stdc++.h"
#include "vector"

using namespace std;

int toInt(char c)
{
	return c - 97;
}

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	vector<string> arr(num);
	for(int i = 0; i < num; i++)	cin>>arr[i];
	
	vector<int> rank(26, -1);

	for(int i = 0; i < num - 1; i++)
	{
        // cout<<arr[i+1]<<endl;
		for(int index = 0; (index < arr[i].size()) && (index < arr[i + 1].size()); index++)
		{
			if( arr[i][index] != arr[i+1][index] )
			{
				if( rank[ toInt(arr[i + 1][index]) ] == -1)
				{
					if( rank[ toInt(arr[i][index]) ] == -1)
					{
						rank[ toInt(arr[i + 1][index]) ] = 2;
						rank[ toInt(arr[i][index]) ] = 1;
					}
					else
					{
						rank[ toInt(arr[i + 1][index]) ] = rank[ toInt(arr[i][index]) ] + 1;
					}
				}
				else
				{
					int tmp = rank[ toInt(arr[i + 1][index]) ];
					int ti = toInt(arr[i + 1][index]);
                    // cout<<"DBG :"<<toInt(arr[i + 1][index]) <<endl;
                    for(int p = 0; p < 26; p++)
					{
						if( rank[p] >= rank[ti] )
						{
							rank[p]++;
						}
					}
					rank[ toInt(arr[i][index]) ] = tmp;
				}
				break;
			}
		}
	}
    
    string res = "";
    bool cont = true;

	for(int i = 0; cont; i++)
	{
        cont = false;
		for(int j = 0; j < 26; j++)
		{
            if(rank[j] != -1)
                cont = true;
			if( rank[j] == i + 1)
			{
				char c = (char)(j + 97);
                res += c;
                rank[j] = -1;
                break;
			}
		}
        // cout<<rank[i]<<endl;
	}
    cout<<res<<endl;
}


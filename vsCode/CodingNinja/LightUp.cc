
/*A bulb can be ‘ON’ or ‘OFF’. Mr. Navdeep got ‘n’ number of bulbs and their status, whether they are ‘ON’ or ‘OFF’. Their status is 
represented in a string of size ‘n’ consisting of 0’s and 1’s, where ‘0’ represents the bulb is in ‘OFF’ condition and ‘1’ represent 
the bulb is ‘ON’. Mr. Navdeep has been given the task to light up all the bulbs.
He can perform two operations.
First, chose any segment of bulbs and reverse them means chose any substring and reverse it. E.g. “0 110 001” -> “0 011 001”. Substring (1, 3) 
is reversed here. This operation will cost him Rs. ‘X’.
Second, chose any segment of bulbs and reverse their present condition. i.e. if the bulb is ‘ON’, make it ‘OFF’ and if it is ‘OFF’, make it 
‘ON’. E.g. “0 011 001” -> “0 100 001”. Substring (1, 3) is complemented. This operation will cost him Rs. ‘Y’. You need to help Mr. Navdeep 
that how much minimum amount it will require to make all the bulbs lightened. (or make all the characters as ‘1’ in the representation string)*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int size;
	long reverse = 0, flip = 0, cost = 0;
	
	cin>>size>>reverse>>flip;
	string s(size, '.');
	cin>>s;

    if(reverse >= flip)
    {
    	int flips = 0;
    	bool prev = false;
    	for(auto c : s)
    	{
    		if(c == '0')
    		{
    			if(!prev)
    				flips++;
    			prev = true;
    		}
    		else
    			prev = false;
    	}
    	cost = flips * flip;
    }
    else
    {
    	bool reversed = false, found = false;
    	for(int i = 0; i < size; i++)
    	{
    		if(s[i] == '0')
    		{
    			found = true;
    			while((i < size - 1) && (s[i] == '0'))
    				i++;
    			while(s[i] == '1')
    			{
                    if(i < size - 1)
                    	//if reversal is found 
    				    reversed = true;
                    else
                    {
                    	//already the end of array no need to reverse just flip 11000001
                        reverse = false;
                        break;
                    }
    				i++;
    			}
    			if(reversed)
                {
                	//go back to prev element for tracking adjacent 1 again
                    i--;
                    cost += reverse;
                }
    			reversed = false;
    		}
    	}
    	if(found)
    		cost += flip;
    }
    cout<<cost;
	return 0;
}

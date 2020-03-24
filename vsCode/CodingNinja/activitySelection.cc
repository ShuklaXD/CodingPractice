#include <bits/stdc++.h>

using namespace std;

struct time
{
	long in;
	long out;
};

bool compare(struct time& t1, struct time& t2)
{
	return (t1.out > t2.out);
}
int main()
{
	int size;
	cin>>size;
	if(size == 0)
	{
		cout<<"0";
		return 0;
	}
	struct time times[size];
	for(int i = 0; i < size; i++)
		cin>>times[i].in>>times[i].out;

	sort(times, times + size, compare);

	struct time last = times[0];
	int act = 1;
	for(int i = 1; i < size; i++)
	{
		if(times[i].in >= last.out)
		{
			act++;
			last = times[i];
		}
	}
	cout<<act;

	return 0;
}
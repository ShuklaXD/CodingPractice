#include<bits/stdc++.h>
#include"map"
using namespace std;

struct painter
{
    int time;
    double cost;
    double work;
};

bool compare(painter& a, painter& b)
{
    if(a.time < b.time)
        return true;
    else if(a.time == b.time)
        return ((a.work/a.cost) > (b.work/b.cost));
    return false;
}

int main()
{
    int size;
    long area;
    cin>>size>>area;
    painter worker[size];
    
    for(int i = 0; i < size; i++)
    {
        cin>>worker[i].time>>worker[i].work>>worker[i].cost;
    }
    sort(worker, worker + size, compare);
    painter lastpainter = worker[0];
    
    int last_time = worker[0].time;
    long cost = worker[0].cost;
    for(int i = 1; i < size; i++)
    {
        cout<<" intime : "<<worker[i].time<<endl;
        long tmp = lastpainter.work * (worker[i].time - last_time);
        cout<<"on work : "<<i<<" efficiency : "<<lastpainter.work / lastpainter.cost<<" in time : "<<lastpainter.time<<" tmp : "<<tmp<<" area :"<<area<<endl;
        if(tmp > area)
        {
            // cost += lastpainter.cost;
            // cost += area * (lastpainter.cost / lastpainter.work);
            area = 0;
            break;
        }
        else
        {
            // cost += lastpainter.cost;
            // cost += (worker[i].time - last_time) * (lastpainter.cost);
            area -= tmp;
        }
        cout<<"cost : "<<cost<<" area left : "<<area<<endl;
        if((lastpainter.work / lastpainter.cost) < (worker[i].work / worker[i].cost))
        {
            lastpainter = worker[i];
            cost += worker[i].cost;
        }
        else if((lastpainter.work / lastpainter.cost) == (worker[i].work / worker[i].cost))
        {
            lastpainter = (lastpainter.work > worker[i].work)?lastpainter:worker[i];
            if(lastpainter.work < worker[i].work)
                cost += worker[i].cost;
        }
        last_time = worker[i].time;
    }
    cout<<"on work : "<<" efficiency : "<<lastpainter.work / lastpainter.cost<<endl;
    // if(area > 0)
    //     cost += lastpainter.cost * (area / lastpainter.work);
    cout<<cost;
    return 0;
}
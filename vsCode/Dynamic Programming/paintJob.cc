/*

Fractional Knapsack

You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point of time. However, no more than 1 worker can be painting the house at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
Note: You can hire a previously hired worker without paying him again.
Input
The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", described in the statement.
Output
Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.
Constraints
1 ≤ N, T, X, Y ≤ 10^5
1 ≤ D ≤ 10^11
Sample Input
3 3
1 1 1
2 2 2
3 1 5
Sample Output
3

*/
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
    if (a.time == b.time){
        return a.work > b.work;
    }
    else
        return a.time < b.time;
}

int main()
{
    int size;
    long area;
    cin>>size>>area;
    painter worker[size];
    
    for(int i = 0; i < size; i++)
    {
        cin>>worker[i].time>>worker[i].cost>>worker[i].work;
    }
    sort(worker, worker + size, compare);
    
     for(int i = 1; i < size; i++)
     {
        cout<<" Worker "<<i<<" : "<<worker[i].time<<" "<<worker[i].work<<" "<<worker[i].cost<<endl;
     }
    painter lastpainter = worker[0];
    
    int last_time = worker[0].time;
    long cost = worker[0].cost;
    cout<<"Selected Worker "<<0<<" : "<<worker[0].time<<" "<<worker[0].work<<" "<<worker[0].cost<<endl;
    for(int i = 1; i < size; i++)
    {
        if((lastpainter.work) < (worker[i].work))
        {
            long tmp = lastpainter.work * (worker[i].time - last_time);
            
            if(tmp >= area)
            {
                area = 0;
                break;
            }
            else
            {
                area -= tmp;
            }
            cout<<"Selected Worker "<<i<<" : "<<worker[i].time<<" "<<worker[i].work<<" "<<worker[i].cost<<endl;
            lastpainter = worker[i];
            cost += worker[i].cost;
            
            last_time = worker[i].time;
        }
    }
    cout<<cost;
    return 0;
}



// #include<bits/stdc++.h>
// #include"map"
// using namespace std;

// struct painter
// {
//     int time;
//     double cost;
//     double work;
// };

// bool compare(painter& a, painter& b)
// {
//     if(a.time < b.time)
//         return true;
//     else if(a.time == b.time)
//         return ((a.work/a.cost) > (b.work/b.cost));
//     return false;
// }

// int main()
// {
//     int size;
//     long area;
//     cin>>size>>area;
//     painter worker[size];
    
//     for(int i = 0; i < size; i++)
//     {
//         cin>>worker[i].time>>worker[i].work>>worker[i].cost;
//     }
//     sort(worker, worker + size, compare);
//     painter lastpainter = worker[0];
    
//     int last_time = worker[0].time;
//     long cost = worker[0].cost;
//     for(int i = 1; i < size; i++)
//     {
//         cout<<" intime : "<<worker[i].time<<endl;
//         long tmp = lastpainter.work * (worker[i].time - last_time);
//         cout<<"on work : "<<i<<" efficiency : "<<lastpainter.work / lastpainter.cost<<" in time : "<<lastpainter.time<<" tmp : "<<tmp<<" area :"<<area<<endl;
//         if(tmp > area)
//         {
//             // cost += lastpainter.cost;
//             // cost += area * (lastpainter.cost / lastpainter.work);
//             area = 0;
//             break;
//         }
//         else
//         {
//             // cost += lastpainter.cost;
//             // cost += (worker[i].time - last_time) * (lastpainter.cost);
//             area -= tmp;
//         }
//         cout<<"cost : "<<cost<<" area left : "<<area<<endl;
//         if((lastpainter.work / lastpainter.cost) < (worker[i].work / worker[i].cost))
//         {
//             lastpainter = worker[i];
//             cost += worker[i].cost;
//         }
//         else if((lastpainter.work / lastpainter.cost) == (worker[i].work / worker[i].cost))
//         {
//             lastpainter = (lastpainter.work > worker[i].work)?lastpainter:worker[i];
//             if(lastpainter.work < worker[i].work)
//                 cost += worker[i].cost;
//         }
//         last_time = worker[i].time;
//     }
//     cout<<"on work : "<<" efficiency : "<<lastpainter.work / lastpainter.cost<<endl;
//     // if(area > 0)
//     //     cost += lastpainter.cost * (area / lastpainter.work);
//     cout<<cost;
//     return 0;
// }
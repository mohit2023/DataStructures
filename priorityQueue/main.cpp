#include <iostream>
#include "priority.cpp"
using namespace std;

int main()
{
    MINPQ pq;
    pq.insert(1);
    pq.insert(17);
    pq.insert(56);
    pq.insert(10);
    pq.insert(3);
    pq.insert(6);
    cout<<pq.top()<<" ";
    pq.pop();
    cout<<pq.top()<<" ";
    pq.pop();
    cout<<pq.top()<<" ";
    pq.pop();
    cout<<pq.top()<<" ";
    pq.pop();
    return 0;
}

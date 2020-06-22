#include <iostream>
#include "queue.cpp"
using namespace std;

int main()
{
    queue<int> q;
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(4);
    q.insert(5);
    q.insert(6);
    q.insert(7);

    while(q.size()>2){
        cout<<q.size()<<" "<<q.front()<<'\n';
        q.pop();
    }
    q.insert(8);
    q.insert(9);
    q.insert(10);
    q.insert(11);
    q.insert(12);
    q.insert(13);

    while(!q.empty()){
        cout<<q.size()<<" "<<q.front()<<'\n';
        q.pop();
    }

    return 0;
}

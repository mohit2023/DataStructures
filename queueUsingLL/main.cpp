#include <iostream>
#include "queue.cpp"

using namespace std;

int main()
{
    queue<int> q;

    for(int i=0;i<10;i++){
        q.insert(i);
    }
    while(!q.empty()){
        cout<<q.size()<<" "<<q.front()<<'\n';
        q.pop();
    }
    return 0;
}

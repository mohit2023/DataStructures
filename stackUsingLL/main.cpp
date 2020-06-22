#include <iostream>
#include "stack.cpp"
using namespace std;

int main()
{
    stack<int> s;
    s.push(7);
    s.push(3);
    s.push(8);
    s.push(2);
    s.push(9);
    s.push(4);
    s.push(7);
    while(!s.empty()){
        cout<<s.size()<<" "<<s.top()<<'\n';
        s.pop();
    }

    return 0;
}

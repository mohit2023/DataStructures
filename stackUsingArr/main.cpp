#include <iostream>
#include "stack.cpp"
using namespace std;

int main()
{
    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(6);
    for(int i=0;i<5;i++){
        cout<<s.top();
        s.pop();
        cout<<'\n';
    }
    return 0;
}

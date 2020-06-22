#include <iostream>
#include "bst.cpp"

using namespace std;

int main()
{
    bst tree;
    tree.insert(5);
    tree.insert(8);
    tree.insert(17);
    tree.insert(5);
    tree.insert(10);
    tree.insert(1);
    tree.insert(123);
    tree.insert(6);
    tree.insert(9);
    tree.print();
    tree.remove(8);
    tree.remove(123);
    tree.print();
    cout<<tree.search(123)<<" "<<tree.search(8)<<" "<<tree.search(9);
    return 0;
}

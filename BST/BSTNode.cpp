#include <iostream>
template <typename T>
class BTNode{

public:

    T data;
    BTNode<T>* left;
    BTNode<T>* right;

    BTNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BTNode(){
        delete left;
        delete right;
    }
};

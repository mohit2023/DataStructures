#include "node.cpp"

template <typename T>

class queue{
    Node<T>* head;
    Node<T>* tail;
    int num;

public:
    queue(){
        head=NULL;
        tail=NULL;
        num=0;
    }

    int size(){
        return num;
    }
    bool empty(){
        return num==0;
    }

    void insert(T data){
        Node<T> *temp=new Node<T>(data);
        if(empty()){
            head=temp;
            tail=temp;
            num++;
            return;
        }
        tail->next=temp;
        tail=temp;
        num++;
    }

    T front(){
        if(empty()){
            return 0;
        }
        return head->data;
    }

    void pop(){
        if(empty()){
            return;
        }
        Node<T>* temp=head->next;
        head->next=NULL;
        delete head;
        head=temp;
        num--;
    }
};

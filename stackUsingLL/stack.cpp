#include "node.cpp"
template <typename T>
class stack{
    Node<T>* head;
    int num;

public:
    stack(){
        head=NULL;
        num=0;
    }
    ~stack(){
        delete head;
    }
    bool empty(){
        return num==0;
    }
    int size(){
        return num;
    }
    void push(T data){
        Node<T>* temp=new Node<T>(data);
        temp->next=head;
        head=temp;
        num++;
    }
    T top(){
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

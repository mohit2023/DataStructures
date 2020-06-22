#include<string>

using namespace std;

template <typename T>
class mapNode{
public:
    string key;
    T value;
    mapNode *next;

    mapNode(string key,T value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~mapNode(){
        delete next;
    }
};

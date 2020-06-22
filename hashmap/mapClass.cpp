#include "node.cpp"


template <typename T>

class hashmap{
    mapNode<T> **bucket;
    int count=0;
    int cap;

    int hashcode(string key){
        int code=0;
        int mult=1;
        int n=key.size();
        for(int i=0;i<n;i++){
            code+= key[i]*mult;
            code=code%cap;
            mult*=37;
            mult=mult%cap;
        }
        return code;
    }

    void rehash(){
        mapNode<T>** ob=bucket;
        int obs=cap;
        cap*=2;
        count=0;
        bucket=new mapNode<T>*[cap];
        for(int i=0;i<cap;i++){
            bucket[i]=NULL;
        }

        for(int i=0;i<obs;i++){
            mapNode<T>* temp=ob[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            delete ob[i];
        }
        delete []ob;
    }

public:
    hashmap(){
        count=0;
        cap=5;
        bucket=new mapNode<T>*[cap];
        for(int i=0;i<cap;i++){
            bucket[i]=NULL;
        }
    }
    ~hashmap(){
        for(int i=0;i<cap;i++){
            delete bucket[i];
        }
        delete[] bucket;
    }

    int size(){
        return count;
    }

    void insert(string key,T value){
        int code=hashcode(key);
        mapNode<T>* temp=bucket[code];
        while(temp!=NULL){
            if(temp->key==key){
                temp->value=value;
                return;
            }
            temp=temp->next;
        }
        mapNode<T>* node=new mapNode<T>(key,value);
        node->next=bucket[code];
        bucket[code]=node;
        count++;
        double lf=(1.0*count)/cap;
        if(lf>0.7){
            rehash();
        }
    }

    T getValue(string key){
        int code=hashcode(key);
        mapNode<T>* temp=bucket[code];
        while(temp!=NULL){
            if(temp->key==key){
                return temp->value;
            }
            temp=temp->next;
        }
        return 0;
    }

    bool find(string key){
        int code=hashcode(key);
        mapNode<T>* temp=bucket[code];
        while(temp!=NULL){
            if(temp->key==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    void remove(string key){
        int code=hashcode(key);
        mapNode<T>* temp=bucket[code];
        mapNode<T>* prev=NULL;

        while(temp!=NULL){
            if(temp->key==key){
                if(prev==NULL){
                    bucket[code]=temp->next;
                }
                else{
                    prev->next=temp->next;
                }
                temp->next=NULL;
                delete temp;
                count--;
                return;
            }
            prev=temp;
            temp=temp->next;
        }
    }

};

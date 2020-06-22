template <typename T>
class stack{
    T *arr;
    int num;
    int cap;

public:
    stack(){
        num=0;
        cap=4;
        arr=new T[cap];
    }
    ~stack(){
        delete [] arr;
    }

    int size(){
        return num;
    }
    bool empty(){
        return num==0;
    }
    void push(T data){
        if(num==cap){
            T *temp=new T[2*cap];
            for(int i=0;i<cap;i++){
                temp[i]=arr[i];
            }
            cap*=2;
            delete[] arr;
            arr=temp;
        }
        arr[num]=data;
        num++;
    }
    T top(){
        if(empty()){
            return 0;
        }
        return arr[num-1];
    }
    void pop(){
        if(empty()){
            return;
        }
        num--;
    }
};

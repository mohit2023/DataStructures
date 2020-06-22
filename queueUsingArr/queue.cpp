template <typename T>

class queue{
    T *arr;
    int ni;
    int fi;
    int num;
    int cap;

public:
    queue(){
        ni=0;
        fi=-1;
        num=0;
        cap=4;
        arr=new T[cap];
    }
    ~queue(){
        delete [] arr;
    }

    int size(){
        return num;
    }
    bool empty(){
        return num==0;
    }
    void insert(T data){
        if(num==cap){
            T *temp=new T[2*cap];
            int j=0;
            for(int i=fi;i<cap;i++){
                temp[j]=arr[i];
                j++;
            }
            for(int i=0;i<fi;i++){
                temp[j]=arr[i];
                j++;
            }
            fi=0;
            ni=cap;
            cap*=2;
            delete [] arr;
            arr=temp;
        }
        arr[ni]=data;
        num++;
        ni = (ni+1)%cap;
        if(fi==-1){
            fi=0;
        }
    }

    T front(){
        if(empty()){
            return 0;
        }
        return arr[fi];
    }

    void pop(){
        if(empty()){
            return;
        }
        fi=(fi+1)%cap;
        num--;
        if(num==0){
            fi=-1;
            ni=0;
        }
    }
};

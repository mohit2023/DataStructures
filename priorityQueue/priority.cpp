#include<vector>
using namespace std;

class MINPQ{

    vector<int> pq;
public:

    MINPQ(){

    }
    ~MINPQ(){

    }

    int size(){
        return pq.size();
    }
    bool empty(){
        return (pq.size()==0);
    }
    int top(){
        if(empty()){
            return 0;
        }
        else{
            return pq[0];
        }
    }
    void insert(int val){
        pq.push_back(val);
        int ci=pq.size()-1;
        int pi=(ci-1)/2;
        while(ci>0){
            if(pq[pi]<=pq[ci]){
                break;
            }
            else{
                int temp=pq[ci];
                pq[ci]=pq[pi];
                pq[pi]=temp;
                ci=pi;
                pi=(ci-1)/2;
            }
        }
    }

    void pop(){
        if(empty()){
            return;
        }
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        if(empty()){
            return;
        }

        int pi=0;
        int lci=2*pi+1;
        int rci=lci+1;
        int mi=pi;
        int n=pq.size();
        while(lci<n){
            if(pq[lci]<pq[mi]){
                mi=lci;
            }

            if(rci<n && pq[rci]<pq[mi]){
                mi=rci;
            }
            if(mi==pi){
                break;
            }
            int temp=pq[pi];
            pq[pi]=pq[mi];
            pq[mi]=temp;

            pi=mi;
            lci=2*pi+1;
            rci=lci+1;
        }
    }
};

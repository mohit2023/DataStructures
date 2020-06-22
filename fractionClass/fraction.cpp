#include <iostream>
using namespace std;

class fraction{
    int num;
    int denum;

    int GCD(int a,int b){
        if(a==0){
            return b;
        }
        return GCD(b%a,a);
    }

public:
    fraction(int num,int denum){
        this->num=num;
        this->denum=denum;
    }
    ~fraction(){

    }

    void print(){
        cout<<num<<"/"<<denum<<'\n';
    }

    void simplify(){
        int gcd=GCD(num,denum);
        num=num/gcd;
        denum=denum/gcd;
    }

    /*fraction add(fraction const* f){
        int num= this->num*f.denum + f.num*this->denum;
        int denum= this->denum * f.denum;
        fraction temp(num,denum);
        temp.simplify();
        return temp;
    }*/

    fraction operator+(fraction const& f) const{
        int num= this->num*f.denum + f.num*this->denum;
        int denum= this->denum * f.denum;
        fraction temp(num,denum);
        temp.simplify();
        return temp;
    }

    /*fraction mult(fraction const& f){
        int num=this->num*f.num;
        int denum=this->denum*f.denum;
        fraction temp(num,denum);
        temp.simplify();
        return temp;
    }*/

    fraction operator*(fraction const& f) const{
        int num=this->num*f.num;
        int denum=this->denum*f.denum;
        fraction temp(num,denum);
        temp.simplify();
        return temp;
    }

    bool operator==(fraction const& f) const{
        return (f.num==num && f.denum==denum);
    }

    //pre
    fraction& operator++(){
        num=num+denum;
        return *this;
    }
    //post
    fraction operator++(int){
        fraction temp(num,denum);
        num=num+denum;
        return temp;
    }

    fraction& operator+=(fraction const& f){
        int num= this->num*f.denum + f.num*this->denum;
        int denum= this->denum * f.denum;
        this->num=num;
        this->denum=denum;
        simplify();
        return *this;
    }

};

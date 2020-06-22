#include <iostream>
#include "fraction.cpp"
using namespace std;

int main()
{
    fraction f1(4,13);
    fraction f2(7,15);

    fraction f3=f1+f2;

    f1.print();
    f2.print();
    f3.print();

    f2=f1*f3;

    f1.print();
    f2.print();
    f3.print();

    f3= f1++;
    f2= ++(++f1);

    f1.print();
    f2.print();
    f3.print();

    f1+= f2+= f3;

    f1.print();
    f2.print();
    f3.print();


    return 0;
}

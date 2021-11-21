#include <iostream>
#include <iomanip>
using namespace std;
#include "Fraction.cpp"

int main() {

 Fraction f1(2,3);
 Fraction f2(5,9);

 Fraction f3 = f1.add(f2) ;
 Fraction f4 = f1 * f2 ;

 cout << boolalpha ;

 if(f1 == f2){
    cout << true <<endl;
 }else{
    cout << false << endl;
 }
 f3.print() ;
 f4.print() ;

}


#include <iostream>
using namespace std ;
#include "stacksUsingArray.cpp"

int main(){
    stackUsingArray<char> s;
    s.push(100) ;
    s.push(101) ;
    s.push(103) ;
    s.push(104) ;
    s.push(105) ;

    cout << s.top() << endl ;
    cout << s.pop() << endl ;
    cout << s.pop() << endl ;
    cout << s.pop() << endl ;

    cout << s.size() << endl ;

    cout << s.isEmpty() << endl ;

}

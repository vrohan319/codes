#include <iostream>
using namespace std ;

#include "queueUsingArray.cpp"

int main(){

    queueUsingArray<int> q(5) ;
    q.enqueue(10) ;
    q.enqueue(20) ;
    q.enqueue(30) ;
    q.enqueue(40) ;
    q.enqueue(50) ;
    q.enqueue(50) ;

    cout << q.Front() << endl ;
    cout << q.dequeue() << endl ;
    cout << q.dequeue() << endl ;
    cout << q.dequeue() << endl ;

    cout << q.isEmpty() << endl ;
    cout << q.getSize() << endl ;

    return 0 ;
}

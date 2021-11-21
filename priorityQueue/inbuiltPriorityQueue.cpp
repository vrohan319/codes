#include <iostream>
using namespace std ;
#include <queue>



int main(){

    priority_queue<int> pq ;

    pq.push(16) ;
    pq.push(1);
    pq.push(45);
    pq.push(23);
    pq.push(6);
    pq.push(88);
    pq.push(3);

    cout << "size" << pq.size() << endl ;
    cout << "top : " << pq.top() << endl ;

    while(!pq.empty()){
        cout << pq.top() << endl ;
        pq.pop() ;
    }

}

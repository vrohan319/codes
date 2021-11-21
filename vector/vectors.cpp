#include <iostream>
#include <vector>
using namespace std ;

int main(){

    vector<int> v ;
    //vector<int> *vp = new vector<int>();

    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.pop_back() ;
    v.capacity() ;
    v.size() ;
    v.at(2) ;

    v[1] = 100 ;
    cout << v[0] << endl ;
    cout << v[1] << endl ;
    cout << v[2] << endl ;



}

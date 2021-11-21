#include <iostream>
#include <algorithm>
using namespace std ;

int main(){

    int a[10] = {1,3,5,2,4} ;

    for(int i = 0 ; i < 10 ; i++){
        cout << a[i] << " " ;
    }
    cout << endl ;
    sort(a,a+10) ;

    for(int i = 0 ; i < 10 ; i++){
        cout << a[i] << " " ;
    }

    return  0 ;
}

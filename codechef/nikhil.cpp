#include <iostream>
using namespace std ;

int main(){

    int h1 , m1 , h2 , m2 ;

    cin >> h1 >> m1 ;
    cin >> h2 >> m2 ;

    int a = (h1 > h2)? (h1 - h2) : (h2 - h1) ;
    int b = (24 - h1 + h2) ;

    int shift_for_hour = min(a,b) ;

    a = (m1 > m2)? (m1 - m2) : (m2 - m1) ;
    b = (60 - m1 + m2) ;

    int shift_for_min = min(a ,b) ;

    int ans = shift_for_hour + shift_for_min ;

    cout << ans ;

    return 0 ;
}

#include <iostream>
using namespace std ;

int main(){

bool** ans = new bool*[10];
    cout << boolalpha ;

    for(int i = 0 ; i < 10 ; i++){
        ans[i] = new bool[10]() ;
        for(int j = 0 ; j < 10 ; j++)
            cout << ans[i][j] << endl ;
    }

}

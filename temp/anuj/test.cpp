#include <iostream>
using namespace std ;

int numOfjumps(int a[],int n){

    int i = 0 ;
    int Count = 0 ;

    while(i < n){
            Count++ ;
            i = i + a[i] ;

    }
    return Count ;
}

int main(){

    /*************** TAKING NUMBER OF SAMPLE CASES */
    int q ;
    cin >> q ;

    while(q-- > 0){
        int n = 11;
        //cin >> n ; /********SIZE OF ARRAY */
        int a[n];
        for(int i = 0 ; i < n ;i++){
            cin >> a[i] ;
        }

        int ans = numOfjumps(a,n) ;
        cout << ans ;
    }
}


#include <iostream>
#include <string>
using namespace std ;

int LCS(string s , string t){

    if(s.length() == 0 || t.length() == 0){
        return 0 ;
    }

    if(s[0] == t[0]){
        return 1 + LCS(s.substr(1) ,t.substr(1)) ;
    }

    int x = LCS(s.substr(1) ,t) ;
    int y = LCS(s,t.substr(1)) ;

    int ans = max(x,y) ;

    return ans ;
}

int LCS_mem(string s , string t,int** output){
    int m = s.length() ;
    int n = t.length() ;

    ///base case
    if(m == 0 || n == 0){
        return 0 ;
    }

    ///checking if answer already exists
    if(output[m][n] != -1){
        return output[m][n] ;
    }

    int ans ;
    ///recursive calls
    if(s[0] == t[0]){
        ans = 1 + LCS_mem(s.substr(1) ,t.substr(1),output) ;
    }else{
        int x = LCS_mem(s.substr(1) ,t,output) ;
        int y = LCS_mem(s,t.substr(1),output) ;
        ans = max(x,y) ;
    }

    ///saving answer
    output[m][n] = ans ;

    return ans ;
}

int LCS_dp(string s,string t){

    int m = s.length() ;
    int n = s.length() ;

    int **output = new int*[m + 1] ;
    for(int i = 0 ; i <= m ;i++){
        output[i] = new int[n + 1] ;
    }

    if(m == 0 || n == 0){
        return 0 ;
    }

    output[0][0] = 0 ;

    int i = 1 ;
    int j = 1 ;
    while(i <= m){  ///row
        output[i][0] = 0 ;
        i++ ;
    }

    while(j <= n){  ///column
        output[0][j] = 0 ;
        j++ ;
    }

    i = 1 ;

    while(i <= m){
        j = 1 ;
        while(j <= n){
            if(s[m-i] == t[n-j]){
                output[i][j] = 1 + output[i - 1][j - 1] ;
            }else{

                int x = output[i - 1][j] ;
                int y = output[i][j - 1] ;
                int z = output[i - 1][j - 1] ;

                output[i][j] = max(x ,max(y,z)) ;
            }
            j++ ;
        }
        i++ ;
    }

    return output[m][n] ;
}


int main(){

    string s = "bcd" ;
    string t = "cd" ;

    int m = s.length() ;
    int n = t.length() ;
    int **output = new int*[m + 1] ;
    for(int i = 0 ; i <= m ;i++){

        output[i] = new int[n + 1] ;
        for(int j = 0 ; j <= n ; j++){
            output[i][j] = -1 ;
        }
    }

    cout << LCS(s , t ) << endl ;
    cout << LCS_mem(s ,t ,output ) << endl ;
    cout << LCS_dp(s,t) << endl;

    return 0 ;
}
























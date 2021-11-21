#include <iostream>
#include <unordered_map>
#include <string>
using namespace std ;
int main(){

    unordered_map<string,int> ourmap ;

    ourmap["abc"] = 1 ;
    ourmap["abc1"] = 2 ;
    ourmap["abc2"] = 3 ;
    ourmap["abc3"] = 4 ;
    ourmap["abc4"] = 5 ;
    ourmap["abc5"] = 6 ;

    unordered_map<string,int>::iterator it = ourmap.begin() ;
    while(it != ourmap.end()){
        cout << "key : " << it->first << "  value :" << it ->second << endl ;
        it++ ;
    }

    ///find
    unordered_map<string,int>::iterator it1 = ourmap.find("abc") ;
    ///erase
    ourmap.erase(it1) ;
    ourmap.erase(it1 , it + 3) ; /// less than 3
}

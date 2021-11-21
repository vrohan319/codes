#include <bits/stdc++.h>
using namespace std ;

int main(){
    unordered_map<string ,int> ourmap ;
    /** insert **/
    pair<string ,int > p("abc" , 1) ;
    ourmap.insert(p) ;
    ourmap["def"] = 2 ;

    /** find **/
    cout << ourmap["abc"] << endl ;
    cout << ourmap.at("abc") << endl ;

    /// cout << ourmap.at("ghi") << endl ;  //error key not found
    cout << "size : " << ourmap.size() << endl ;
    cout << ourmap["ghi"] << endl ; /// if the key doesn't exist in the map it will insert 0 corresponding to the key return 0
    cout << "size : " << ourmap.size() << endl ;

    ///check presence
    if(ourmap.count("ghi") > 0){
        cout << "ghi is present" << endl ;
    }

    /// erase
    ourmap.erase("ghi") ;
    if(ourmap.count("ghi") > 0){
        cout << "ghi is present" << endl ;
    }

    cout << "size : " << ourmap.size() << endl ;

    return 0 ;
}

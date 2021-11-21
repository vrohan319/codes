#include <bits/stdc++.h>
using namespace std ;

vector<int> arr[10001] ;
int visited[10001] ;

bool check_cycle_using_dfs(int sv , int parent){

    visited[sv] = 1 ;
    for(int child: arr[sv]){
        if(visited[child] == 0){
            if(check_cycle_using_dfs(child ,sv)){
                return true ;
            }
        }else if(child != parent){
            return true ;
        }
    }

    return false ;
}

int main(){

    int n , e ;
    cin >> n >> e ;

    for(int i = 0 ; i < e ; i++){
        int a , b ;
        cin >> a >> b , arr[a].push_back(b) , arr[b].push_back(a) ;
    }

    bool ans = check_cycle_using_dfs(1 , -1);

    if(ans){
        cout << "cycle is present" << endl ;
    }else{
        cout << "no cycle found" << endl ;
    }

}

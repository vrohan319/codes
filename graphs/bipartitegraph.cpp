#include <bits/stdc++.h>
using namespace std ;

vector<int> arr[10001] ;
int visited[10001] ;
int col[10001] ;

bool dfs_bipartite_test(int sv , int color){

    visited[sv] = 1 ;
    col[sv] = color ;

    for(int child : arr[sv]){
        if(visited[child] == 0){
            if(dfs_bipartite_test(child , color^1) == false ){
                return false ;
            }
        }else if(col[sv] == col[child]){
            return false ;
        }
    }

    return true ;
}

int main(){

    int n, e ;
    cin >> n >> e ;

    for(int i = 0 ; i < e ; i++){
        int a , b ;
        cin >> a >> b , arr[a].push_back(b) , arr[b].push_back(a) ;
    }

    bool ans = true ;
    for(int i = 1 ; i <= n ; i++){
        if(visited[i] == 0){
            ans = dfs_bipartite_test(i ,0) ;
            if(!ans){
                break ;
            }
        }
    }
    cout << boolalpha ;

    cout << ans << endl ;
}

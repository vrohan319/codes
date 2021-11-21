#include <bits/stdc++.h>
using namespace std ;

void dfs(vector<int> edges[] , bool* visited , int sv){

    cout << sv << endl ;
    visited[sv] = true ;

    for(int i = 0 ; i < edges[sv].size() ; i++){
        int temp = edges[sv].at(i) ;
        if(!visited[temp]){
            dfs(edges , visited , temp) ;
        }
    }
}

int main(){

    int n , e ;
    cin >> n >> e ;

    vector<int> edges[n+1] ;

    for(int i = 0 ; i < e; i++){
        int f , s ;
        cin >> f >> s ;
        edges[f].push_back(s) ;
        edges[s].push_back(f) ;
    }

    bool* visited = new bool[n] ;
    for(int i = 0 ; i < n ; i++){
        visited[i] = false ;
    }
    dfs(edges , visited , 0) ;

    delete [] visited ;
}















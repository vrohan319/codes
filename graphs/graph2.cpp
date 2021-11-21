#include <iostream>
#include <queue>
using namespace std ;


void print_BFS(bool** edges,int v,int sv ,bool* visited){

    if(v == 0){
        return ;
    }

    queue<int> pendingNodes ;
    pendingNodes.push(sv) ;

    while(!pendingNodes.empty()){
        int currentVertex = pendingNodes.front() ;
        pendingNodes.pop() ;

        cout << currentVertex << " " ;
        visited[currentVertex] = true ;

        for(int i = 0 ; i < v ; i++){
            if(edges[currentVertex][i] && !visited[i] ){
                pendingNodes.push(i) ;
            }
        }
    }
}


void print_DFS(bool** edges , int v,int sv ,bool* visited){

    if(v == 0){
        return ;
    }

    cout << sv << " " ;
    visited[sv] = true ;

    for(int i = 0 ; i < v ; i++){
        if(edges[sv][i] && !visited[i] ){
            print_DFS(edges , v, i , visited) ;
        }
    }
}

int main(){

    int v ;
    int e ;

    cin >> v >> e ;

    bool** edges = new bool*[v] ;
    for(int i = 0 ; i < v ; i++){
        edges[i] = new bool[v] ;
        for(int j = 0 ; j < v ; j++){
            edges[i][j] = false ;
        }
    }

    for(int i = 0 ; i < e ; i++){
        int a , b ;
        cin >> a >> b ;
        edges[a][b] = true ;
        edges[b][a] = true ;
    }

    bool *visited = new bool[v] ;

    for(int i = 0 ; i < v ; i++){
        visited[i] = false;
    }

    print_BFS(edges ,v ,0 ,visited ) ;

    delete [] visited ;
    for(int i = 0 ; i < v ; i++){
        delete [] edges[i] ;
    }

    delete [] edges ;


    return 0 ;
}

#include <bits/stdc++.h>
using namespace std ;

vector<int> arr[100001] ;
int visited[100001] ;

void dfs(int sv){

    visited[sv] = 1 ;

    for(int i = 0 ; i < arr[sv].size() ; i++){
        int temp = arr[sv].at(i) ;
        if(!visited[temp]){
            dfs(temp) ;
        }
    }
}

int main(){

	int n , e ;
	cin >> n >> e ;

	for(int i = 0 ; i < e ; i++){
		int a , b ;
		cin >> a >> b , arr[a].push_back(b) , arr[b].push_back(a) ;
	}

	int count = 0 ;

	for(int i = 1 ; i <= n ; i++){
		if(visited[i] == 0){
			count++ ;
			dfs(i) ;
		}
	}

	cout << count << endl ;
}
/*

6
4
1 2
1 3
3 4
4 5




8
4
1 2
1 4
4 5
4 6
*/

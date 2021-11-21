#include <bits/stdc++.h>
using namespace std;

int main() {

    int T ;
    cin >> T ;

    while(T-- > 0){
        /***************************************************************/
        int N , A ,B ;
        cin >> N >> A >> B ;

        string S ;
        cin >> S ;

        int ans = 0 ;
        for(int i = 0 ; i < N ; i++){
            if(S[i] == '0'){
                ans += A ;
            }else{
                ans += B ;
            }
        }

        cout << ans << endl ;

        /***************************************************************/
    }

	return 0;
}

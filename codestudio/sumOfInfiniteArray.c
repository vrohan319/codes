#include <iostream>
#include <vector>
using namespace std ;

int main



vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // Write your code here

    int prefix[n] ;
    int suffix[n] ;

    vector<int> ans ;

    int sum = 0 ;
    for(int i = 0 ;i < n ;i++){
        sum = sum + arr[i] ;
        prefix[i] =  sum ;
    }

    for(int i = n - 1 ;i >= 0 ; i--){
        suffix[i] = sum ;
        sum = sum - arr[i] ;
    }

    for(int i = 0 ; i < q ; i++){

        long long s = queries[i][0] ;
        long long e = queries[i][1] ;

        long long si = (s - 1) % n ;
        long long ei = (e - 1) % n ;

        long long totalElements = s - e + 1 ;

        int eleFromStart = (n - si) ;
        int eleFromEnd = (ei + 1) ;

        long long remElements = totalElements - (eleFromStart + eleFromEnd) ;
        long long numOfCompleteArray = remElements / n ;

        long long temp = suffix[si] + prefix[ei] + numOfCompleteArray * suffix[0] ;

        int tempAns = temp % 10^9+7 ;

        ans.push_back(tempAns) ;
    }
    return ans ;
}



















































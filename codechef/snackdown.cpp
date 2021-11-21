#include <bits/stdc++.h>
#include <vector>

using namespace std ;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr ;

        int i = 0 , j = 0 ;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <=  nums2[j]){
                arr.push_back(nums1[i]) ;
                i++ ;
            }else{
                arr.push_back(nums2[j]) ;
                j++ ;
            }
        }

        while(i < nums1.size()){
            arr.push_back(nums1[i]) ;
            i++ ;
        }

        while(j < nums2.size()){
            arr.push_back(nums2[j]) ;
            j++ ;
        }

        int s = arr.size() ;

        if(s%2 == 0){
            double ans = double((arr[s/2] + arr[s/2 - 1])) / 2.0 ;
            return  ans  ;
        }else{
            cout << s << " " << s/2  << endl ;

            for(int i = 0 ; i < arr.size() ; i++){
                cout << arr[i] << " " ;
            }

            return arr[s/2] ;
        }

    }

int main(){

    vector<int> nums1 ;
    nums1.push_back(1) ;
    //nums1.push_back(3) ;

    vector<int> nums2 ;
    nums2.push_back(2) ;
    nums2.push_back(4) ;

    double ans = findMedianSortedArrays(nums1 ,nums2) ;
    cout << ans << endl ;

    return 0 ;
}



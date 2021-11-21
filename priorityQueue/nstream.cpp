#include <iostream>
#include <vector>
using namespace std;



void removeMin(int arr[] ,int heapSize){

    int temp = arr[0] ;
    arr[0] = arr[heapSize] ;
    arr[heapSize] = temp ;

    int parentIndex = 0 ;
    int leftIndex = (2 * parentIndex) + 1 ;
    int rightIndex = leftIndex + 1 ;

    while(leftIndex < heapSize){

        int smallIndex = leftIndex ;
        if(rightIndex < heapSize && arr[rightIndex] < arr[leftIndex]){
            smallIndex = rightIndex ;
        }

        if(arr[parentIndex] < arr[smallIndex]){
            break ;
        }

        int temp = arr[parentIndex] ;
        arr[parentIndex] = arr[smallIndex] ;
        arr[smallIndex] = temp ;

        parentIndex = smallIndex ;
        leftIndex = (2 * parentIndex) + 1 ;
        rightIndex = leftIndex + 1 ;

    }

}

void insert(int arr[] , int heapSize){

    int childIndex = heapSize ;

    while(childIndex > 0){

        int parentIndex = (childIndex - 1) /  2 ;

        if(arr[parentIndex] < arr[childIndex] ){
            break ;
        }

        int temp = arr[parentIndex] ;
        arr[parentIndex] = arr[childIndex] ;
        arr[childIndex] = temp ;

        childIndex = parentIndex ;

    }

}

void heapSort(int arr[], int n) {

    if(n <= 1){
        return ;
    }

    int heapSize = 1 ;

    while(heapSize < n){
        insert(arr , heapSize++) ;
    }

    while(heapSize > 0){
        heapSize-- ;
        removeMin(arr , heapSize) ;
    }

}

void findMedian(int *arr, int n) {

    for(int i = 1 ; i <= n ; i++){

        heapSort(arr , i) ;

        if(i % 2 == 0){

            int a = i / 2 ;
            int b = a - 1 ;

            int median =  ( arr[a] + arr[b] ) / 2 ;
            cout << median << " " ;
        }else{
            int a = i / 2 ;
            int median = arr[a] ;
            cout << median << " " ;
        }

    }

}


int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}

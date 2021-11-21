
#include <iostream>
using namespace std;

void Swap(int arr[],int size)
{
    int i = 0,j = 0;

    cout << i << "tt " << j << endl ;

    while (i+1 < size)
    {
       int temp1 = arr[i];
       int temp2 = arr[i+1];
       arr[j] = temp2;
       arr[j+1] = temp1;
       cout << temp1 << " " << arr[j] <<endl ;
       cout << temp2 << " " << arr[j + 1] <<endl ;
       i += 2;
       j += 2;
     }
     /*
     for (int i = 0; i < size; i++)
     {
        cout << arr[i] << " ";
     }
*/

    cout<< "fuck"<< size << endl ;
}

void swapAlternate(int *arr, int size)
{
    //Write your code here

    int i = 0 ;
    int temp ;
    while(i+1 < size){
        temp = arr[i] ;
        arr[i] = arr[i+1] ;
        arr[i+1] = temp ;
        i = i + 2 ;
    }
}

int main()
{

    int size;
    cout << "enter size of array" << endl;
    cin >> size ;

    int* arr = new int [size];
     cout << "enter elements of array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    Swap( arr,size);

    for (int i = 0; i < size; i++)
     {
        cout << arr[i] << " ";
     }

}

#include <iostream>
using namespace std;

void swap(int* arr,int size)
{
    int i,j = 0;

    while (i+1 < size)
    {
       int temp1 = arr[i];
       int temp2 = arr[i+1];
       arr[j] = temp2;
       arr[j+1] = temp1;
       i += 2;
       j += 2;
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

    swap(arr,size);

    for (int i = 0; i < size; i++)
     {
        cout << arr[i] << " ";
     }

}

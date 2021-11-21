#include <iostream>
using namespace std;
#include<algorithm>
int arrayRotateCheck(int *input, int size)
{
    //Write your code here
    int *arr=new int[size];
    for(int i=0;i<size;i++)
    {
        arr[i]=input[i];
    }
    sort(arr,arr+size);
    int index=0;
    for(int i=0;i<size;i++)
    {
        if(arr[0]==input[i])
            return i;
        // else index++;
    }
    return 0;
}
int main()
{
 /*
	int t;
	cin >> t;
	while (t--)
	{
*/
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	/*}
*/
	return 0;
}

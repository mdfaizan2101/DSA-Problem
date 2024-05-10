#include<iostream>
using namespace std;

int BinarySearch(int arr[],int size,int key)
{
    int start = 0;
    int end = size-1;

    int mid = 0;

    while ( start <= end )
    {
        mid = start + (end - start)/2;

        if(arr[mid] == key) 
        {
            return mid;
        }
        if (arr[mid] < key) 
        {
            start = mid + 1;
        }
        else 
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int odd[5] = {11,22,33,44,55};
    int even[6] = {12,23,34,45,67,78};

    // int key;
    // cout << "Enter the key to be searched" << endl;
    // cin >> key;

    int indexodd = BinarySearch(odd,5,44);

    cout << "Index of key in odd array is " << indexodd << endl;

    int indexeven = BinarySearch(even,6,67);

    cout << "Index of key in even array is " << indexeven << endl;

    return 0;
}
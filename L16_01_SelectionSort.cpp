#include<iostream>
using namespace std;

int selectionSort(int arr[],int n)
{
    for (int  i = 0; i < n-1; i++)
    {
        int minValue = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[minValue] > arr[j]) 
            minValue = j;
        }
            swap(arr[minValue],arr[i]);
    }
}

int main()
{
    int arr[] = {23,13,221,64,46,98,19,43,94};

    selectionSort(arr,9);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " " ;
    }
        
}
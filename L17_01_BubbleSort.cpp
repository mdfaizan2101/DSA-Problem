#include<iostream>
using namespace std;

int bubbleSort(int arr[],int n)
{
    bool swapped = false;
    for (int  i = 1; i < n; i++) // Form Round-1 to Round-(n-1)
    {

        for (int j = 0; j < n-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
            swap(arr[j],arr[j+1]);
            swapped = true;   
            }
        }
            if(swapped == false)
            break;
    }
}

int main()
{
    int arr[] = {1,7,10,4,9,2,0,1,3};

    bubbleSort(arr,9);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " " ;
    }
        
}
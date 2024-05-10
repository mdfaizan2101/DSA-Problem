#include<iostream>
using namespace std;

int partitionArray(int arr[], int s, int e)
{
    int pivotElement = arr[s];
    int count  = 0;
    for (int i = s+1; i <= e; i++)
    {
        if(pivotElement >= arr[i])
        count++;
    }

    // place pivot at right position
    int pivotIndex = s + count;
    swap(arr[s],arr[pivotIndex]);

    // left aur right ka part sambhal lete hai
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivotElement)
        {
            i++;
        }

        while (arr[j] > pivotElement)
        {
            j--;
        }
        
        if (i <  pivotIndex && j > pivotIndex)
        {
            swap(arr[i++],arr[j--]);
        }
        
    }
    
    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    // base case
    if(s >= e)
    return ;

    // partition karo
    int p = partitionArray(arr, s, e);

    // recursive call

    // left part sort karo
    quickSort(arr, s, p-1);

    // right part sort karo
    quickSort(arr, p+1, e);

}

int main()
{
    int arr[17] = {2,4,1,6,3,12,43,10,76,89,22,55,34,48,15,93,9};
    int n = 17;

    quickSort(arr,0,n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
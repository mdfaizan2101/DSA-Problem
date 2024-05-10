#include<iostream>
using namespace std;

int FirstOccurence(int arr[],int n,int key)
{
    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid = s + (e - s)/2;

    while ( s <= e )
    {        
        if( arr[mid] == key ) {
            ans = mid;
            e = mid - 1;
        }

        else if ( arr[mid] < key ) {
            s = mid + 1;
        }

        else if( arr[mid] > key) {
            e = mid - 1;
        }

        mid = s + (e - s)/2;

    }
    return ans;
}

int LastOccurence(int arr[],int n,int key)
{
    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid = s + (e - s)/2;

    while ( s <= e )
    {        
        if( arr[mid] == key ) {
            ans = mid;
            s = mid + 1;
        }

        else if ( arr[mid] < key ) {
            s = mid + 1;
        }

        else if( arr[mid] > key) {
            e = mid - 1;
        }

        mid = s + (e - s)/2;

    }
    return ans;
}

int main()
{
    int arr[5] = {2,3,3,3,6};

    int indexFirst = FirstOccurence(arr,5,3);

    cout << "First Occurence of 3 is at index no : " << indexFirst << endl;

    int indexLast = LastOccurence(arr,5,3);

    cout << "Last Occurence of 3 is at index no : " << indexLast << endl;

    cout << "No of times it occurs : " << indexFirst+indexLast-1 << endl;

    return 0;
}
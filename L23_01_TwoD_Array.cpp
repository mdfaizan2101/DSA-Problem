#include<iostream>
using namespace std;

bool present(int arr[][4],int target,int row,int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(arr[row][col] == target)
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[3][4] = {{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};
    
    // for (int row = 0; row < 3; row++)
    // {
    //     for (int col = 0; col < 3; col++)
    //     {
    //         cin >> arr[row][col];
    //     }   
    // }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout <<  arr[row][col] << " ";
        }
        cout << endl;
    }

    int target;
    cout << "Enter a element" << endl;
    cin >> target;

    if(present(arr,target,3,4)==1)
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }

    return 0;
}
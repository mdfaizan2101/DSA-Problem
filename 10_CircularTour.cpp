#include<iostream>
#include<queue>
using namespace std;

int CircularTour(int petrol[],int distance[],int n)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance = balance + petrol[i] - distance[i];
        if (balance < 0)
        {
            deficit = deficit + balance;
            start = i + 1;
            balance = 0;
        }
    }
    
    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int petrol[4] = {4,6,7,4};
    int distance[4] = {6,5,3,3};

    int ans = CircularTour(petrol, distance, 4);

    cout << "Answer: " << ans << endl;

    return 0;
}
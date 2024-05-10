#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int>&s,int num)
{
    //base case
    if ( s.empty() || (!s.empty() && s.top() < num ))
    {
        s.push(num);
        return;
    }

    int num2 = s.top();
    s.pop();

    //Recursive call
    sortedInsert(s,num);

    s.push(num2);
}

stack<int> sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return s;
    }

    int num = s.top();
    s.pop();

    //recursive call
    sortStack(s);

    sortedInsert(s,num);

    return s;
}

int main()
{
    stack<int> s;

    s.push(3);
    s.push(-7);
    s.push(10);
    s.push(-1);
    s.push(2);

    sortStack(s);

    cout << s.top() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    
    return 0;
}
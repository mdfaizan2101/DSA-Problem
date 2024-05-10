#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> rev(queue<int> q)
{
    stack<int> s;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}

int main()
{
    queue<int> q;

    q.push(6);
    q.push(5);
    q.push(11);
    q.push(4);
    q.push(13);
    q.push(9);

    queue<int> ans = rev(q);

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    
    return 0;
}
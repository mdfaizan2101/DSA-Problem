#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> kElementReverse(queue<int> q, int k)
{
    stack<int> s;

    for(int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    int t = q.size() - k;
    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
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

    queue<int> ans = kElementReverse(q, 4);

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    
    return 0;
}
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;
    Node* random;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        this -> random = NULL;
    }
};

void insertAtTail(Node* &head,Node* &tail,int d) 
{
    //new node create
    Node* newNode = new Node(d);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
    tail -> next = newNode;
    tail = newNode;
    }
}

Node* merge(Node* &left,Node* &right)
{
    if(left == NULL)
    return right;

    if (right == NULL)
    return left;

    //first element is dummy 
    Node* ans = new Node(-1);
    Node* temp = ans;

    //merge both left and right part
    while (left != NULL && right != NULL)
    {
        if (left -> data < right -> data)
        {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }  
    }
    
    while (left != NULL)
    {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while (right != NULL)
    {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    ans = ans -> next;
    return ans;
}

Node* findMid(Node* &head)
{
    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node*mergeSort(Node* &head)
{
    //base case
    if(head == NULL || head -> next == NULL)
    {
    return head;
    }

    //break the linked list into 2 halves
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    //recursive call
    left = mergeSort(left);
    right = mergeSort(right);

    Node* result = merge(left,right);

    return result;
}

void print(Node* &head) {

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    Node* node1 = new Node(9);
    Node* head1 = node1;
    Node* tail1 = node1;

    insertAtTail(head1,tail1,200);
    insertAtTail(head1,tail1,3);
    insertAtTail(head1,tail1,42);
    insertAtTail(head1,tail1,5);
    insertAtTail(head1,tail1,98);
    insertAtTail(head1,tail1,0);
    insertAtTail(head1,tail1,33);
    insertAtTail(head1,tail1,1);

    cout << endl << "List1: "; 
    print(head1);

    Node* result = mergeSort(head1);
    cout << endl << "MergeSorted List: ";
    print(result);
    cout << endl;
    
    return 0;
}
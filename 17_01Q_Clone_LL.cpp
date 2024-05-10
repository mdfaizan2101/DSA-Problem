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

void print(Node* head)
{
    cout << head -> data << "(" << head -> random -> data << ")";
    head = head -> next;
    while (head != NULL) 
    {
        cout << " -> " << head -> data << "(" << head -> random -> data << ")";
        head = head -> next;
    }
    cout << endl;
}


// APPROACH-1

Node* cloneLinkedList(Node* &head)
{
    //create a clone list 
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while (temp != NULL)
    {
       insertAtTail(cloneHead,cloneTail,temp->data);
       temp = temp -> next; 
    }
  
    //create a map
    map<Node*,Node*> oldToNewNode;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    // while (originalNode != NULL)
    // {
    //     oldToNewNode[originalNode] = cloneNode;
    //     originalNode = originalNode -> next;
    //     cloneNode = cloneNode -> next;
    // }

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        cloneNode -> random = oldToNewNode[originalNode -> random];
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }
    return cloneHead;
}


// APPROACH-2
/*
Node* copyList(Node* &head)
{
    //step1: create a clone list 
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while (temp != NULL)
    {
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp -> next; 
    }

    //step2: cloneNodes add in Between original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next;

        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = next;
    }
    
    //step3: random pointer copy
    temp = head;

    while (temp != NULL)
    {
        if (temp -> next != NULL)
        {
            temp -> next -> random = temp -> random 
            ? temp -> random -> next : temp -> random;
            
        }
        temp = temp -> next -> next;
    }

    //step4: revert changes done in step2
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;

        if(originalNode != NULL)
        {
        cloneNode -> next = originalNode -> next;
        cloneNode = cloneNode -> next;
        }
    }
    
    //step5: return answer   
    return cloneHead;
}
*/

int main()
{
    // Creating a linked list with random pointer
    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next = new Node(5);

    head -> random = head -> next -> next;
    head -> next -> random = head;
    head -> next -> next -> random = head -> next -> next -> next -> next;
    head -> next -> next -> next -> random = head -> next -> next;
    head -> next -> next -> next -> next -> random = head -> next;
   
    // Print the original list
    cout << "The original linked list:\n";
    print(head);
   
    // Function call
    Node* sol = cloneLinkedList(head);
   
    cout << "The cloned linked list:\n";
    print(sol);
   
    return 0;
}
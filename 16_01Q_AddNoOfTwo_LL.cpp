#include<iostream>
#include<vector>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(Node* &head,Node* &tail,int val) 
{
    Node* temp = new Node(val);

    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail -> next = temp;
        tail = temp;
    }
    
}

Node* reverse(Node* &head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// APPROACH-1
/*
Node* add(Node* &list1,Node* &list2)
{
    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        int sum = carry + list1 -> data + list2 -> data;

        int digit = sum % 10;

        //create node and in answer
        insertAtTail(ansHead,ansTail,digit);

        carry = sum / 10; 
        list1 = list1 -> next;
        list2 = list2 -> next;
    }

    while (list1 != NULL)
    {
        int sum = carry + list1 -> data;

        int digit = sum % 10;

        //create node and in answer
        insertAtTail(ansHead,ansTail,digit);

        carry = sum / 10; 
        list1 = list1 -> next;
    }

    while (list2 != NULL)
    {
        int sum = carry + list2 -> data;

        int digit = sum % 10;

        //create node and in answer
        insertAtTail(ansHead,ansTail,digit);

        carry = sum / 10;
        list2 = list2 -> next; 
    }
    
    while (carry != 0)
    {
        int sum = carry;

        int digit = sum % 10;

        //create node and in answer
        insertAtTail(ansHead,ansTail,digit);

        carry = sum / 10; 
    }
    return ansHead;
}

Node* addList(Node* &list1,Node* &list2)
{
    //reverse the lists
    list1 = reverse(list1);
    list2 = reverse(list2);

    //addition of reversed list1 and list2
    Node* ans = add(list1,list2);

    //reverse the reversed answer list
    ans = reverse(ans);

    return ans;
}
*/

// APPROACH-2
Node* add(Node* list1, Node* list2) {
    int carry = 0;
    
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    
    while(list1 != NULL || list2 != NULL || carry != 0) {
        
        int val1 = 0;
        if(list1 != NULL)
            val1 = list1 -> data;
            
        int val2 = 0;
        if(list2 !=NULL)
            val2 = list2 -> data;
        
        
        int sum = carry + val1 + val2;
        
        int digit = sum%10;
        
        //create node and add in answer Linked List
        insertAtTail(ansHead, ansTail, digit);
        
        carry = sum/10;
        
        if(list1 != NULL)
            list1 = list1 -> next;
        
        if(list2 != NULL)
            list2 = list2 -> next;
    }
    return ansHead;
    }

Node* addList(Node* &list1,Node* &list2)
{
    //reverse the lists
    list1 = reverse(list1);
    list2 = reverse(list2);

    //addition of reversed list1 and list2
    Node* ans = add(list1,list2);

    //reverse the reversed answer list
    ans = reverse(ans);

    return ans;
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
    Node* list1 = new Node(1);
    Node* head1 = list1;
    Node* tail1 = list1;

    insertAtTail(head1,tail1,3);
    insertAtTail(head1,tail1,4);
    insertAtTail(head1,tail1,6);

    cout << "Head1 " << head1 -> data << endl;
    cout << "Tail1 " << tail1 -> data << endl;
    print(head1);

    Node* list2 = new Node(2);
    Node* head2 = list2;
    Node* tail2 = list2;

    insertAtTail(head2,tail2,3);
    insertAtTail(head2,tail2,5);
    print(head2);

    Node* ans = addList(list1,list2);

    cout << "Added Linked List: " << endl;
    print(ans);

    return 0;
}
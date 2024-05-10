// #include<iostream>
// using namespace std;

// class Node {

//     public:
//     int data;
//     Node* next;
//     Node* bottom;

//     Node(int data) {
//         this -> data = data;
//         this -> next = NULL;
//         this -> bottom = NULL;
//     }
// };

// void insertAtTail(Node* &head,Node* &tail,int d) 
// {
//     //new node create
//     Node* newNode = new Node(d);
//     if(head == NULL)
//     {
//         head = newNode;
//         tail = newNode;
//         return;
//     }
//     else
//     {
//     tail -> next = newNode;
//     tail = newNode;
//     }
// }

// void insertAtbottom(Node* &tail,int d) {

//     //new node create in branch
//     Node* temp = new Node(d);
//     tail -> bottom = temp;
//     tail = temp;
// }

// Node* merge(Node* &down,Node* &right)
// {
//     if(down == NULL)
//     return right;

//     if (right == NULL)
//     return down;

//     //first element is dummy 
//     Node* ans = new Node(-1);
//     ans = down;
//     Node* temp = ans;

//     /*
//     //If bottom and next both are sorted
//     while (temp -> bottom != NULL)
//     {
//         temp = temp -> bottom;
//     }
    
//     temp -> next = right;
//     return ans;
//     */

//     //merge both left and right part
//     while (down != NULL && right != NULL)
//     {
//         if (down -> data < right -> data)
//         {
//             temp -> next = down;
//             temp = down;
//             down = down -> bottom;
//         }
//         else
//         {
//             temp -> next = right;
//             temp = right;
//             right = right -> next;
//         }  
//     }
    
//     while (down != NULL)
//     {
//         temp -> next = down;
//         temp = down;
//         down = down -> bottom;
//     }

//     while (right != NULL)
//     {
//         temp -> next = right;
//         temp = right;
//         right = right -> next;
//     }
//     return ans;
// }

// Node*flatten(Node* &head)
// {
//     Node* down = head;
//     down -> next = NULL;

//     //base case
//     if(down == NULL)
//     {
//     return down;
//     }
//     Node* right = flatten(head -> next);

//     Node* ans = merge(down,right);

//     ans = ans -> next;
//     return ans;
// }

// void print(Node* &head) {

//     Node* temp = head;

//     while (temp != NULL)
//     {
//         cout << temp -> data << " ";
//         temp = temp -> next;
//     }
//     cout << endl;
// }

// int main()
// {
//     Node* head = NULL;

// 	/* Let us create the following linked list
// 		5 -> 10 -> 19 -> 28
// 		|    |	   |	 |
// 		V    V	   V	 V
// 		7    20    22    35
// 		|		   |	 |
// 		V		   V	 V
// 		8		   50    40
// 		|			     |
// 		V			     V
// 		30			     45
// 	*/
//     Node* node1 = new Node(5);
//     Node* head1 = node1;
//     Node* tail1 = node1;

//     insertAtbottom(tail1, 7);
//     insertAtbottom(tail1, 8);
//     insertAtbottom(tail1, 30);

//     insertAtTail(head1,tail1,10);
//     insertAtbottom(tail1, 20);

//     insertAtTail(head1,tail1,19);
//     insertAtbottom(tail1, 22);
//     insertAtbottom(tail1, 50);

//     insertAtTail(head1,tail1,28);
// 	insertAtbottom(tail1, 35);
//     insertAtbottom(tail1, 40);
//     insertAtbottom(tail1, 45);

// 	// Function call
// 	head = flatten(head);

// 	cout << "Flatten Linked List: " << endl;
// 	print(head);

// 	return 0;
// }





#include <iostream>
using namespace std;

class Node 
{
    public:
	int data;
	Node *next;
    Node *bottom;
};

Node* merge(Node* a, Node* b)
{

	if (a == NULL)
		return b;

	if (b == NULL)
		return a;

	Node* result;

	if (a -> data < b -> data) 
    {
		result = a;
		result -> bottom = merge(a -> bottom, b);
	}
	else 
    {
		result = b;
		result -> bottom = merge(a, b -> bottom);
	}

	result -> next = NULL;
	return result;
}

Node* flatten(Node* root)
{

	// Base Cases
	if (root == NULL || root -> next == NULL)
		return root;

	// Recur for next list
	root -> next = flatten(root -> next);

	// Now merge
	root = merge(root, root -> next);

	// Return the root
	// it will be in turn merged with its left
	return root;
}

// Utility function to insert a node at
// beginning of the linked list
Node* push(Node* head, int data)
{

	// Allocate the Node & Put in the data
	Node* new_node = new Node();

	new_node -> data = data;
	new_node -> next = NULL;

	// Make next of new Node as head
	new_node -> bottom = head;

	// Move the head to point to new Node
	head = new_node;

	return head;
}

void printList(Node* head)
{
	Node* temp = head;

	while (temp != NULL) 
    {
		cout << temp -> data << " ";
		temp = temp -> bottom;
	}
	cout << endl;
}

// Driver's code
int main()
{
	Node* head = NULL;

	/* Let us create the following linked list
		5 -> 10 -> 19 -> 28
		|    |	   |	 |
		V    V	   V	 V
		7    20    22    35
		|		   |	 |
		V		   V	 V
		8		   50    40
		|			     |
		V			     V
		30			     45
	*/
	head = push(head, 30);
	head = push(head, 8);
	head = push(head, 7);
	head = push(head, 5);

	head->next = push(head->next, 20);
	head->next = push(head->next, 10);

	head->next->next = push(head->next->next, 50);
	head->next->next = push(head->next->next, 22);
	head->next->next = push(head->next->next, 19);

	head->next->next->next
		= push(head->next->next->next, 45);
	head->next->next->next
		= push(head->next->next->next, 40);
	head->next->next->next
		= push(head->next->next->next, 35);
	head->next->next->next
		= push(head->next->next->next, 28);

	// Function call
	head = flatten(head);

	cout << "Flatten Linked List: " << endl;
	printList(head);
	return 0;
}

// This code is contributed by rajsanghavi9.

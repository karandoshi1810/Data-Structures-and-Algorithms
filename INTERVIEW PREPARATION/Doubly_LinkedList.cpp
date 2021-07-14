/*
A Doubly Linked List (DLL) contains an extra pointer, typically called previous pointer, together with next pointer and data which 
are there in singly linked list.
*/
#include<bits/stdc++.h>
using namespace std;
//class to create and initialize a node
class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

//function to insert at head
void insertAtHead(node* &head,int val)
{
    node* n = new node(val); //create new node
    if(head==NULL) //if null then it new node will be head
    {
        head=n;
        return;
    }
    n->next=head; //next of new node will point to current head
    head->prev=n; //prev of current head will point to new node
    head = n; //new node will be head now
}

//function to insert node at tail
void insert(node* &head,int val)
{
    node* n = new node(val); //create new node
    if(head==NULL) //if null then it new node will sevrve as head
    {
        head=n;
        return;
    }
    node* temp = head; //temporary variable to traverse LL
    while(temp->next!=NULL) //traverse till end of LL
    {
        temp=temp->next;
    }
    temp->next=n; //next of last node will point to new node
    n->prev=temp; //prev of new node will point to current last node
    n->next=NULL; //next of new node will point to null and will serve as new last node
}

//function to insert node at middle
void insertAtMiddle(node* head, int pos, int val)
{
    if(head==NULL) //if null then it new node will sevrve as head
    {
        insertAtHead(head,val); //this function will add a node at head/first of LL
        return;
    }
    node* n =new node(val);// create a new node
    node* temp = head; //temporary variable to traverse LL
    int count=1; //counter to match the position at which new node is meant to be added
    while(temp->next!=NULL && count!=pos) //traverse till pos
    {
        temp=temp->next;
        count++;
    }
    temp->next->prev=n; //prev of next node will point to new node n
    n->next=temp->next; //next of new node will point to next of temp node
    n->prev=temp; //prev of new node will point to temp node
    temp->next = n; //next of temp node will point to new node


}

//function to display LL
void display(node* &head)
{
    node* temp=head; //temporary variable to traverse LL
    while(temp!=NULL) //traverse till the node is not NULL
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insertAtHead(head,5);

    display(head);
    return 0;
}